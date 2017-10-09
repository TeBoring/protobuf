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

// -----------------------------------------------------------------------------
// Field_Kind
// -----------------------------------------------------------------------------

static zend_function_entry field_kind_methods[] = {
  {NULL, NULL, NULL}
};

zend_class_entry* field_kind_type;

// Init class entry.
PHP_PROTO_INIT_ENUMCLASS_START("Google\\Protobuf\\Field_Kind",
                                Field_Kind, field_kind)
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_UNKNOWN", 12, 0 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_DOUBLE", 11, 1 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_FLOAT", 10, 2 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_INT64", 10, 3 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_UINT64", 11, 4 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_INT32", 10, 5 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_FIXED64", 12, 6 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_FIXED32", 12, 7 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_BOOL", 9, 8 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_STRING", 11, 9 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_GROUP", 10, 10 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_MESSAGE", 12, 11 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_BYTES", 10, 12 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_UINT32", 11, 13 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_ENUM", 9, 14 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_SFIXED32", 13, 15 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_SFIXED64", 13, 16 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_SINT32", 11, 17 TSRMLS_CC);
  zend_declare_class_constant_long(field_kind_type,
                                   "TYPE_SINT64", 11, 18 TSRMLS_CC);
PHP_PROTO_INIT_ENUMCLASS_END

// -----------------------------------------------------------------------------
// NullValue
// -----------------------------------------------------------------------------

static zend_function_entry null_value_methods[] = {
  {NULL, NULL, NULL}
};

zend_class_entry* null_value_type;

// Init class entry.
PHP_PROTO_INIT_ENUMCLASS_START("Google\\Protobuf\\NullValue",
                                NullValue, null_value)
  zend_declare_class_constant_long(null_value_type,
                                   "NULL_VALUE", 10, 0 TSRMLS_CC);
PHP_PROTO_INIT_ENUMCLASS_END

// -----------------------------------------------------------------------------
// Syntax
// -----------------------------------------------------------------------------

static zend_function_entry syntax_methods[] = {
  {NULL, NULL, NULL}
};

zend_class_entry* syntax_type;

// Init class entry.
PHP_PROTO_INIT_ENUMCLASS_START("Google\\Protobuf\\Syntax",
                                Syntax, syntax)
  zend_declare_class_constant_long(syntax_type,
                                   "SYNTAX_PROTO2", 13, 0 TSRMLS_CC);
  zend_declare_class_constant_long(syntax_type,
                                   "SYNTAX_PROTO3", 13, 1 TSRMLS_CC);
PHP_PROTO_INIT_ENUMCLASS_END

