if [[ ! -v COMPOME_PATH ]]
then
    export COMPOME_PATH="$(realpath ../../..)"
fi

export COMPOME_MODEL_PATH=$(echo ${COMPOME_PATH}/build/* | tr ' ' ':'):.
