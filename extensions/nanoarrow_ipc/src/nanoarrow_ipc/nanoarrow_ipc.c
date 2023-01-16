// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "nanoarrow/nanoarrow.h"

#include "File_reader.h"
#include "Message_reader.h"
#include "Message_verifier.h"
#include "Schema_reader.h"

#include "nanoarrow_ipc.h"

ArrowIpcErrorCode ArrowIpcErrorSet(struct ArrowIpcError* error, const char* fmt, ...) {
  if (error == NULL) {
    return NANOARROW_OK;
  }

  memset(error->message, 0, sizeof(error->message));

  va_list args;
  va_start(args, fmt);
  int chars_needed = vsnprintf(error->message, sizeof(error->message), fmt, args);
  va_end(args);

  if (chars_needed < 0) {
    return EINVAL;
  } else if (((size_t)chars_needed) >= sizeof(error->message)) {
    return ERANGE;
  } else {
    return NANOARROW_OK;
  }
}

void ArrowIpcReaderInit(struct ArrowIpcReader* reader) {
  memset(reader, 0, sizeof(struct ArrowIpcReader));
}

void ArrowIpcReaderReset(struct ArrowIpcReader* reader) {
  if (reader->schema.release != NULL) {
    reader->schema.release(&reader->schema);
  }

  ArrowIpcReaderInit(reader);
}

static inline uint32_t ArrowIpcReadUint32LE(struct ArrowIpcBufferView* data) {
  uint32_t value;
  memcpy(&value, data->data, sizeof(uint32_t));
  // TODO: bswap32() if big endian
  data->data += sizeof(uint32_t);
  data->size_bytes -= sizeof(uint32_t);
  return value;
}

static inline int32_t ArrowIpcReadInt32LE(struct ArrowIpcBufferView* data) {
  int32_t value;
  memcpy(&value, data->data, sizeof(int32_t));
  // TODO: bswap32() if big endian
  data->data += sizeof(int32_t);
  data->size_bytes -= sizeof(int32_t);
  return value;
}

#define ns(x) FLATBUFFERS_WRAP_NAMESPACE(org_apache_arrow_flatbuf, x)

static int ArrowIpcReaderSetTypeSimple(struct ArrowSchema* schema, int nanoarrow_type,
                                       struct ArrowIpcError* error) {
  int result = ArrowSchemaSetType(schema, nanoarrow_type);
  if (result != NANOARROW_OK) {
    ArrowIpcErrorSet(error, "ArrowSchemaSetType() failed for type %s",
                     ArrowTypeString(nanoarrow_type));
    return result;
  }

  return NANOARROW_OK;
}

static int ArrowIpcReaderSetTypeInt(struct ArrowSchema* schema,
                                    flatbuffers_generic_t type_generic,
                                    struct ArrowIpcError* error) {
  ns(Int_table_t) type = (ns(Int_table_t))type_generic;

  int is_signed = ns(Int_is_signed_get(type));
  int bitwidth = ns(Int_bitWidth_get(type));
  int nanoarrow_type = NANOARROW_TYPE_UNINITIALIZED;

  if (is_signed) {
    switch (bitwidth) {
      case 8:
        nanoarrow_type = NANOARROW_TYPE_INT8;
        break;
      case 16:
        nanoarrow_type = NANOARROW_TYPE_INT16;
        break;
      case 32:
        nanoarrow_type = NANOARROW_TYPE_INT32;
        break;
      case 64:
        nanoarrow_type = NANOARROW_TYPE_INT64;
        break;
      default:
        ArrowIpcErrorSet(error,
                         "Expected signed int bitwidth of 8, 16, 32, or 64 but got %d",
                         (int)bitwidth);
        return EINVAL;
    }
  } else {
    switch (bitwidth) {
      case 8:
        nanoarrow_type = NANOARROW_TYPE_UINT8;
        break;
      case 16:
        nanoarrow_type = NANOARROW_TYPE_UINT16;
        break;
      case 32:
        nanoarrow_type = NANOARROW_TYPE_UINT32;
        break;
      case 64:
        nanoarrow_type = NANOARROW_TYPE_UINT64;
        break;
      default:
        ArrowIpcErrorSet(error,
                         "Expected unsigned int bitwidth of 8, 16, 32, or 64 but got %d",
                         (int)bitwidth);
        return EINVAL;
    }
  }

  return ArrowIpcReaderSetTypeSimple(schema, nanoarrow_type, error);
}

static int ArrowIpcReaderSetField(struct ArrowSchema* schema, ns(Field_table_t) field,
                                  struct ArrowIpcError* error) {
  int result;
  if (ns(Field_name_is_present(field))) {
    result = ArrowSchemaSetName(schema, ns(Field_name_get(field)));
  } else {
    result = ArrowSchemaSetName(schema, "");
  }

  if (result != NANOARROW_OK) {
    ArrowIpcErrorSet(error, "ArrowSchemaSetName() failed");
    return result;
  }

  if (ns(Field_nullable_get(field))) {
    schema->flags |= ARROW_FLAG_NULLABLE;
  }

  int type_type = ns(Field_type_type(field));
  switch (type_type) {
    case ns(Type_Int):
      NANOARROW_RETURN_NOT_OK(
          ArrowIpcReaderSetTypeInt(schema, ns(Field_type_get(field)), error));
      break;
    default:
      ArrowIpcErrorSet(error, "Unrecognized Field type with value %d", (int)type_type);
      return EINVAL;
  }

  return NANOARROW_OK;
}

static int ArrowIpcReaderSetChildren(struct ArrowSchema* schema, ns(Field_vec_t) fields,
                                     struct ArrowIpcError* error) {
  int64_t n_fields = ns(Schema_vec_len(fields));

  for (int64_t i = 0; i < n_fields; i++) {
    ns(Field_table_t) field = ns(Field_vec_at(fields, i));
    NANOARROW_RETURN_NOT_OK(ArrowIpcReaderSetField(schema->children[i], field, error));
  }

  return NANOARROW_OK;
}

static int ArrowIpcReaderDecodeSchema(struct ArrowIpcReader* reader,
                                      flatbuffers_generic_t message_header,
                                      struct ArrowIpcError* error) {
  ns(Schema_table_t) schema = (ns(Schema_table_t))message_header;
  int endianness = ns(Schema_endianness(schema));
  switch (endianness) {
    case ns(Endianness_Little):
      reader->endianness = NANOARROW_IPC_ENDIANNESS_LITTLE;
      break;
    case ns(Endianness_Big):
      reader->endianness = NANOARROW_IPC_ENDIANNESS_BIG;
      break;
    default:
      ArrowIpcErrorSet(error,
                       "Expected Schema endianness of 0 (little) or 1 (big) but got %d",
                       (int)endianness);
      return EINVAL;
  }

  ns(Feature_vec_t) features = ns(Schema_features(schema));
  int64_t n_features = ns(Feature_vec_len(features));
  reader->features = 0;

  for (int64_t i = 0; i < n_features; i++) {
    int feature = ns(Feature_vec_at(features, i));
    switch (feature) {
      case ns(Feature_COMPRESSED_BODY):
        reader->features |= NANOARROW_IPC_FEATURE_COMPRESSED_BODY;
        break;
      case ns(Feature_DICTIONARY_REPLACEMENT):
        reader->features |= NANOARROW_IPC_FEATURE_DICTIONARY_REPLACEMENT;
        break;
      default:
        ArrowIpcErrorSet(error, "Unrecognized Schema feature with value %d",
                         (int)feature);
        return EINVAL;
    }
  }

  ns(Field_vec_t) fields = ns(Schema_fields(schema));
  int64_t n_fields = ns(Schema_vec_len(fields));
  if (reader->schema.release != NULL) {
    reader->schema.release(&reader->schema);
  }

  ArrowSchemaInit(&reader->schema);
  int result = ArrowSchemaSetTypeStruct(&reader->schema, n_fields);
  if (result != NANOARROW_OK) {
    ArrowIpcErrorSet(error, "Failed to allocate struct schema with %ld children",
                     (long)n_fields);
    return result;
  }

  return ArrowIpcReaderSetChildren(&reader->schema, fields, error);
}

static inline int ArrowIpcReaderCheckHeader(struct ArrowIpcReader* reader,
                                            struct ArrowIpcBufferView* data_mut,
                                            int32_t* message_size_bytes,
                                            struct ArrowIpcError* error) {
  if (data_mut->size_bytes < 8) {
    ArrowIpcErrorSet(error, "Expected data of at least 8 bytes but only %ld bytes remain",
                     (long)data_mut->size_bytes);
    return EINVAL;
  }

  uint32_t continuation = ArrowIpcReadUint32LE(data_mut);
  if (continuation != 0xFFFFFFFF) {
    ArrowIpcErrorSet(error, "Expected 0xFFFFFFFF at start of message but found 0x%08X",
                     (unsigned int)continuation);
    return EINVAL;
  }

  *message_size_bytes = ArrowIpcReadInt32LE(data_mut);
  if ((*message_size_bytes) > data_mut->size_bytes || (*message_size_bytes) < 0) {
    ArrowIpcErrorSet(error,
                     "Expected 0 <= message body size <= %ld bytes but found message "
                     "body size of %ld bytes",
                     (long)data_mut->size_bytes, (long)(*message_size_bytes));
    return EINVAL;
  }

  return NANOARROW_OK;
}

static void ArrowIpcReaderAdvanceData(struct ArrowIpcBufferView* data,
                                      int32_t message_size_bytes) {
  message_size_bytes += (message_size_bytes + 8) % 8;
  data->data += message_size_bytes;
  data->size_bytes -= message_size_bytes;
}

ArrowIpcErrorCode ArrowIpcReaderPeek(struct ArrowIpcReader* reader,
                                     struct ArrowIpcBufferView* data,
                                     struct ArrowIpcError* error) {
  struct ArrowIpcBufferView data_mut = *data;
  int32_t message_size_bytes;
  NANOARROW_RETURN_NOT_OK(
      ArrowIpcReaderCheckHeader(reader, &data_mut, &message_size_bytes, error));

  ArrowIpcReaderAdvanceData(&data_mut, message_size_bytes);
  *data = data_mut;
  return NANOARROW_OK;
}

ArrowIpcErrorCode ArrowIpcReaderVerify(struct ArrowIpcReader* reader,
                                       struct ArrowIpcBufferView* data,
                                       struct ArrowIpcError* error) {
  struct ArrowIpcBufferView data_mut = *data;
  int32_t message_size_bytes;
  NANOARROW_RETURN_NOT_OK(
      ArrowIpcReaderCheckHeader(reader, &data_mut, &message_size_bytes, error));

  if (ns(Message_verify_as_root(data_mut.data, data_mut.size_bytes)) ==
      flatcc_verify_ok) {
    ArrowIpcReaderAdvanceData(&data_mut, message_size_bytes);
    *data = data_mut;
    return NANOARROW_OK;
  } else {
    ArrowIpcErrorSet(error, "Message flatbuffer verification failed");
    return EINVAL;
  }
}

ArrowIpcErrorCode ArrowIpcReaderDecode(struct ArrowIpcReader* reader,
                                       struct ArrowIpcBufferView* data,
                                       struct ArrowIpcError* error) {
  reader->message_type = NANOARROW_IPC_MESSAGE_TYPE_UNINITIALIZED;
  struct ArrowIpcBufferView data_mut = *data;

  int32_t message_size_bytes;
  NANOARROW_RETURN_NOT_OK(
      ArrowIpcReaderCheckHeader(reader, &data_mut, &message_size_bytes, error));

  ns(Message_table_t) message = ns(Message_as_root(data_mut.data));
  if (!message) {
    return EINVAL;
  }

  int version = ns(Message_version(message));
  switch (version) {
    case ns(MetadataVersion_V4):
    case ns(MetadataVersion_V5):
      break;
    case ns(MetadataVersion_V1):
    case ns(MetadataVersion_V2):
    case ns(MetadataVersion_V3):
      ArrowIpcErrorSet(error, "Expected metadata version V4 or V5 but found %s",
                       ns(MetadataVersion_name(version)));
      break;
    default:
      ArrowIpcErrorSet(error, "Unexpected value for Message metadata version (%d)", version);
      return EINVAL;
  }

  reader->message_type = ns(Message_header_type(message));
  flatbuffers_generic_t message_header = ns(Message_header_get(message));

  switch (reader->message_type) {
    case ns(MessageHeader_Schema):
      NANOARROW_RETURN_NOT_OK(ArrowIpcReaderDecodeSchema(reader, message_header, error));
      break;
    case ns(MessageHeader_DictionaryBatch):
    case ns(MessageHeader_RecordBatch):
    case ns(MessageHeader_Tensor):
    case ns(MessageHeader_SparseTensor):
      ArrowIpcErrorSet(error, "Unsupported message type: '%s'",
                       ns(MessageHeader_type_name(reader->message_type)));
      return ENOTSUP;
    default:
      ArrowIpcErrorSet(error, "Unnown message type: %d", (int)(reader->message_type));
      return EINVAL;
  }

  ArrowIpcReaderAdvanceData(&data_mut, message_size_bytes);
  *data = data_mut;
  return NANOARROW_OK;
}