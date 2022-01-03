#!/usr/bin/env bash
set -euo pipefail

export DEBUG_RELEASE=Debug # Release
if [[ -v "COMPO_WORKDIR_TMP" && "$COMPO_WORKDIR_TMP" == 1 ]]
then
    COMPO_WORKDIR=$(mktemp -d)
    COMPO_RMDIR=1
else
    COMPO_WORKDIR=tmp_before
    COMPO_RMDIR=0
    rm -rf tmp_before
fi

if [[ ! -v COMPOME_INSTALL ]]
then
    COMPOME_INSTALL=${COMPOME_PATH}/build
fi

echo "Build to be install: " ${COMPOME_INSTALL}


function Compo_build {
    if [ "$1" == "ALL" ]
    then
        Compo_build "CPP"
        Compo_build "GRAPH"
    elif [ "$1" == "CPP" ]
    then
        cmake -DCMAKE_BUILD_TYPE=${DEBUG_RELEASE} -DCMAKE_INSTALL_PREFIX=${COMPOME_INSTALL}/$(basename ${target}) .
        make -j8
        make install
    elif [ "$1" == "GRAPH" ]
    then
        FTI=$(find -name "*.html")
        for f in ${FTI}
        do
            local target_f=${COMPOME_INSTALL}/$(basename ${target})/${f}
            echo "Install: ${f} -> ${target_f}"
            mkdir -p $(dirname ${target_f})
            cp ${f} ${target_f}
        done
    fi
}

function Compo_generate {
    if [ "$1" == "ALL" ]
    then
        Compo_generate "CPP"
        Compo_generate "GRAPH"
    else
        COMPOME_MODEL=$1 ${COMPOME_PATH}/compome generate -f *.yaml
    fi
}


export COMPOME_MODEL_PATH=$(echo ${COMPOME_INSTALL}/* | tr ' ' ':')

# COPY OF CPP_BEFORE TARGET TO TMP_BEFORE  ####################################
for target in $@ ; do
    echo $(tput setab 4 ) cp ${target} $(tput sgr0)
    mkdir -p ${COMPO_WORKDIR}
    cp -r ${target} ${COMPO_WORKDIR}
    export COMPOME_MODEL_PATH=$(realpath ${COMPO_WORKDIR}/$(basename ${target})):${COMPOME_MODEL_PATH}
done

export COMPOME_GRAPH_PATH=${COMPOME_MODEL_PATH}

# GERNERATE TARGET ####################################
for target in $@ ; do
    echo $(tput setab 4 ) gen ${target} $(tput sgr0)
    cd ${COMPO_WORKDIR}/$(basename ${target})

    Compo_generate ${COMPOME_MODEL}
    cd ../..
done

for target in $@ ; do
    cd ${COMPO_WORKDIR}/$(basename ${target})
    echo $(tput setab 4 ) build ${target} $(tput sgr0)

    Compo_build ${COMPOME_MODEL}

    cd ../..
done

if [[ $COMPO_RMDIR == 1 ]]
then
    rm -r $COMPO_WORKDIR
fi
