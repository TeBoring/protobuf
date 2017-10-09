#!/bin/bash

pushd ..; make -j4; popd; ./protoc --php_out=sandbox \
  google/protobuf/any.proto \
  google/protobuf/api.proto \
  google/protobuf/duration.proto \
  google/protobuf/empty.proto \
  google/protobuf/field_mask.proto \
  google/protobuf/source_context.proto \
  google/protobuf/struct.proto \
  google/protobuf/timestamp.proto \
  google/protobuf/type.proto \
  google/protobuf/wrappers.proto \

cd sandbox

cat ./Google/Protobuf/Any.message.c ./Google/Protobuf/Api.message.c ./Google/Protobuf/BoolValue.message.c ./Google/Protobuf/BytesValue.message.c ./Google/Protobuf/DoubleValue.message.c ./Google/Protobuf/Duration.message.c ./Google/Protobuf/Enum.message.c ./Google/Protobuf/EnumValue.message.c ./Google/Protobuf/FieldMask.message.c ./Google/Protobuf/Field.message.c ./Google/Protobuf/FloatValue.message.c ./Google/Protobuf/GPBEmpty.message.c ./Google/Protobuf/Int32Value.message.c ./Google/Protobuf/Int64Value.message.c ./Google/Protobuf/ListValue.message.c ./Google/Protobuf/Method.message.c ./Google/Protobuf/Mixin.message.c ./Google/Protobuf/Option.message.c ./Google/Protobuf/SourceContext.message.c ./Google/Protobuf/StringValue.message.c ./Google/Protobuf/Struct.message.c ./Google/Protobuf/Timestamp.message.c ./Google/Protobuf/Type.message.c ./Google/Protobuf/UInt32Value.message.c ./Google/Protobuf/UInt64Value.message.c ./Google/Protobuf/Value.message.c > message.c

cat ./Google/Protobuf/Any.protobuf.h ./Google/Protobuf/Api.protobuf.h ./Google/Protobuf/BoolValue.protobuf.h ./Google/Protobuf/BytesValue.protobuf.h ./Google/Protobuf/DoubleValue.protobuf.h ./Google/Protobuf/Duration.protobuf.h ./Google/Protobuf/Enum.protobuf.h ./Google/Protobuf/EnumValue.protobuf.h ./Google/Protobuf/FieldMask.protobuf.h ./Google/Protobuf/Field.protobuf.h ./Google/Protobuf/FloatValue.protobuf.h ./Google/Protobuf/GPBEmpty.protobuf.h ./Google/Protobuf/Int32Value.protobuf.h ./Google/Protobuf/Int64Value.protobuf.h ./Google/Protobuf/ListValue.protobuf.h ./Google/Protobuf/Method.protobuf.h ./Google/Protobuf/Mixin.protobuf.h ./Google/Protobuf/Option.protobuf.h ./Google/Protobuf/SourceContext.protobuf.h ./Google/Protobuf/StringValue.protobuf.h ./Google/Protobuf/Struct.protobuf.h ./Google/Protobuf/Timestamp.protobuf.h ./Google/Protobuf/Type.protobuf.h ./Google/Protobuf/UInt32Value.protobuf.h ./Google/Protobuf/UInt64Value.protobuf.h ./Google/Protobuf/Value.protobuf.h > protobuf.h

cat ./Google/Protobuf/Any.metadata.h ./Google/Protobuf/Api.metadata.h ./Google/Protobuf/Duration.metadata.h ./Google/Protobuf/FieldMask.metadata.h ./Google/Protobuf/GPBEmpty.metadata.h ./Google/Protobuf/SourceContext.metadata.h ./Google/Protobuf/Struct.metadata.h ./Google/Protobuf/Timestamp.metadata.h ./Google/Protobuf/Type.metadata.h ./Google/Protobuf/Wrappers.metadata.h > metadata.h

cat ./Google/Protobuf/Any.metadata.c ./Google/Protobuf/Api.metadata.c ./Google/Protobuf/Duration.metadata.c ./Google/Protobuf/FieldMask.metadata.c ./Google/Protobuf/GPBEmpty.metadata.c ./Google/Protobuf/SourceContext.metadata.c ./Google/Protobuf/Struct.metadata.c ./Google/Protobuf/Timestamp.metadata.c ./Google/Protobuf/Type.metadata.c ./Google/Protobuf/Wrappers.metadata.c > metadata.c

cat ./Google/Protobuf/Field_Cardinality.enum.c ./Google/Protobuf/Field_Kind.enum.c ./Google/Protobuf/NullValue.enum.c ./Google/Protobuf/Syntax.enum.c > enum.c
