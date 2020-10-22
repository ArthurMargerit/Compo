#!/usr/bin/env bash
set -euo pipefail

export TERM=xterm-256color
export COMPOME_PATH=$(pwd)
export COMPOME_MODEL_PATH=${COMPOME_PATH}/CompoMe
export COMPOME_GRAPH_PATH=${COMPOME_PATH}/CompoMe

cd Test/gen
export COMPOME_MODEL=CPP
./run_before.sh cpp_before/Test
./run_before.sh cpp_before/CompoMe
./run_before.sh cpp_before/CompoMe_Swig
./run_before.sh cpp_before/CompoMe_Log
./run_before.sh cpp_before/CompoMe_Tools
./run_before.sh cpp_before/CompoMe_Async
./run_before.sh cpp_before/CompoMe_Tcp
./run_before.sh cpp_before/CompoMe_Udp
./run_before.sh cpp_before/CompoMe_Http
./run_before.sh cpp_before/CompoMe_Zmq
./run_before.sh cpp_before/CompoMe_Dbus

export COMPOME_MODEL=GRAPH
./run_before.sh cpp_before/Test
./run_before.sh cpp_before/CompoMe
./run_before.sh cpp_before/CompoMe_Swig
./run_before.sh cpp_before/CompoMe_Log
./run_before.sh cpp_before/CompoMe_Tools
./run_before.sh cpp_before/CompoMe_Async
./run_before.sh cpp_before/CompoMe_Tcp
./run_before.sh cpp_before/CompoMe_Udp
./run_before.sh cpp_before/CompoMe_Zmq
./run_before.sh cpp_before/CompoMe_Dbus

########################### test
# ./run_test.sh cpp
# ./run_test.sh graph
# ./run_test.sh uml
