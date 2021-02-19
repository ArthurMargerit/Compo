#!/usr/bin/env bash
TMP_DIR=$(mktemp --directory)

cd ${TMP_DIR}
mkdir esp
cd esp
git clone -b v4.2 --recursive https://github.com/espressif/esp-idf.git
cd esp-idf
./install.sh
. ${TMP_DIR}/esp/esp-idf/export.sh
cd ${TMP_DIR}/esp
cp -r $IDF_PATH/examples/get-started/hello_world .
cd hello_world
mkdir build
cd build
cmake ..
make

echo ${TMP_DIR}
