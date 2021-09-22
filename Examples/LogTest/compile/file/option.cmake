include("${CMAKE_CURRENT_LIST_DIR}/Ext_option.cmake" OPTIONAL)
include("${CMAKE_CURRENT_LIST_DIR}/Int_option.cmake" OPTIONAL)

######################################################### LOG SYSTEM ##########
include(CMakeDependentOption)
option(CompoMeLog "CompoMe Log System" 0)
foreach ( Debug_file ${src_file} )
  cmake_dependent_option(${Debug_file}_debug_on_off "Use Foo" OFF
                        "CompoMeLog" OFF)
  if( ${${Debug_file}_debug_on_off} STREQUAL "ON" )
      set(log_on_for_this_file 1)
  else()
      set(log_on_for_this_file 0)
  endif()
  set_source_files_properties(${Debug_file} PROPERTIES COMPILE_DEFINITIONS "COMPOME_LOG=${log_on_for_this_file}")
endforeach()
###############################################################################