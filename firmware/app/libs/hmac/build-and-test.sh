#!/bin/sh

set -e
set -x

autoreconf -i
./configure $COVERAGE
make check
if [ "x$COVERAGE" != "x" ]; then
    gem install coveralls-lcov
    set +x
    coveralls-lcov coverage/app2.info
fi
