// -----------------------------------------------------------------------------
// GPBEmpty
// -----------------------------------------------------------------------------

static zend_function_entry g_p_b_empty_methods[] = {
  PHP_ME(GPBEmpty, __construct, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* g_p_b_empty_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\GPBEmpty",
                                 GPBEmpty, g_p_b_empty)
  zend_class_implements(g_p_b_empty_type TSRMLS_CC, 1, message_type);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(GPBEmpty, __construct) {
  init_file_empty();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(g_p_b_empty_type, intern PHP_PROTO_TSRMLS_CC);
}


