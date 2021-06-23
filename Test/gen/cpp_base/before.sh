if [[ ! -v COMPOME_PATH ]]
then
    export COMPOME_PATH="$(realpath ../../..)"
fi

if [[ ! -v COMPOME_MODEL_PATH ]]
then
    if [[ ! -v COMPOME_INSTALL ]]
    then
        export COMPOME_MODEL_PATH=$(echo ${COMPOME_PATH}/build/* | tr ' ' ':'):.
    else
        export COMPOME_MODEL_PATH=$(echo ${COMPOME_INSTALL}/* | tr ' ' ':'):.
    fi
fi


