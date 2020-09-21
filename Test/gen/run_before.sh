#!/usr/bin/env bash
set -euo pipefail


for target in $@ ; do
    echo $(tput setab 4 ) ${target} $(tput sgr0)
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

    mkdir -p ${COMPO_WORKDIR}
    cp -r ${target} ${COMPO_WORKDIR}
    cd ${COMPO_WORKDIR}/$(basename ${target})
    ${COMPOME_PATH}/compome generate -f *.yaml

    if [ "$COMPOME_MODEL" == "CPP" ]
    then
        cmake -DCMAKE_BUILD_TYPE=${DEBUG_RELEASE} -DCMAKE_INSTALL_PREFIX=${COMPOME_PATH}/CompoMe .
        make -j8
        make install
    elif [ "$COMPOME_MODEL" == "GRAPH" ]
    then
        FTI=$(find -name "*.html")
        for f in ${FTI}
        do
            echo Install: ${f}
            mkdir -p $(dirname ${COMPOME_PATH}/${f})
            cp ${f} ${COMPOME_PATH}/CompoMe/${f}
        done
    fi

    cd -
    if [[ $COMPO_RMDIR == 1 ]]
    then
        rm $COMPO_WORKDIR
    fi
done
