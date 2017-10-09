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

// -----------------------------------------------------------------------------
// Api
// -----------------------------------------------------------------------------

static zend_function_entry api_methods[] = {
  PHP_ME(Api, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getMethods, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setMethods, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getVersion, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setVersion, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getMixins, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setMixins, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, getSyntax, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Api, setSyntax, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* api_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Api",
                                 Api, api)
  zend_class_implements(api_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(api_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "methods", strlen("methods"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "options", strlen("options"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "version", strlen("version"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "source_context", strlen("source_context"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "mixins", strlen("mixins"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(api_type, "syntax", strlen("syntax"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Api, __construct) {
  init_file_api();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(api_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Api, api, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Methods, "methods")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Options, "options")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Version, "version")
PHP_PROTO_FIELD_ACCESSORS(Api, api, SourceContext, "source_context")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Mixins, "mixins")
PHP_PROTO_FIELD_ACCESSORS(Api, api, Syntax, "syntax")

// -----------------------------------------------------------------------------
// BoolValue
// -----------------------------------------------------------------------------

static zend_function_entry bool_value_methods[] = {
  PHP_ME(BoolValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(BoolValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(BoolValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* bool_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\BoolValue",
                                 BoolValue, bool_value)
  zend_class_implements(bool_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(bool_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(BoolValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(bool_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(BoolValue, bool_value, Value, "value")

// -----------------------------------------------------------------------------
// BytesValue
// -----------------------------------------------------------------------------

static zend_function_entry bytes_value_methods[] = {
  PHP_ME(BytesValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(BytesValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(BytesValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* bytes_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\BytesValue",
                                 BytesValue, bytes_value)
  zend_class_implements(bytes_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(bytes_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(BytesValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(bytes_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(BytesValue, bytes_value, Value, "value")

// -----------------------------------------------------------------------------
// DoubleValue
// -----------------------------------------------------------------------------

static zend_function_entry double_value_methods[] = {
  PHP_ME(DoubleValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(DoubleValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(DoubleValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* double_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\DoubleValue",
                                 DoubleValue, double_value)
  zend_class_implements(double_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(double_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(DoubleValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(double_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(DoubleValue, double_value, Value, "value")

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

// -----------------------------------------------------------------------------
// FieldMask
// -----------------------------------------------------------------------------

static zend_function_entry field_mask_methods[] = {
  PHP_ME(FieldMask, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(FieldMask, getPaths, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(FieldMask, setPaths, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* field_mask_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\FieldMask",
                                 FieldMask, field_mask)
  zend_class_implements(field_mask_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(field_mask_type, "paths", strlen("paths"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(FieldMask, __construct) {
  init_file_field_mask();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(field_mask_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(FieldMask, field_mask, Paths, "paths")

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

// -----------------------------------------------------------------------------
// FloatValue
// -----------------------------------------------------------------------------

static zend_function_entry float_value_methods[] = {
  PHP_ME(FloatValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(FloatValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(FloatValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* float_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\FloatValue",
                                 FloatValue, float_value)
  zend_class_implements(float_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(float_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(FloatValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(float_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(FloatValue, float_value, Value, "value")

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


// -----------------------------------------------------------------------------
// Int32Value
// -----------------------------------------------------------------------------

static zend_function_entry int32_value_methods[] = {
  PHP_ME(Int32Value, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Int32Value, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Int32Value, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* int32_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Int32Value",
                                 Int32Value, int32_value)
  zend_class_implements(int32_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(int32_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Int32Value, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(int32_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Int32Value, int32_value, Value, "value")

// -----------------------------------------------------------------------------
// Int64Value
// -----------------------------------------------------------------------------

static zend_function_entry int64_value_methods[] = {
  PHP_ME(Int64Value, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Int64Value, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Int64Value, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* int64_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Int64Value",
                                 Int64Value, int64_value)
  zend_class_implements(int64_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(int64_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Int64Value, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(int64_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Int64Value, int64_value, Value, "value")

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

// -----------------------------------------------------------------------------
// Mixin
// -----------------------------------------------------------------------------

static zend_function_entry mixin_methods[] = {
  PHP_ME(Mixin, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Mixin, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Mixin, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Mixin, getRoot, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Mixin, setRoot, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* mixin_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Mixin",
                                 Mixin, mixin)
  zend_class_implements(mixin_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(mixin_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(mixin_type, "root", strlen("root"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Mixin, __construct) {
  init_file_api();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(mixin_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Mixin, mixin, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Mixin, mixin, Root, "root")

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

// -----------------------------------------------------------------------------
// SourceContext
// -----------------------------------------------------------------------------

static zend_function_entry source_context_methods[] = {
  PHP_ME(SourceContext, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(SourceContext, getFileName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(SourceContext, setFileName, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* source_context_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\SourceContext",
                                 SourceContext, source_context)
  zend_class_implements(source_context_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(source_context_type, "file_name", strlen("file_name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(SourceContext, __construct) {
  init_file_source_context();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(source_context_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(SourceContext, source_context, FileName, "file_name")

// -----------------------------------------------------------------------------
// StringValue
// -----------------------------------------------------------------------------

static zend_function_entry string_value_methods[] = {
  PHP_ME(StringValue, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(StringValue, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(StringValue, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* string_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\StringValue",
                                 StringValue, string_value)
  zend_class_implements(string_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(string_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(StringValue, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(string_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(StringValue, string_value, Value, "value")

// -----------------------------------------------------------------------------
// Struct
// -----------------------------------------------------------------------------

static zend_function_entry struct_methods[] = {
  PHP_ME(Struct, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Struct, getFields, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Struct, setFields, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* struct_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Struct",
                                 Struct, struct)
  zend_class_implements(struct_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(struct_type, "fields", strlen("fields"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Struct, __construct) {
  init_file_struct();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(struct_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Struct, struct, Fields, "fields")

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

// -----------------------------------------------------------------------------
// Type
// -----------------------------------------------------------------------------

static zend_function_entry type_methods[] = {
  PHP_ME(Type, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setName, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getFields, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setFields, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getOneofs, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setOneofs, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setOptions, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setSourceContext, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, getSyntax, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Type, setSyntax, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* type_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Type",
                                 Type, type)
  zend_class_implements(type_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(type_type, "name", strlen("name"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "fields", strlen("fields"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "oneofs", strlen("oneofs"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "options", strlen("options"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "source_context", strlen("source_context"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
  zend_declare_property_null(type_type, "syntax", strlen("syntax"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Type, __construct) {
  init_file_type();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(type_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Type, type, Name, "name")
PHP_PROTO_FIELD_ACCESSORS(Type, type, Fields, "fields")
PHP_PROTO_FIELD_ACCESSORS(Type, type, Oneofs, "oneofs")
PHP_PROTO_FIELD_ACCESSORS(Type, type, Options, "options")
PHP_PROTO_FIELD_ACCESSORS(Type, type, SourceContext, "source_context")
PHP_PROTO_FIELD_ACCESSORS(Type, type, Syntax, "syntax")

// -----------------------------------------------------------------------------
// UInt32Value
// -----------------------------------------------------------------------------

static zend_function_entry u_int32_value_methods[] = {
  PHP_ME(UInt32Value, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(UInt32Value, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(UInt32Value, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* u_int32_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\UInt32Value",
                                 UInt32Value, u_int32_value)
  zend_class_implements(u_int32_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(u_int32_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(UInt32Value, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(u_int32_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(UInt32Value, u_int32_value, Value, "value")

// -----------------------------------------------------------------------------
// UInt64Value
// -----------------------------------------------------------------------------

static zend_function_entry u_int64_value_methods[] = {
  PHP_ME(UInt64Value, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(UInt64Value, getValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(UInt64Value, setValue, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* u_int64_value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\UInt64Value",
                                 UInt64Value, u_int64_value)
  zend_class_implements(u_int64_value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(u_int64_value_type, "value", strlen("value"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(UInt64Value, __construct) {
  init_file_wrappers();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(u_int64_value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(UInt64Value, u_int64_value, Value, "value")

// -----------------------------------------------------------------------------
// Value
// -----------------------------------------------------------------------------

static zend_function_entry value_methods[] = {
  PHP_ME(Value, __construct, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getNullValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setNullValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getNumberValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setNumberValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getStringValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setStringValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getBoolValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setBoolValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getStructValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setStructValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getListValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, setListValue, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Value, getKind, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

zend_class_entry* value_type;

// Init class entry.
PHP_PROTO_INIT_SUBMSGCLASS_START("Google\\Protobuf\\Value",
                                 Value, value)
  zend_class_implements(value_type TSRMLS_CC, 1, message_type);
  zend_declare_property_null(value_type, "kind", strlen("kind"),
                             ZEND_ACC_PRIVATE TSRMLS_CC);
PHP_PROTO_INIT_SUBMSGCLASS_END

PHP_METHOD(Value, __construct) {
  init_file_struct();
  MessageHeader* intern = UNBOX(MessageHeader, getThis());
  custom_data_init(value_type, intern PHP_PROTO_TSRMLS_CC);
}

PHP_PROTO_FIELD_ACCESSORS(Value, value, NullValue, "null_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, NumberValue, "number_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, StringValue, "string_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, BoolValue, "bool_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, StructValue, "struct_value")
PHP_PROTO_FIELD_ACCESSORS(Value, value, ListValue, "list_value")
PHP_PROTO_ONEOF_ACCESSORS(Value, value, Kind, "kind")

