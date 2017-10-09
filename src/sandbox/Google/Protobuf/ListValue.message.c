// -----------------------------------------------------------------------------
// ListValue
// -----------------------------------------------------------------------------

static zend_function_entry list_value_methods[] = {
  PHP_ME(ListValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(ListValue, getValues, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(ListValue, setValues, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* list_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\ListValue",
                                 ListValue, list_value)
  zend_class_implements(list_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(list_value_type, "values", strlen("values"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(ListValue, __construct) {
  init_file_struct();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(list_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(ListValue, list_value, Values, "values")

