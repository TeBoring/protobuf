// -----------------------------------------------------------------------------
// Field_Cardinality
// -----------------------------------------------------------------------------

static zend_function_entry field_cardinality_methods[] = {
  {NULL, NULL, NULL}
};

zend_class_entry* field_cardinality_type;

// Init class entry.
PHP_PROTO_INIT_ENUMCLASS_START("Google\\Protobuf\\Field_Cardinality",
                                Field_Cardinality, field_cardinality)
  zend_declare_class_constant_long(field_cardinality_type,
                                   "CARDINALITY_UNKNOWN", 19, 0 TSRMLS_CC);
  zend_declare_class_constant_long(field_cardinality_type,
                                   "CARDINALITY_OPTIONAL", 20, 1 TSRMLS_CC);
  zend_declare_class_constant_long(field_cardinality_type,
                                   "CARDINALITY_REQUIRED", 20, 2 TSRMLS_CC);
  zend_declare_class_constant_long(field_cardinality_type,
                                   "CARDINALITY_REPEATED", 20, 3 TSRMLS_CC);
PHP_PROTO_INIT_ENUMCLASS_END

