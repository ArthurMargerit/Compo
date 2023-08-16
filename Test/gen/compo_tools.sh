#!/usr/bin/env bash
set -euo pipefail

function Compo_build {
    if [ "$1" == "ALL" ]
    then
        Compo_build "CPP"
        Compo_build "GRAPH"
    elif [ "$1" == "CPP" ]
    then
        cmake -DCMAKE_BUILD_TYPE=${DEBUG_RELEASE} -DCMAKE_INSTALL_PREFIX=${COMPOME_INSTALL}/$(basename ${target}) -B build .
        make -j8 -C build
    elif [ "$1" == "GRAPH" ]
    then
        echo No action for graph
    fi
}

function Compo_install {
    if [ "$1" == "ALL" ]
    then
        Compo_install "CPP"
        Compo_install "GRAPH"
    elif [ "$1" == "CPP" ]
    then
        make install -C build
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

