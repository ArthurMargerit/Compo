# This file is the Cmake file to compile the swig part
# You need to define by including compile/var.cmake :
# ${_links_lib}
# ${_include_directories})
# ${compo_project_name}

cmake_policy(SET CMP0078 NEW)

set (UseSWIG_TARGET_NAME_PREFERENCE STANDARD)
find_package(SWIG 4.0 COMPONENTS python)
if(SWIG_FOUND)
  message(VERBOSE "SWIG found: ${SWIG_EXECUTABLE}")
else()
  message(FATAL_ERROR "SWIG not found")
endif()

include (UseSWIG)

if( DEFINED ENV{EXR_USE_PYTHON_ENV} AND "$ENV{EXR_USE_PYTHON_ENV}" EQUAL "1" )
  set(MY_PYTHON_INC $ENV{PYTHON_INCLUDE_DIR})
  set(MY_PYTHON_LIB $ENV{PYTHON_LIBRARY})
else()
find_package(PythonLibs COMPONENTS Development)
if(PYTHONLIBS_FOUND)
  set(MY_PYTHON_INC ${PYTHON_INCLUDE_DIRS})
  set(MY_PYTHON_LIB ${PYTHON_LIBRARIES})
else()
  find_package(Python3 COMPONENTS Development)
  set(MY_PYTHON_INC ${Python3_INCLUDE_DIRS})
  set(MY_PYTHON_LIB ${Python3_LIBRARIES})
endif()
endif()

set(SWIG_OUTFILE_DIR tmp)
message(VERBOSE "My python inc:" ${MY_PYTHON_INC} )
message(VERBOSE "My python lib:" ${MY_PYTHON_LIB} )

foreach(file ${swig_file})
  get_filename_component(Ta ${file} NAME_WE)
  get_filename_component(Ta_pa ${file} DIRECTORY swig)
  string(REGEX REPLACE "swig" "" Ta_p ${Ta_pa})
  string(REGEX REPLACE "/" "_" Ta_target ${file})
  string(REGEX REPLACE ".i" "" Ta_target ${Ta_target})

  set_property(SOURCE ${file} PROPERTY CPLUSPLUS ON)

  swig_add_library(${Ta_target} LANGUAGE python SOURCES ${file} OUTFILE_DIR swig_src/${Ta_p} OUTPUT_DIR swig_lib/${Ta_p})

  set_property(TARGET ${Ta_target} PROPERTY SWIG_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/swig ${_include_directories} ${_include_directories_swig})

  set_property(TARGET ${Ta_target} PROPERTY POSITION_INDEPENDENT_CODE ON)
  set_property(TARGET ${Ta_target} PROPERTY LIBRARY_OUTPUT_DIRECTORY swig_lib/${Ta_p})

  target_include_directories(${Ta_target} PUBLIC ${MY_PYTHON_INC})
  target_include_directories(${Ta_target} PUBLIC ${_include_directories})

  target_link_libraries(${Ta_target} ${MY_PYTHON_LIB})
  target_link_libraries(${Ta_target} ${_links_dir} ${_links_lib} ${_links_lib})
  target_link_libraries(${Ta_target} ${compo_lib_name})
  install(TARGETS ${Ta_target} LIBRARY DESTINATION swig_lib/${Ta_p})

endforeach(file)

install(DIRECTORY ${CMAKE_BINARY_DIR}/swig_lib DESTINATION .
        FILES_MATCHING PATTERN "**/*.py")

install(DIRECTORY swig DESTINATION .
        FILES_MATCHING PATTERN "*.i")
