#include "protobuf.h"

#include <zend_hash.h>

// -----------------------------------------------------------------------------
// Global map from upb {msg,enum}defs to wrapper Descriptor/EnumDescriptor
// instances.
// -----------------------------------------------------------------------------

// This is a hash table from def objects (encoded by converting pointers to
// PHP integers) to MessageDef/EnumDef instances (as Ruby values).
HashTable* upb_def_to_php_obj_map;

void add_def_obj(const void* def, zval* value) {
  uint nIndex = (ulong)def & upb_def_to_php_obj_map->nTableMask;

  zval* pDest = NULL;
  zend_hash_index_update(upb_def_to_php_obj_map, (zend_ulong)def, value,
                         sizeof(zval), &pDest);
}

zval* get_def_obj(const void* def) {
  zval* value;
  if (zend_hash_index_find(upb_def_to_php_obj_map, (zend_ulong)def, &value) ==
      FAILURE) {
    zend_error(E_ERROR, "PHP object not found for given definition.\n");
    return NULL;
  }
  return value;
}

// -----------------------------------------------------------------------------
// Utilities.
// -----------------------------------------------------------------------------

// define the function(s) we want to add
zend_function_entry protobuf_functions[] = {
  ZEND_FE(get_generated_pool, NULL)
  ZEND_FE_END
};

// "protobuf_functions" refers to the struct defined above
// we'll be filling in more of this later: you can use this to specify
// globals, php.ini info, startup and teardown functions, etc.
zend_module_entry protobuf_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_PROTOBUF_EXTNAME,
  protobuf_functions,
  PHP_MINIT(protobuf),
  NULL,
  NULL,
  NULL,
  NULL,
  PHP_PROTOBUF_VERSION,
  STANDARD_MODULE_PROPERTIES
};

// install module
ZEND_GET_MODULE(protobuf)

// global variables
// ZEND_DECLARE_MODULE_GLOBALS(protobuf)

static void protobuf_init_globals() {
  generated_pool = NULL;

  ALLOC_HASHTABLE(upb_def_to_php_obj_map);
  zend_hash_init(upb_def_to_php_obj_map, 16, NULL, NULL, 0);
}

PHP_MINIT_FUNCTION(protobuf) {
  // ZEND_INIT_MODULE_GLOBALS(protobuf, protobuf_init_globals, NULL);
  protobuf_init_globals();
  DescriptorPool_init(TSRMLS_C);
  Descriptor_init(TSRMLS_C);
  MessageBuilderContext_init(TSRMLS_C);
  Builder_init(TSRMLS_C);
}
