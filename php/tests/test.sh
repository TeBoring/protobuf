#!/bin/bash

VERSION=$1

# Generate code for proto
../../src/protoc --php_out=generated         \
  proto/test.proto                           \
  proto/test_include.proto                   \
  proto/test_no_namespace.proto              \
  proto/test_prefix.proto                    \
  proto/test_php_namespace.proto             \
  proto/test_empty_php_namespace.proto       \
  proto/test_reserved_enum_lower.proto       \
  proto/test_reserved_enum_upper.proto       \
  proto/test_reserved_enum_value_lower.proto \
  proto/test_reserved_enum_value_upper.proto \
  proto/test_reserved_message_lower.proto    \
  proto/test_reserved_message_upper.proto    \
  proto/test_service.proto                   \
  proto/test_service_namespace.proto         \
  proto/test_descriptors.proto
pushd ../../src
./protoc --php_out=../php/tests/generated -I../php/tests -I. \
  ../php/tests/proto/test_import_descriptor_proto.proto
popd

export PATH=/usr/local/php-$VERSION/bin:$PATH
export C_INCLUDE_PATH=/usr/local/php-$VERSION/include/php/main:/usr/local/php-$VERSION/include/php:$C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH=/usr/local/php-$VERSION/include/php/main:/usr/local/php-$VERSION/include/php:$CPLUS_INCLUDE_PATH

# Compile c extension
pushd ../ext/google/protobuf/
make clean || true
set -e
# Add following in configure for debug: --enable-debug CFLAGS='-g -O0'
phpize && ./configure CFLAGS='-g -O0' && make
popd

tests=( array_test.php encode_decode_test.php generated_class_test.php generated_phpdoc_test.php map_field_test.php well_known_test.php generated_service_test.php descriptors_test.php )

for t in "${tests[@]}"
do
  echo "****************************"
  echo "* $t"
  echo "****************************"
  php -dextension=../ext/google/protobuf/modules/protobuf.so `which phpunit` --bootstrap autoload.php $t
  echo ""
done

# # Make sure to run the memory test in debug mode.
# php -dextension=../ext/google/protobuf/modules/protobuf.so memory_leak_test.php

export ZEND_DONT_UNLOAD_MODULES=1
export USE_ZEND_ALLOC=0
valgrind --leak-check=yes php -dextension=../ext/google/protobuf/modules/protobuf.so memory_leak_test.php

# TODO(teboring): Only for debug (phpunit has memory leak which blocks this beging used by
# regresssion test.)

# for t in "${tests[@]}"
# do
#   echo "****************************"
#   echo "* $t (memory leak)"
#   echo "****************************"
#   valgrind --leak-check=yes php -dextension=../ext/google/protobuf/modules/protobuf.so `which phpunit` --bootstrap autoload.php $t
#   echo ""
# done
