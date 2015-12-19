<?php

namespace Google\Protobuf;

# $pool = new DescriptorPool();
# var_dump($pool);
#
# $descriptor = new Descriptor();
# var_dump($descriptor);
# $descriptor->name_set('TestMessage');
# $pool->add($descriptor);
# $builder = new Internal\Builder();
# $message_builder_context = new Internal\MessageBuilderContext($descriptor, $builder);
# $pool->build();
# $pool->search('TestMessage')

$descriptor = new Descriptor();
$descriptor->name_set("TestMessage");
$builder = new Internal\Builder();
# $context = new Internal\MessageBuilderContext($descriptor, $builder);
$builder->add_message($descriptor);

$pool = new DescriptorPool();
$builder->finalize_to_pool($pool);
$pool->search('TestMessage')

?>
