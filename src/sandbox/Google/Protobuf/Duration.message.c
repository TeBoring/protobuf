// -----------------------------------------------------------------------------
// Duration
// -----------------------------------------------------------------------------

static zend_function_entry duration_methods[] = {
  PHP_ME(Duration, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Duration, getSeconds, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Duration, setSeconds, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Duration, getNanos, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Duration, setNanos, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* duration_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Duration",
                                 Duration, duration)
  zend_class_implements(duration_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(duration_type, "seconds", strlen("seconds"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(duration_type, "nanos", strlen("nanos"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Duration, __construct) {
  init_file_duration();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(duration_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Duration, duration, Seconds, "seconds")
PHP_PROTO_FIELD_ACCESSORS(Duration, duration, Nanos, "nanos")

