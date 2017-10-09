// -----------------------------------------------------------------------------
// Timestamp
// -----------------------------------------------------------------------------

static zend_function_entry timestamp_methods[] = {
  PHP_ME(Timestamp, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Timestamp, getSeconds, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Timestamp, setSeconds, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Timestamp, getNanos, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Timestamp, setNanos, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* timestamp_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Timestamp",
                                 Timestamp, timestamp)
  zend_class_implements(timestamp_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(timestamp_type, "seconds", strlen("seconds"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(timestamp_type, "nanos", strlen("nanos"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Timestamp, __construct) {
  init_file_timestamp();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(timestamp_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Timestamp, timestamp, Seconds, "seconds")
PHP_PROTO_FIELD_ACCESSORS(Timestamp, timestamp, Nanos, "nanos")

