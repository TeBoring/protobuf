<?php
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: google/protobuf/type.proto

namespace Google\Protobuf;

use Google\Protobuf\Internal\GPBType;
use Google\Protobuf\Internal\RepeatedField;
use Google\Protobuf\Internal\GPBUtil;

/**
 * Enum value definition.
 *
 * Generated from protobuf message <code>google.protobuf.EnumValue</code>
 */
class EnumValue extends \Google\Protobuf\Internal\Message
{
    /**
     * Enum value name.
     *
     * Generated from protobuf field <code>string name = 1;</code>
     */
    protected $name = '';
    /**
     * Enum value number.
     *
     * Generated from protobuf field <code>int32 number = 2;</code>
     */
    protected $number = 0;
    /**
     * Protocol buffer options.
     *
     * Generated from protobuf field <code>repeated .google.protobuf.Option options = 3;</code>
     */
    private $options;

    /**
     * Constructor.
     *
     * @param array $data {
     *     Optional. Data for populating the Message object.
     *
     *     @type string $name
     *           Enum value name.
     *     @type int $number
     *           Enum value number.
     *     @type \Google\Protobuf\Option[]|\Google\Protobuf\Internal\RepeatedField $options
     *           Protocol buffer options.
     * }
     */
    public function __construct($data = NULL) {
        \GPBMetadata\Google\Protobuf\Type::initOnce();
        parent::__construct($data);
    }

    /**
     * Enum value name.
     *
     * Generated from protobuf field <code>string name = 1;</code>
     * @return string
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * Enum value name.
     *
     * Generated from protobuf field <code>string name = 1;</code>
     * @param string $var
     * @return $this
     */
    public function setName($var)
    {
        $this->name = $var;

        return $this;
    }

    /**
     * Enum value number.
     *
     * Generated from protobuf field <code>int32 number = 2;</code>
     * @return int
     */
    public function getNumber()
    {
        return $this->number;
    }

    /**
     * Enum value number.
     *
     * Generated from protobuf field <code>int32 number = 2;</code>
     * @param int $var
     * @return $this
     */
    public function setNumber($var)
    {
        $this->number = $var;

        return $this;
    }

    /**
     * Protocol buffer options.
     *
     * Generated from protobuf field <code>repeated .google.protobuf.Option options = 3;</code>
     * @return \Google\Protobuf\Internal\RepeatedField
     */
    public function getOptions()
    {
        return $this->options;
    }

    /**
     * Protocol buffer options.
     *
     * Generated from protobuf field <code>repeated .google.protobuf.Option options = 3;</code>
     * @param \Google\Protobuf\Option[]|\Google\Protobuf\Internal\RepeatedField $var
     * @return $this
     */
    public function setOptions($var)
    {
        $arr = GPBUtil::checkRepeatedField($var, \Google\Protobuf\Internal\GPBType::MESSAGE, \Google\Protobuf\Option::class);
        $this->options = $arr;

        return $this;
    }

}

