// -----------------------------------------------------------------------------
// Field
// -----------------------------------------------------------------------------

static zend_function_entry field_methods[] = {
  PHP_ME(Field, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getKind, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setKind, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getCardinality, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setCardinality, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getNumber, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setNumber, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getTypeUrl, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setTypeUrl, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getOneofIndex, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setOneofIndex, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getPacked, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setPacked, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getJsonName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setJsonName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, getDefaultValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Field, setDefaultValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* field_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Field",
                                 Field, field)
  zend_class_implements(field_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(field_type, "kind", strlen("kind"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "cardinality", strlen("cardinality"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "number", strlen("number"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "type_url", strlen("type_url"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "oneof_index", strlen("oneof_index"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "packed", strlen("packed"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "options", strlen("options"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "json_name", strlen("json_name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(field_type, "default_value", strlen("default_value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Field, __construct) {
  init_file_type();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(field_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Field, field, Kind, "kind")
PHP_PROTO_FIELD_ACCESSORS(Field, field, Cardinality, "cardinality")
PHP_PROTO_FIELD_ACCESSORS(Field, field, Number, "number")
PHP_PROTO_FIELD_ACCESSORS(Field, field, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Field, field, TypeUrl, "type_url")
PHP_PROTO_FIELD_ACCESSORS(Field, field, OneofIndex, "oneof_index")
PHP_PROTO_FIELD_ACCESSORS(Field, field, Packed, "packed")
PHP_PROTO_FIELD_ACCESSORS(Field, field, Options, "options")
PHP_PROTO_FIELD_ACCESSORS(Field, field, JsonName, "json_name")
PHP_PROTO_FIELD_ACCESSORS(Field, field, DefaultValue, "default_value")

