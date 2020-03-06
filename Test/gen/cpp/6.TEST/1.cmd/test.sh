#!/bin/env bash

set -euxo pipefail

# cmake . >> cmake.log
# make 2>&1  >> make.log
# ./dep1 >> exec.log
cmake .
make --jobs=$[ $(nproc) ]
cat order.cmd | ./dep1
cat order2.cmd | ./dep2
exit 0
