#!/usr/bin/env bash
set -euo pipefail

DEBUG_RELEASE=Debug # Release
if [[ -v "COMPO_WORKDIR_TMP" && "$COMPO_WORKDIR_TMP" == 1 ]]
then
    COMPO_WORKDIR=$(mktemp -d)
    COMPO_RMDIR=1
else
    COMPO_WORKDIR=tmp_before
    COMPO_RMDIR=0
    rm -rf tmp_before
fi

for target in $@ ; do
    echo $(tput setab 4 ) cp ${target} $(tput sgr0)

    mkdir -p ${COMPO_WORKDIR}
    cp -r ${target} ${COMPO_WORKDIR}
    export COMPOME_MODEL_PATH=$(realpath ${COMPO_WORKDIR}/$(basename ${target})):${COMPOME_MODEL_PATH}
done

for target in $@ ; do
    echo $(tput setab 4 ) gen ${target} $(tput sgr0)
    cd ${COMPO_WORKDIR}/$(basename ${target})
    ${COMPOME_PATH}/compome generate -f *.yaml
    cd ../..
done

for target in $@ ; do
    cd ${COMPO_WORKDIR}/$(basename ${target})
    echo $(tput setab 4 ) build ${target} $(tput sgr0)

    if [ "$COMPOME_MODEL" == "CPP" ]
    then
        cmake -DCMAKE_BUILD_TYPE=${DEBUG_RELEASE} -DCMAKE_INSTALL_PREFIX=${COMPOME_PATH}/build/$(basename ${target}) .
        make -j8
        make install
    elif [ "$COMPOME_MODEL" == "GRAPH" ]
    then
        FTI=$(find -name "*.html")
        for f in ${FTI}
        do
            echo Install: ${f}
            mkdir -p $(dirname ${COMPOME_PATH}/CompoMe/${f})
            cp ${f} ${COMPOME_PATH}/CompoMe/${f}
        done
    fi

    cd ../..
done

if [[ $COMPO_RMDIR == 1 ]]
then
    rm -r $COMPO_WORKDIR
fi
