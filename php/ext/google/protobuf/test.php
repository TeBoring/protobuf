<?php

namespace Google\Protobuf;

$pool = get_generated_pool();
$pool->new_builder()
    ->add_message("TestMessage")
    ->optional("optional_int32_a", "int32", 1)
    ->optional("optional_int32_b", "int32", 2)
    ->finalize()
    ->finalize_to_pool();

$test_message = new \TestMessage();
$test_message->optional_int32_a = -42;
var_dump($test_message->optional_int32_a);

?>
