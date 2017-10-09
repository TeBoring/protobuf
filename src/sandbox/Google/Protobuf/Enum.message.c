// -----------------------------------------------------------------------------
// Enum
// -----------------------------------------------------------------------------

static zend_function_entry enum_methods[] = {
  PHP_ME(Enum, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, getEnumvalue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, setEnumvalue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, setOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, getSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, setSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, getSyntax, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Enum, setSyntax, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* enum_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Enum",
                                 Enum, enum)
  zend_class_implements(enum_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(enum_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(enum_type, "enumvalue", strlen("enumvalue"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(enum_type, "options", strlen("options"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(enum_type, "source_context", strlen("source_context"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(enum_type, "syntax", strlen("syntax"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Enum, __construct) {
  init_file_type();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(enum_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Enum, enum, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Enum, enum, Enumvalue, "enumvalue")
PHP_PROTO_FIELD_ACCESSORS(Enum, enum, Options, "options")
PHP_PROTO_FIELD_ACCESSORS(Enum, enum, SourceContext, "source_context")
PHP_PROTO_FIELD_ACCESSORS(Enum, enum, Syntax, "syntax")

