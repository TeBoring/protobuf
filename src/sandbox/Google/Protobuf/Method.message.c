// -----------------------------------------------------------------------------
// Method
// -----------------------------------------------------------------------------

static zend_function_entry method_methods[] = {
  PHP_ME(Method, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, getRequestTypeUrl, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, setRequestTypeUrl, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, getRequestStreaming, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, setRequestStreaming, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, getResponseTypeUrl, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, setResponseTypeUrl, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, getResponseStreaming, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, setResponseStreaming, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, setOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, getSyntax, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Method, setSyntax, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* method_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Method",
                                 Method, method)
  zend_class_implements(method_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(method_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(method_type, "request_type_url", strlen("request_type_url"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(method_type, "request_streaming", strlen("request_streaming"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(method_type, "response_type_url", strlen("response_type_url"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(method_type, "response_streaming", strlen("response_streaming"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(method_type, "options", strlen("options"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(method_type, "syntax", strlen("syntax"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Method, __construct) {
  init_file_api();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(method_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Method, method, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Method, method, RequestTypeUrl, "request_type_url")
PHP_PROTO_FIELD_ACCESSORS(Method, method, RequestStreaming, "request_streaming")
PHP_PROTO_FIELD_ACCESSORS(Method, method, ResponseTypeUrl, "response_type_url")
PHP_PROTO_FIELD_ACCESSORS(Method, method, ResponseStreaming, "response_streaming")
PHP_PROTO_FIELD_ACCESSORS(Method, method, Options, "options")
PHP_PROTO_FIELD_ACCESSORS(Method, method, Syntax, "syntax")

