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

