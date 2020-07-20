#!/usr/bin/env bash

mkdir ${COMPOME_PATH}/CompoMe/lib -p
mkdir ${COMPOME_PATH}/CompoMe/inc -p
mkdir ${COMPOME_PATH}/CompoMe/model -p

cp inc/* ${COMPOME_PATH}/CompoMe/inc/. -r
cp *.so *.a ${COMPOME_PATH}/CompoMe/lib/.
cp *.yaml ${COMPOME_PATH}/CompoMe/
