#!/usr/bin/env bash
set -euo pipefail

export COMPOME_PATH=$(realpath ../../)
export COMPOME_MODEL=ALL

rm ${COMPOME_PATH}/build/* -rf

echo "__CORE__"
./run_before.sh cpp_before/CompoMe cpp_before/CompoMe_Async cpp_before/CompoMe_Log cpp_before/CompoMe_Swig cpp_before/CompoMe_Test cpp_before/CompoMe_Tools cpp_before/CompoMe_Json cpp_before/CompoMe_Port

echo "__CORE__OPT"
./run_before.sh cpp_before/CompoMe_Dbus cpp_before/CompoMe_Http cpp_before/CompoMe_Https cpp_before/CompoMe_Tcp cpp_before/CompoMe_Udp cpp_before/CompoMe_Zmq
