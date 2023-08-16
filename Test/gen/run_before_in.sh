#!/usr/bin/env bash
set -euo pipefail
source ./compo_tools.sh

export DEBUG_RELEASE=Debug # Release
# export DEBUG_RELEASE=Release

if [[ ! -v COMPOME_INSTALL ]]
then
    COMPOME_INSTALL=${COMPOME_PATH}/build
fi

echo "Build to be install: " ${COMPOME_INSTALL}

export COMPOME_MODEL_PATH=$(echo ${COMPOME_INSTALL}/* | tr ' ' ':')
export COMPOME_GRAPH_PATH=${COMPOME_MODEL_PATH}

# GERNERATE TARGET ####################################
for target in $@ ; do
    cd ${target}

    echo $(tput setab 4 ) Generate: ${target} $(tput sgr0)
    Compo_generate ${COMPOME_MODEL}

    cd ../..
done

for target in $@ ; do
    cd ${target}

    echo $(tput setab 4 ) Build: ${target} $(tput sgr0)
    Compo_build ${COMPOME_MODEL}

    cd ../..
done

for target in $@ ; do
    cd ${target}

    echo $(tput setab 4 ) Install: ${target} $(tput sgr0)
    Compo_install ${COMPOME_MODEL}

    cd ../..
done
