include("${CMAKE_CURRENT_LIST_DIR}/Ext_option.cmake" OPTIONAL)
include("${CMAKE_CURRENT_LIST_DIR}/Int_option.cmake" OPTIONAL)


######################################################### LOG SYSTEM ##########
include(CMakeDependentOption)
option(CompoMeLog "CompoMe Log System" 0)
foreach ( Debug_file ${src_file})
        message(DF " " ${Debug_file} " " ${${Debug_file}_log_act} " " ${${Debug_file}_log_output})

        set_property(SOURCE ${Debug_file} APPEND PROPERTY COMPILE_DEFINITIONS "COMPOME_LOG=${${Debug_file}_log_act}")
        set_property(SOURCE ${Debug_file} APPEND PROPERTY COMPILE_DEFINITIONS "COMPOME_LOG_OUTPUT=${${Debug_file}_log_output}")
endforeach()
###############################################################################