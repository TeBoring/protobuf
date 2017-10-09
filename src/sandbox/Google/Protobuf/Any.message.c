// -----------------------------------------------------------------------------
// Any
// -----------------------------------------------------------------------------

static zend_function_entry any_methods[] = {
  PHP_ME(Any, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Any, getTypeUrl, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Any, setTypeUrl, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Any, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Any, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* any_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Any",
                                 Any, any)
  zend_class_implements(any_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(any_type, "type_url", strlen("type_url"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(any_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Any, __construct) {
  init_file_any();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(any_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Any, any, TypeUrl, "type_url")
PHP_PROTO_FIELD_ACCESSORS(Any, any, Value, "value")

