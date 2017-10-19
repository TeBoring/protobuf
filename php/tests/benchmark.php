<?php

require_once('generated/NoNamespaceEnum.php');
require_once('generated/NoNamespaceMessage.php');
require_once('generated/NoNamespaceMessage_NestedEnum.php');
require_once('generated/PrefixEmpty.php');
require_once('generated/PrefixTestPrefix.php');
require_once('generated/TestEmptyNamespace.php');
require_once('generated/Bar/TestInclude.php');
require_once('generated/Foo/PBARRAY.php');
require_once('generated/Foo/PBEmpty.php');
require_once('generated/Foo/TestEnum.php');
require_once('generated/Foo/TestIncludeNamespaceMessage.php');
require_once('generated/Foo/TestIncludePrefixMessage.php');
require_once('generated/Foo/TestMessage.php');
require_once('generated/Foo/TestMessage_Empty.php');
require_once('generated/Foo/TestMessage_NestedEnum.php');
require_once('generated/Foo/TestMessage_Sub.php');
require_once('generated/Foo/TestPackedMessage.php');
require_once('generated/Foo/TestPhpDoc.php');
require_once('generated/Foo/TestRandomFieldOrder.php');
require_once('generated/Foo/TestReverseFieldOrder.php');
require_once('generated/Foo/TestUnpackedMessage.php');
require_once('generated/Foo/testLowerCaseMessage.php');
require_once('generated/Foo/testLowerCaseEnum.php');
require_once('generated/GPBMetadata/Proto/Test.php');
require_once('generated/GPBMetadata/Proto/TestEmptyPhpNamespace.php');
require_once('generated/GPBMetadata/Proto/TestInclude.php');
require_once('generated/GPBMetadata/Proto/TestNoNamespace.php');
require_once('generated/GPBMetadata/Proto/TestPhpNamespace.php');
require_once('generated/GPBMetadata/Proto/TestPrefix.php');
require_once('generated/Php/Test/TestNamespace.php');
require_once('test_util.php');

use Foo\TestMessage;

function microtime_float() {
    list($usec, $sec) = explode(" ", microtime());
      return ((float)$usec + (float)$sec);
}

$person1 = new TestMessage();
TestUtil::setTestMessage($person1);

$encode_time = 0;
$decode_time = 0;
$size = 0;

for ($i = 0; $i < 10000; $i++) {
    $time_start = microtime_float();
    $data = $person1->serializeToString();
    $time_end = microtime_float();
    $encode_time += $time_end - $time_start;
    $size += strlen($data);

    $person2 = new TestMessage();
    $time_start = microtime_float();
    $person2->mergeFromString($data);
    $time_end = microtime_float();
    $decode_time += $time_end - $time_start;
}

echo "Encode: $encode_time s\n";
echo "Decode: $decode_time s\n";

$encode_time = 0;
$decode_time = 0;
$size = 0;

$arr = json_decode($person1->serializeToJsonString());

for ($i = 0; $i < 10000; $i++) {
    $time_start = microtime_float();
    $data = json_encode($arr);
    $time_end = microtime_float();
    $encode_time += $time_end - $time_start;
    $size += strlen($data);

    $time_start = microtime_float();
    json_decode($data);
    $time_end = microtime_float();
    $decode_time += $time_end - $time_start;
}

echo "Encode: $encode_time s\n";
echo "Decode: $decode_time s\n";
