PHP_METHOD(Any, __construct);
PHP_METHOD(Any, getTypeUrl);
PHP_METHOD(Any, setTypeUrl);
PHP_METHOD(Any, getValue);
PHP_METHOD(Any, setValue);

PHP_METHOD(Api, __construct);
PHP_METHOD(Api, getName);
PHP_METHOD(Api, setName);
PHP_METHOD(Api, getMethods);
PHP_METHOD(Api, setMethods);
PHP_METHOD(Api, getOptions);
PHP_METHOD(Api, setOptions);
PHP_METHOD(Api, getVersion);
PHP_METHOD(Api, setVersion);
PHP_METHOD(Api, getSourceContext);
PHP_METHOD(Api, setSourceContext);
PHP_METHOD(Api, getMixins);
PHP_METHOD(Api, setMixins);
PHP_METHOD(Api, getSyntax);
PHP_METHOD(Api, setSyntax);

PHP_METHOD(BoolValue, __construct);
PHP_METHOD(BoolValue, getValue);
PHP_METHOD(BoolValue, setValue);

PHP_METHOD(BytesValue, __construct);
PHP_METHOD(BytesValue, getValue);
PHP_METHOD(BytesValue, setValue);

PHP_METHOD(DoubleValue, __construct);
PHP_METHOD(DoubleValue, getValue);
PHP_METHOD(DoubleValue, setValue);

PHP_METHOD(Duration, __construct);
PHP_METHOD(Duration, getSeconds);
PHP_METHOD(Duration, setSeconds);
PHP_METHOD(Duration, getNanos);
PHP_METHOD(Duration, setNanos);

PHP_METHOD(Enum, __construct);
PHP_METHOD(Enum, getName);
PHP_METHOD(Enum, setName);
PHP_METHOD(Enum, getEnumvalue);
PHP_METHOD(Enum, setEnumvalue);
PHP_METHOD(Enum, getOptions);
PHP_METHOD(Enum, setOptions);
PHP_METHOD(Enum, getSourceContext);
PHP_METHOD(Enum, setSourceContext);
PHP_METHOD(Enum, getSyntax);
PHP_METHOD(Enum, setSyntax);

PHP_METHOD(EnumValue, __construct);
PHP_METHOD(EnumValue, getName);
PHP_METHOD(EnumValue, setName);
PHP_METHOD(EnumValue, getNumber);
PHP_METHOD(EnumValue, setNumber);
PHP_METHOD(EnumValue, getOptions);
PHP_METHOD(EnumValue, setOptions);

PHP_METHOD(FieldMask, __construct);
PHP_METHOD(FieldMask, getPaths);
PHP_METHOD(FieldMask, setPaths);

PHP_METHOD(Field, __construct);
PHP_METHOD(Field, getKind);
PHP_METHOD(Field, setKind);
PHP_METHOD(Field, getCardinality);
PHP_METHOD(Field, setCardinality);
PHP_METHOD(Field, getNumber);
PHP_METHOD(Field, setNumber);
PHP_METHOD(Field, getName);
PHP_METHOD(Field, setName);
PHP_METHOD(Field, getTypeUrl);
PHP_METHOD(Field, setTypeUrl);
PHP_METHOD(Field, getOneofIndex);
PHP_METHOD(Field, setOneofIndex);
PHP_METHOD(Field, getPacked);
PHP_METHOD(Field, setPacked);
PHP_METHOD(Field, getOptions);
PHP_METHOD(Field, setOptions);
PHP_METHOD(Field, getJsonName);
PHP_METHOD(Field, setJsonName);
PHP_METHOD(Field, getDefaultValue);
PHP_METHOD(Field, setDefaultValue);

PHP_METHOD(FloatValue, __construct);
PHP_METHOD(FloatValue, getValue);
PHP_METHOD(FloatValue, setValue);

PHP_METHOD(GPBEmpty, __construct);

PHP_METHOD(Int32Value, __construct);
PHP_METHOD(Int32Value, getValue);
PHP_METHOD(Int32Value, setValue);

PHP_METHOD(Int64Value, __construct);
PHP_METHOD(Int64Value, getValue);
PHP_METHOD(Int64Value, setValue);

PHP_METHOD(ListValue, __construct);
PHP_METHOD(ListValue, getValues);
PHP_METHOD(ListValue, setValues);

PHP_METHOD(Method, __construct);
PHP_METHOD(Method, getName);
PHP_METHOD(Method, setName);
PHP_METHOD(Method, getRequestTypeUrl);
PHP_METHOD(Method, setRequestTypeUrl);
PHP_METHOD(Method, getRequestStreaming);
PHP_METHOD(Method, setRequestStreaming);
PHP_METHOD(Method, getResponseTypeUrl);
PHP_METHOD(Method, setResponseTypeUrl);
PHP_METHOD(Method, getResponseStreaming);
PHP_METHOD(Method, setResponseStreaming);
PHP_METHOD(Method, getOptions);
PHP_METHOD(Method, setOptions);
PHP_METHOD(Method, getSyntax);
PHP_METHOD(Method, setSyntax);

PHP_METHOD(Mixin, __construct);
PHP_METHOD(Mixin, getName);
PHP_METHOD(Mixin, setName);
PHP_METHOD(Mixin, getRoot);
PHP_METHOD(Mixin, setRoot);

PHP_METHOD(Option, __construct);
PHP_METHOD(Option, getName);
PHP_METHOD(Option, setName);
PHP_METHOD(Option, getValue);
PHP_METHOD(Option, setValue);

PHP_METHOD(SourceContext, __construct);
PHP_METHOD(SourceContext, getFileName);
PHP_METHOD(SourceContext, setFileName);

PHP_METHOD(StringValue, __construct);
PHP_METHOD(StringValue, getValue);
PHP_METHOD(StringValue, setValue);

PHP_METHOD(Struct, __construct);
PHP_METHOD(Struct, getFields);
PHP_METHOD(Struct, setFields);

PHP_METHOD(Timestamp, __construct);
PHP_METHOD(Timestamp, getSeconds);
PHP_METHOD(Timestamp, setSeconds);
PHP_METHOD(Timestamp, getNanos);
PHP_METHOD(Timestamp, setNanos);

PHP_METHOD(Type, __construct);
PHP_METHOD(Type, getName);
PHP_METHOD(Type, setName);
PHP_METHOD(Type, getFields);
PHP_METHOD(Type, setFields);
PHP_METHOD(Type, getOneofs);
PHP_METHOD(Type, setOneofs);
PHP_METHOD(Type, getOptions);
PHP_METHOD(Type, setOptions);
PHP_METHOD(Type, getSourceContext);
PHP_METHOD(Type, setSourceContext);
PHP_METHOD(Type, getSyntax);
PHP_METHOD(Type, setSyntax);

PHP_METHOD(UInt32Value, __construct);
PHP_METHOD(UInt32Value, getValue);
PHP_METHOD(UInt32Value, setValue);

PHP_METHOD(UInt64Value, __construct);
PHP_METHOD(UInt64Value, getValue);
PHP_METHOD(UInt64Value, setValue);

PHP_METHOD(Value, __construct);
PHP_METHOD(Value, getNullValue);
PHP_METHOD(Value, setNullValue);
PHP_METHOD(Value, getNumberValue);
PHP_METHOD(Value, setNumberValue);
PHP_METHOD(Value, getStringValue);
PHP_METHOD(Value, setStringValue);
PHP_METHOD(Value, getBoolValue);
PHP_METHOD(Value, setBoolValue);
PHP_METHOD(Value, getStructValue);
PHP_METHOD(Value, setStructValue);
PHP_METHOD(Value, getListValue);
PHP_METHOD(Value, setListValue);

