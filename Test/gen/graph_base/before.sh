if [[ ! -v COMPOME_PATH ]]
then
    export COMPOME_PATH="$(realpath ../../..)"
fi

export COMPOME_MODEL_PATH=${COMPOME_PATH}/CompoMe
export COMPOME_GRAPH_PATH=${COMPOME_PATH}/CompoMe