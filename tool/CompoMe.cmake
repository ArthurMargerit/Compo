set(CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

######################################################### CMAKE CORE compilation ##########
function(Gen_CompoMe_Core)
  if(EXISTS "${CMAKE_BINARY_DIR}/compo/CompoMe/compile/CompoMe/main.cmake")
    message(VERBOSE "Already Generate CORE GENERATION")
  else()
    message("Generate CORE GENERATION")
    execute_process(COMMAND bash -c "export COMPOME_MODEL=CPP COMPOME_PATH=${CMAKE_CURRENT_SOURCE_DIR}/compo COMPOME_INSTALL=${CMAKE_BINARY_DIR}/compo && cd ${CMAKE_CURRENT_SOURCE_DIR}/compo/Test/gen/ && ./core_build_exr.sh")
  endif()
endfunction()

set(Gen_CompoMe_Model__internal_dir ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "")

######################################################### CMAKE compilation ##########
function(Gen_CompoMe_Model target COMPOME_SRC)

  cmake_parse_arguments(GEN_COMPOME_MODEL "" "MODEL" "" ${ARGN})

  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/compile/${target}/main.cmake")
    message(VERBOSE  "Already Generate " ${target})
  else()
    message("Generate " ${target} : ${CMAKE_CURRENT_SOURCE_DIR})
    execute_process(COMMAND bash -c "mkdir -p ${CMAKE_CURRENT_SOURCE_DIR}/compile/${target}                            
                            export COMPOME_MODEL=CPP
                            export COMPOME_INSTALL=${CMAKE_BINARY_DIR}/compo
                            export COMPOME_MODEL_PATH=$(echo $COMPOME_INSTALL/* | tr ' ' ':'):${GEN_COMPOME_MODEL_MODEL}
                            cd ${COMPOME_SRC}
                            $COMPOME_PATH/compome generate -f ${target}.yaml")
  endif()

  include("${COMPOME_SRC}/compile/${target}/main.cmake")
endfunction()



######################################################### LOG SYSTEM ##########
macro(COMPOME_APPLY_LOG)
    if(NOT DEFINED COMPOME_SRC)
         set(COMPOME_SRC ${CMAKE_SOURCE_DIR})
    endif()

    message(VERBOSE In ${COMPOME_SRC} ":")
    foreach (Debug_file ${ARGV})

            STRING(REPLACE ${COMPOME_SRC}/ "" Debug_file_src ${COMPOME_SRC}/${Debug_file})

            message(VERBOSE "\tLOG"
                            " - "  ${COMPOME_SRC}
                            " of " ${Debug_file_src}
                            " is " ${${Debug_file_src}_log_act}
                            " to " ${${Debug_file_src}_log_output})

            set_property(SOURCE ${Debug_file_src}
                                APPEND PROPERTY
                                COMPILE_DEFINITIONS "COMPOME_LOG=${${Debug_file_src}_log_act}")

            set_property(SOURCE ${Debug_file_src}
                                APPEND PROPERTY
                                COMPILE_DEFINITIONS "COMPOME_LOG_OUTPUT=${${Debug_file_src}_log_output}")
    endforeach()

endmacro()
