<?php
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: google/protobuf/descriptor.proto

namespace Google\Protobuf\Internal\FieldDescriptorProto;

use UnexpectedValueException;

class Type
{
    /**
     * 0 is reserved for errors.
     * Order is weird for historical reasons.
     *
     * Generated from protobuf enum <code>TYPE_DOUBLE = 1;</code>
     */
    const TYPE_DOUBLE = 1;
    /**
     * Generated from protobuf enum <code>TYPE_FLOAT = 2;</code>
     */
    const TYPE_FLOAT = 2;
    /**
     * Not ZigZag encoded.  Negative numbers take 10 bytes.  Use TYPE_SINT64 if
     * negative values are likely.
     *
     * Generated from protobuf enum <code>TYPE_INT64 = 3;</code>
     */
    const TYPE_INT64 = 3;
    /**
     * Generated from protobuf enum <code>TYPE_UINT64 = 4;</code>
     */
    const TYPE_UINT64 = 4;
    /**
     * Not ZigZag encoded.  Negative numbers take 10 bytes.  Use TYPE_SINT32 if
     * negative values are likely.
     *
     * Generated from protobuf enum <code>TYPE_INT32 = 5;</code>
     */
    const TYPE_INT32 = 5;
    /**
     * Generated from protobuf enum <code>TYPE_FIXED64 = 6;</code>
     */
    const TYPE_FIXED64 = 6;
    /**
     * Generated from protobuf enum <code>TYPE_FIXED32 = 7;</code>
     */
    const TYPE_FIXED32 = 7;
    /**
     * Generated from protobuf enum <code>TYPE_BOOL = 8;</code>
     */
    const TYPE_BOOL = 8;
    /**
     * Generated from protobuf enum <code>TYPE_STRING = 9;</code>
     */
    const TYPE_STRING = 9;
    /**
     * Tag-delimited aggregate.
     * Group type is deprecated and not supported in proto3. However, Proto3
     * implementations should still be able to parse the group wire format and
     * treat group fields as unknown fields.
     *
     * Generated from protobuf enum <code>TYPE_GROUP = 10;</code>
     */
    const TYPE_GROUP = 10;
    /**
     * Length-delimited aggregate.
     *
     * Generated from protobuf enum <code>TYPE_MESSAGE = 11;</code>
     */
    const TYPE_MESSAGE = 11;
    /**
     * New in version 2.
     *
     * Generated from protobuf enum <code>TYPE_BYTES = 12;</code>
     */
    const TYPE_BYTES = 12;
    /**
     * Generated from protobuf enum <code>TYPE_UINT32 = 13;</code>
     */
    const TYPE_UINT32 = 13;
    /**
     * Generated from protobuf enum <code>TYPE_ENUM = 14;</code>
     */
    const TYPE_ENUM = 14;
    /**
     * Generated from protobuf enum <code>TYPE_SFIXED32 = 15;</code>
     */
    const TYPE_SFIXED32 = 15;
    /**
     * Generated from protobuf enum <code>TYPE_SFIXED64 = 16;</code>
     */
    const TYPE_SFIXED64 = 16;
    /**
     * Uses ZigZag encoding.
     *
     * Generated from protobuf enum <code>TYPE_SINT32 = 17;</code>
     */
    const TYPE_SINT32 = 17;
    /**
     * Uses ZigZag encoding.
     *
     * Generated from protobuf enum <code>TYPE_SINT64 = 18;</code>
     */
    const TYPE_SINT64 = 18;

    private static $valueToName = [
        self::TYPE_DOUBLE => 'TYPE_DOUBLE',
        self::TYPE_FLOAT => 'TYPE_FLOAT',
        self::TYPE_INT64 => 'TYPE_INT64',
        self::TYPE_UINT64 => 'TYPE_UINT64',
        self::TYPE_INT32 => 'TYPE_INT32',
        self::TYPE_FIXED64 => 'TYPE_FIXED64',
        self::TYPE_FIXED32 => 'TYPE_FIXED32',
        self::TYPE_BOOL => 'TYPE_BOOL',
        self::TYPE_STRING => 'TYPE_STRING',
        self::TYPE_GROUP => 'TYPE_GROUP',
        self::TYPE_MESSAGE => 'TYPE_MESSAGE',
        self::TYPE_BYTES => 'TYPE_BYTES',
        self::TYPE_UINT32 => 'TYPE_UINT32',
        self::TYPE_ENUM => 'TYPE_ENUM',
        self::TYPE_SFIXED32 => 'TYPE_SFIXED32',
        self::TYPE_SFIXED64 => 'TYPE_SFIXED64',
        self::TYPE_SINT32 => 'TYPE_SINT32',
        self::TYPE_SINT64 => 'TYPE_SINT64',
    ];

    public static function name($value)
    {
        if (!isset(self::$valueToName[$value])) {
            throw new UnexpectedValueException(sprintf(
                    'Enum %s has no name defined for value %s', __CLASS__, $value));
        }
        return self::$valueToName[$value];
    }


    public static function value($name)
    {
        $const = __CLASS__ . '::' . strtoupper($name);
        if (!defined($const)) {
            throw new UnexpectedValueException(sprintf(
                    'Enum %s has no value defined for name %s', __CLASS__, $name));
        }
        return constant($const);
    }
}

// Adding a class alias for backwards compatibility with the previous class name.
class_alias(Type::class, \Google\Protobuf\Internal\FieldDescriptorProto_Type::class);

