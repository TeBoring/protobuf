// -----------------------------------------------------------------------------
// Type
// -----------------------------------------------------------------------------

static zend_function_entry type_methods[] = {
  PHP_ME(Type, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getFields, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setFields, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getOneofs, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setOneofs, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getSyntax, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setSyntax, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* type_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Type",
                                 Type, type)
  zend_class_implements(type_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(type_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "fields", strlen("fields"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "oneofs", strlen("oneofs"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "options", strlen("options"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "source_context", strlen("source_context"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "syntax", strlen("syntax"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Type, __construct) {
  init_file_type();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(type_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Type, type, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Type, type, Fields, "fields")
PHP_PROTO_FIELD_ACCESSORS(Type, type, Oneofs, "oneofs")
PHP_PROTO_FIELD_ACCESSORS(Type, type, Options, "options")
PHP_PROTO_FIELD_ACCESSORS(Type, type, SourceContext, "source_context")
PHP_PROTO_FIELD_ACCESSORS(Type, type, Syntax, "syntax")

