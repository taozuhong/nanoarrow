#ifndef MESSAGE_READER_H
#define MESSAGE_READER_H

/* Generated by flatcc 0.6.1 FlatBuffers schema compiler for C by dvide.com */

#ifndef FLATBUFFERS_COMMON_READER_H
#include "flatbuffers_common_reader.h"
#endif
#ifndef TENSOR_READER_H
#include "Tensor_reader.h"
#endif
#ifndef SPARSETENSOR_READER_H
#include "SparseTensor_reader.h"
#endif
#ifndef SCHEMA_READER_H
#include "Schema_reader.h"
#endif
#include "flatcc/flatcc_flatbuffers.h"
#ifndef __alignas_is_defined
#include <stdalign.h>
#endif
#include "flatcc/flatcc_prologue.h"
#ifndef flatbuffers_identifier
#define flatbuffers_identifier 0
#endif
#ifndef flatbuffers_extension
#define flatbuffers_extension "bin"
#endif

typedef struct org_apache_arrow_flatbuf_FieldNode org_apache_arrow_flatbuf_FieldNode_t;
typedef const org_apache_arrow_flatbuf_FieldNode_t *org_apache_arrow_flatbuf_FieldNode_struct_t;
typedef org_apache_arrow_flatbuf_FieldNode_t *org_apache_arrow_flatbuf_FieldNode_mutable_struct_t;
typedef const org_apache_arrow_flatbuf_FieldNode_t *org_apache_arrow_flatbuf_FieldNode_vec_t;
typedef org_apache_arrow_flatbuf_FieldNode_t *org_apache_arrow_flatbuf_FieldNode_mutable_vec_t;

typedef const struct org_apache_arrow_flatbuf_BodyCompression_table *org_apache_arrow_flatbuf_BodyCompression_table_t;
typedef struct org_apache_arrow_flatbuf_BodyCompression_table *org_apache_arrow_flatbuf_BodyCompression_mutable_table_t;
typedef const flatbuffers_uoffset_t *org_apache_arrow_flatbuf_BodyCompression_vec_t;
typedef flatbuffers_uoffset_t *org_apache_arrow_flatbuf_BodyCompression_mutable_vec_t;
typedef const struct org_apache_arrow_flatbuf_RecordBatch_table *org_apache_arrow_flatbuf_RecordBatch_table_t;
typedef struct org_apache_arrow_flatbuf_RecordBatch_table *org_apache_arrow_flatbuf_RecordBatch_mutable_table_t;
typedef const flatbuffers_uoffset_t *org_apache_arrow_flatbuf_RecordBatch_vec_t;
typedef flatbuffers_uoffset_t *org_apache_arrow_flatbuf_RecordBatch_mutable_vec_t;
typedef const struct org_apache_arrow_flatbuf_DictionaryBatch_table *org_apache_arrow_flatbuf_DictionaryBatch_table_t;
typedef struct org_apache_arrow_flatbuf_DictionaryBatch_table *org_apache_arrow_flatbuf_DictionaryBatch_mutable_table_t;
typedef const flatbuffers_uoffset_t *org_apache_arrow_flatbuf_DictionaryBatch_vec_t;
typedef flatbuffers_uoffset_t *org_apache_arrow_flatbuf_DictionaryBatch_mutable_vec_t;
typedef const struct org_apache_arrow_flatbuf_Message_table *org_apache_arrow_flatbuf_Message_table_t;
typedef struct org_apache_arrow_flatbuf_Message_table *org_apache_arrow_flatbuf_Message_mutable_table_t;
typedef const flatbuffers_uoffset_t *org_apache_arrow_flatbuf_Message_vec_t;
typedef flatbuffers_uoffset_t *org_apache_arrow_flatbuf_Message_mutable_vec_t;
#ifndef org_apache_arrow_flatbuf_FieldNode_file_identifier
#define org_apache_arrow_flatbuf_FieldNode_file_identifier 0
#endif
/* deprecated, use org_apache_arrow_flatbuf_FieldNode_file_identifier */
#ifndef org_apache_arrow_flatbuf_FieldNode_identifier
#define org_apache_arrow_flatbuf_FieldNode_identifier 0
#endif
#define org_apache_arrow_flatbuf_FieldNode_type_hash ((flatbuffers_thash_t)0x931857b8)
#define org_apache_arrow_flatbuf_FieldNode_type_identifier "\xb8\x57\x18\x93"
#ifndef org_apache_arrow_flatbuf_FieldNode_file_extension
#define org_apache_arrow_flatbuf_FieldNode_file_extension "bin"
#endif
#ifndef org_apache_arrow_flatbuf_BodyCompression_file_identifier
#define org_apache_arrow_flatbuf_BodyCompression_file_identifier 0
#endif
/* deprecated, use org_apache_arrow_flatbuf_BodyCompression_file_identifier */
#ifndef org_apache_arrow_flatbuf_BodyCompression_identifier
#define org_apache_arrow_flatbuf_BodyCompression_identifier 0
#endif
#define org_apache_arrow_flatbuf_BodyCompression_type_hash ((flatbuffers_thash_t)0xbc821116)
#define org_apache_arrow_flatbuf_BodyCompression_type_identifier "\x16\x11\x82\xbc"
#ifndef org_apache_arrow_flatbuf_BodyCompression_file_extension
#define org_apache_arrow_flatbuf_BodyCompression_file_extension "bin"
#endif
#ifndef org_apache_arrow_flatbuf_RecordBatch_file_identifier
#define org_apache_arrow_flatbuf_RecordBatch_file_identifier 0
#endif
/* deprecated, use org_apache_arrow_flatbuf_RecordBatch_file_identifier */
#ifndef org_apache_arrow_flatbuf_RecordBatch_identifier
#define org_apache_arrow_flatbuf_RecordBatch_identifier 0
#endif
#define org_apache_arrow_flatbuf_RecordBatch_type_hash ((flatbuffers_thash_t)0x43c558b)
#define org_apache_arrow_flatbuf_RecordBatch_type_identifier "\x8b\x55\x3c\x04"
#ifndef org_apache_arrow_flatbuf_RecordBatch_file_extension
#define org_apache_arrow_flatbuf_RecordBatch_file_extension "bin"
#endif
#ifndef org_apache_arrow_flatbuf_DictionaryBatch_file_identifier
#define org_apache_arrow_flatbuf_DictionaryBatch_file_identifier 0
#endif
/* deprecated, use org_apache_arrow_flatbuf_DictionaryBatch_file_identifier */
#ifndef org_apache_arrow_flatbuf_DictionaryBatch_identifier
#define org_apache_arrow_flatbuf_DictionaryBatch_identifier 0
#endif
#define org_apache_arrow_flatbuf_DictionaryBatch_type_hash ((flatbuffers_thash_t)0x5c6da7bc)
#define org_apache_arrow_flatbuf_DictionaryBatch_type_identifier "\xbc\xa7\x6d\x5c"
#ifndef org_apache_arrow_flatbuf_DictionaryBatch_file_extension
#define org_apache_arrow_flatbuf_DictionaryBatch_file_extension "bin"
#endif
#ifndef org_apache_arrow_flatbuf_Message_file_identifier
#define org_apache_arrow_flatbuf_Message_file_identifier 0
#endif
/* deprecated, use org_apache_arrow_flatbuf_Message_file_identifier */
#ifndef org_apache_arrow_flatbuf_Message_identifier
#define org_apache_arrow_flatbuf_Message_identifier 0
#endif
#define org_apache_arrow_flatbuf_Message_type_hash ((flatbuffers_thash_t)0xc3efd227)
#define org_apache_arrow_flatbuf_Message_type_identifier "\x27\xd2\xef\xc3"
#ifndef org_apache_arrow_flatbuf_Message_file_extension
#define org_apache_arrow_flatbuf_Message_file_extension "bin"
#endif

typedef int8_t org_apache_arrow_flatbuf_CompressionType_enum_t;
__flatbuffers_define_integer_type(org_apache_arrow_flatbuf_CompressionType, org_apache_arrow_flatbuf_CompressionType_enum_t, 8)
#define org_apache_arrow_flatbuf_CompressionType_LZ4_FRAME ((org_apache_arrow_flatbuf_CompressionType_enum_t)INT8_C(0))
#define org_apache_arrow_flatbuf_CompressionType_ZSTD ((org_apache_arrow_flatbuf_CompressionType_enum_t)INT8_C(1))

static inline const char *org_apache_arrow_flatbuf_CompressionType_name(org_apache_arrow_flatbuf_CompressionType_enum_t value)
{
    switch (value) {
    case org_apache_arrow_flatbuf_CompressionType_LZ4_FRAME: return "LZ4_FRAME";
    case org_apache_arrow_flatbuf_CompressionType_ZSTD: return "ZSTD";
    default: return "";
    }
}

static inline int org_apache_arrow_flatbuf_CompressionType_is_known_value(org_apache_arrow_flatbuf_CompressionType_enum_t value)
{
    switch (value) {
    case org_apache_arrow_flatbuf_CompressionType_LZ4_FRAME: return 1;
    case org_apache_arrow_flatbuf_CompressionType_ZSTD: return 1;
    default: return 0;
    }
}

/**  Provided for forward compatibility in case we need to support different
 *  strategies for compressing the IPC message body (like whole-body
 *  compression rather than buffer-level) in the future */
typedef int8_t org_apache_arrow_flatbuf_BodyCompressionMethod_enum_t;
__flatbuffers_define_integer_type(org_apache_arrow_flatbuf_BodyCompressionMethod, org_apache_arrow_flatbuf_BodyCompressionMethod_enum_t, 8)
/**  Each constituent buffer is first compressed with the indicated
 *  compressor, and then written with the uncompressed length in the first 8
 *  bytes as a 64-bit little-endian signed integer followed by the compressed
 *  buffer bytes (and then padding as required by the protocol). The
 *  uncompressed length may be set to -1 to indicate that the data that
 *  follows is not compressed, which can be useful for cases where
 *  compression does not yield appreciable savings. */
#define org_apache_arrow_flatbuf_BodyCompressionMethod_BUFFER ((org_apache_arrow_flatbuf_BodyCompressionMethod_enum_t)INT8_C(0))

static inline const char *org_apache_arrow_flatbuf_BodyCompressionMethod_name(org_apache_arrow_flatbuf_BodyCompressionMethod_enum_t value)
{
    switch (value) {
    case org_apache_arrow_flatbuf_BodyCompressionMethod_BUFFER: return "BUFFER";
    default: return "";
    }
}

static inline int org_apache_arrow_flatbuf_BodyCompressionMethod_is_known_value(org_apache_arrow_flatbuf_BodyCompressionMethod_enum_t value)
{
    switch (value) {
    case org_apache_arrow_flatbuf_BodyCompressionMethod_BUFFER: return 1;
    default: return 0;
    }
}


/**  ----------------------------------------------------------------------
 *  Data structures for describing a table row batch (a collection of
 *  equal-length Arrow arrays)
 *  Metadata about a field at some level of a nested type tree (but not
 *  its children).
 * 
 *  For example, a List<Int16> with values `[[1, 2, 3], null, [4], [5, 6], null]`
 *  would have {length: 5, null_count: 2} for its List node, and {length: 6,
 *  null_count: 0} for its Int16 node, as separate FieldNode structs */
struct org_apache_arrow_flatbuf_FieldNode {
    /**  The number of value slots in the Arrow array at this level of a nested
     *  tree */
    alignas(8) int64_t length;
    /**  The number of observed nulls. Fields with null_count == 0 may choose not
     *  to write their physical validity bitmap out as a materialized buffer,
     *  instead setting the length of the bitmap buffer to 0. */
    alignas(8) int64_t null_count;
};
static_assert(sizeof(org_apache_arrow_flatbuf_FieldNode_t) == 16, "struct size mismatch");

static inline const org_apache_arrow_flatbuf_FieldNode_t *org_apache_arrow_flatbuf_FieldNode__const_ptr_add(const org_apache_arrow_flatbuf_FieldNode_t *p, size_t i) { return p + i; }
static inline org_apache_arrow_flatbuf_FieldNode_t *org_apache_arrow_flatbuf_FieldNode__ptr_add(org_apache_arrow_flatbuf_FieldNode_t *p, size_t i) { return p + i; }
static inline org_apache_arrow_flatbuf_FieldNode_struct_t org_apache_arrow_flatbuf_FieldNode_vec_at(org_apache_arrow_flatbuf_FieldNode_vec_t vec, size_t i)
__flatbuffers_struct_vec_at(vec, i)
static inline size_t org_apache_arrow_flatbuf_FieldNode__size(void) { return 16; }
static inline size_t org_apache_arrow_flatbuf_FieldNode_vec_len(org_apache_arrow_flatbuf_FieldNode_vec_t vec)
__flatbuffers_vec_len(vec)
__flatbuffers_struct_as_root(org_apache_arrow_flatbuf_FieldNode)

__flatbuffers_define_struct_scalar_field(org_apache_arrow_flatbuf_FieldNode, length, flatbuffers_int64, int64_t)
__flatbuffers_define_struct_scalar_field(org_apache_arrow_flatbuf_FieldNode, null_count, flatbuffers_int64, int64_t)


/**  Optional compression for the memory buffers constituting IPC message
 *  bodies. Intended for use with RecordBatch but could be used for other
 *  message types */
struct org_apache_arrow_flatbuf_BodyCompression_table { uint8_t unused__; };

static inline size_t org_apache_arrow_flatbuf_BodyCompression_vec_len(org_apache_arrow_flatbuf_BodyCompression_vec_t vec)
__flatbuffers_vec_len(vec)
static inline org_apache_arrow_flatbuf_BodyCompression_table_t org_apache_arrow_flatbuf_BodyCompression_vec_at(org_apache_arrow_flatbuf_BodyCompression_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(org_apache_arrow_flatbuf_BodyCompression_table_t, vec, i, 0)
__flatbuffers_table_as_root(org_apache_arrow_flatbuf_BodyCompression)

/**  Compressor library.
 *  For LZ4_FRAME, each compressed buffer must consist of a single frame. */
__flatbuffers_define_scalar_field(0, org_apache_arrow_flatbuf_BodyCompression, codec, org_apache_arrow_flatbuf_CompressionType, org_apache_arrow_flatbuf_CompressionType_enum_t, INT8_C(0))
/**  Indicates the way the record batch body was compressed */
__flatbuffers_define_scalar_field(1, org_apache_arrow_flatbuf_BodyCompression, method, org_apache_arrow_flatbuf_BodyCompressionMethod, org_apache_arrow_flatbuf_BodyCompressionMethod_enum_t, INT8_C(0))

/**  A data header describing the shared memory layout of a "record" or "row"
 *  batch. Some systems call this a "row batch" internally and others a "record
 *  batch". */
struct org_apache_arrow_flatbuf_RecordBatch_table { uint8_t unused__; };

static inline size_t org_apache_arrow_flatbuf_RecordBatch_vec_len(org_apache_arrow_flatbuf_RecordBatch_vec_t vec)
__flatbuffers_vec_len(vec)
static inline org_apache_arrow_flatbuf_RecordBatch_table_t org_apache_arrow_flatbuf_RecordBatch_vec_at(org_apache_arrow_flatbuf_RecordBatch_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(org_apache_arrow_flatbuf_RecordBatch_table_t, vec, i, 0)
__flatbuffers_table_as_root(org_apache_arrow_flatbuf_RecordBatch)

/**  number of records / rows. The arrays in the batch should all have this
 *  length */
__flatbuffers_define_scalar_field(0, org_apache_arrow_flatbuf_RecordBatch, length, flatbuffers_int64, int64_t, INT64_C(0))
/**  Nodes correspond to the pre-ordered flattened logical schema */
__flatbuffers_define_vector_field(1, org_apache_arrow_flatbuf_RecordBatch, nodes, org_apache_arrow_flatbuf_FieldNode_vec_t, 0)
/**  Buffers correspond to the pre-ordered flattened buffer tree
 * 
 *  The number of buffers appended to this list depends on the schema. For
 *  example, most primitive arrays will have 2 buffers, 1 for the validity
 *  bitmap and 1 for the values. For struct arrays, there will only be a
 *  single buffer for the validity (nulls) bitmap */
__flatbuffers_define_vector_field(2, org_apache_arrow_flatbuf_RecordBatch, buffers, org_apache_arrow_flatbuf_Buffer_vec_t, 0)
/**  Optional compression of the message body */
__flatbuffers_define_table_field(3, org_apache_arrow_flatbuf_RecordBatch, compression, org_apache_arrow_flatbuf_BodyCompression_table_t, 0)

/**  For sending dictionary encoding information. Any Field can be
 *  dictionary-encoded, but in this case none of its children may be
 *  dictionary-encoded.
 *  There is one vector / column per dictionary, but that vector / column
 *  may be spread across multiple dictionary batches by using the isDelta
 *  flag */
struct org_apache_arrow_flatbuf_DictionaryBatch_table { uint8_t unused__; };

static inline size_t org_apache_arrow_flatbuf_DictionaryBatch_vec_len(org_apache_arrow_flatbuf_DictionaryBatch_vec_t vec)
__flatbuffers_vec_len(vec)
static inline org_apache_arrow_flatbuf_DictionaryBatch_table_t org_apache_arrow_flatbuf_DictionaryBatch_vec_at(org_apache_arrow_flatbuf_DictionaryBatch_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(org_apache_arrow_flatbuf_DictionaryBatch_table_t, vec, i, 0)
__flatbuffers_table_as_root(org_apache_arrow_flatbuf_DictionaryBatch)

__flatbuffers_define_scalar_field(0, org_apache_arrow_flatbuf_DictionaryBatch, id, flatbuffers_int64, int64_t, INT64_C(0))
__flatbuffers_define_table_field(1, org_apache_arrow_flatbuf_DictionaryBatch, data, org_apache_arrow_flatbuf_RecordBatch_table_t, 0)
/**  If isDelta is true the values in the dictionary are to be appended to a
 *  dictionary with the indicated id. If isDelta is false this dictionary
 *  should replace the existing dictionary. */
__flatbuffers_define_scalar_field(2, org_apache_arrow_flatbuf_DictionaryBatch, isDelta, flatbuffers_bool, flatbuffers_bool_t, UINT8_C(0))
/**  ----------------------------------------------------------------------
 *  The root Message type
 *  This union enables us to easily send different message types without
 *  redundant storage, and in the future we can easily add new message types.
 * 
 *  Arrow implementations do not need to implement all of the message types,
 *  which may include experimental metadata types. For maximum compatibility,
 *  it is best to send data using RecordBatch */
typedef uint8_t org_apache_arrow_flatbuf_MessageHeader_union_type_t;
__flatbuffers_define_integer_type(org_apache_arrow_flatbuf_MessageHeader, org_apache_arrow_flatbuf_MessageHeader_union_type_t, 8)
__flatbuffers_define_union(flatbuffers_, org_apache_arrow_flatbuf_MessageHeader)
#define org_apache_arrow_flatbuf_MessageHeader_NONE ((org_apache_arrow_flatbuf_MessageHeader_union_type_t)UINT8_C(0))
#define org_apache_arrow_flatbuf_MessageHeader_Schema ((org_apache_arrow_flatbuf_MessageHeader_union_type_t)UINT8_C(1))
#define org_apache_arrow_flatbuf_MessageHeader_DictionaryBatch ((org_apache_arrow_flatbuf_MessageHeader_union_type_t)UINT8_C(2))
#define org_apache_arrow_flatbuf_MessageHeader_RecordBatch ((org_apache_arrow_flatbuf_MessageHeader_union_type_t)UINT8_C(3))
#define org_apache_arrow_flatbuf_MessageHeader_Tensor ((org_apache_arrow_flatbuf_MessageHeader_union_type_t)UINT8_C(4))
#define org_apache_arrow_flatbuf_MessageHeader_SparseTensor ((org_apache_arrow_flatbuf_MessageHeader_union_type_t)UINT8_C(5))

static inline const char *org_apache_arrow_flatbuf_MessageHeader_type_name(org_apache_arrow_flatbuf_MessageHeader_union_type_t type)
{
    switch (type) {
    case org_apache_arrow_flatbuf_MessageHeader_NONE: return "NONE";
    case org_apache_arrow_flatbuf_MessageHeader_Schema: return "Schema";
    case org_apache_arrow_flatbuf_MessageHeader_DictionaryBatch: return "DictionaryBatch";
    case org_apache_arrow_flatbuf_MessageHeader_RecordBatch: return "RecordBatch";
    case org_apache_arrow_flatbuf_MessageHeader_Tensor: return "Tensor";
    case org_apache_arrow_flatbuf_MessageHeader_SparseTensor: return "SparseTensor";
    default: return "";
    }
}

static inline int org_apache_arrow_flatbuf_MessageHeader_is_known_type(org_apache_arrow_flatbuf_MessageHeader_union_type_t type)
{
    switch (type) {
    case org_apache_arrow_flatbuf_MessageHeader_NONE: return 1;
    case org_apache_arrow_flatbuf_MessageHeader_Schema: return 1;
    case org_apache_arrow_flatbuf_MessageHeader_DictionaryBatch: return 1;
    case org_apache_arrow_flatbuf_MessageHeader_RecordBatch: return 1;
    case org_apache_arrow_flatbuf_MessageHeader_Tensor: return 1;
    case org_apache_arrow_flatbuf_MessageHeader_SparseTensor: return 1;
    default: return 0;
    }
}


struct org_apache_arrow_flatbuf_Message_table { uint8_t unused__; };

static inline size_t org_apache_arrow_flatbuf_Message_vec_len(org_apache_arrow_flatbuf_Message_vec_t vec)
__flatbuffers_vec_len(vec)
static inline org_apache_arrow_flatbuf_Message_table_t org_apache_arrow_flatbuf_Message_vec_at(org_apache_arrow_flatbuf_Message_vec_t vec, size_t i)
__flatbuffers_offset_vec_at(org_apache_arrow_flatbuf_Message_table_t, vec, i, 0)
__flatbuffers_table_as_root(org_apache_arrow_flatbuf_Message)

__flatbuffers_define_scalar_field(0, org_apache_arrow_flatbuf_Message, version, org_apache_arrow_flatbuf_MetadataVersion, org_apache_arrow_flatbuf_MetadataVersion_enum_t, INT16_C(0))
__flatbuffers_define_union_field(flatbuffers_, 2, org_apache_arrow_flatbuf_Message, header, org_apache_arrow_flatbuf_MessageHeader, 0)
__flatbuffers_define_scalar_field(3, org_apache_arrow_flatbuf_Message, bodyLength, flatbuffers_int64, int64_t, INT64_C(0))
__flatbuffers_define_vector_field(4, org_apache_arrow_flatbuf_Message, custom_metadata, org_apache_arrow_flatbuf_KeyValue_vec_t, 0)


#include "flatcc/flatcc_epilogue.h"
#endif /* MESSAGE_READER_H */