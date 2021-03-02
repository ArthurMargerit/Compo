include("${CMAKE_CURRENT_LIST_DIR}/Ext_option.cmake" OPTIONAL)
include("${CMAKE_CURRENT_LIST_DIR}/Int_option.cmake" OPTIONAL)

######################################################### LOG SYSTEM ##########
include(CMakeDependentOption)
option(CompoMeLog "CompoMe Log System" 0)
foreach ( Debug_file ${src_file} )
  cmake_dependent_option(${Debug_file}_debug_on_off "Use Foo" OFF
                        "CompoMeLog" OFF)
  set_source_files_properties(src/Data/code.cpp PROPERTIES COMPILE_DEFINITIONS "COMPOME_LOG=\"${${Debug_file}_debug_on_off}\"")
endforeach()
###############################################################################