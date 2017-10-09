// -----------------------------------------------------------------------------
// EnumValue
// -----------------------------------------------------------------------------

static zend_function_entry enum_value_methods[] = {
  PHP_ME(EnumValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(EnumValue, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(EnumValue, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(EnumValue, getNumber, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(EnumValue, setNumber, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(EnumValue, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(EnumValue, setOptions, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* enum_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\EnumValue",
                                 EnumValue, enum_value)
  zend_class_implements(enum_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(enum_value_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(enum_value_type, "number", strlen("number"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(enum_value_type, "options", strlen("options"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(EnumValue, __construct) {
  init_file_type();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(enum_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(EnumValue, enum_value, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(EnumValue, enum_value, Number, "number")
PHP_PROTO_FIELD_ACCESSORS(EnumValue, enum_value, Options, "options")

