#!/bin/env bash

set -euxo pipefail

cmake .
make --jobs=$[ $(nproc) ]
cat order.cmd | ./dep1
cat order2.cmd | ./dep2

exit 0
