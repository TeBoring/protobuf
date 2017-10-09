// -----------------------------------------------------------------------------
// Option
// -----------------------------------------------------------------------------

static zend_function_entry option_methods[] = {
  PHP_ME(Option, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Option, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Option, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Option, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Option, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* option_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Option",
                                 Option, option)
  zend_class_implements(option_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(option_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(option_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Option, __construct) {
  init_file_type();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(option_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Option, option, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Option, option, Value, "value")

