# This file is the Cmake file to compile the swig part
# You need to define by including compile/var.cmake :
# ${_links_lib}
# ${_include_directories})
# ${compo_project_name}

set (UseSWIG_TARGET_NAME_PREFERENCE STANDARD)
find_package(SWIG 4.0 COMPONENTS python)
if(SWIG_FOUND)
  message("SWIG found: ${SWIG_EXECUTABLE}")
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
message("My python inc:" ${MY_PYTHON_INC} )
message("My python lib:" ${MY_PYTHON_LIB} )

foreach(file ${swig_file})
  get_filename_component(Ta ${file} NAME_WE)
  get_filename_component(Ta_pa ${file} DIRECTORY swig)
  string(REGEX REPLACE "swig" "" Ta_p ${Ta_pa})

  set_property(SOURCE ${file} PROPERTY CPLUSPLUS ON)

  swig_add_library(${Ta} LANGUAGE python SOURCES ${file} OUTFILE_DIR swig_src/${Ta_p} OUTPUT_DIR swig_lib/${Ta_p})

  set_property(TARGET ${Ta} PROPERTY SWIG_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/inc ${CMAKE_CURRENT_SOURCE_DIR}/swig ${_include_directories} ${_include_directories_swig})

  set_property(TARGET ${Ta} PROPERTY POSITION_INDEPENDENT_CODE ON)
  set_property(TARGET ${Ta} PROPERTY LIBRARY_OUTPUT_DIRECTORY swig_lib/${Ta_p})

  target_include_directories(${Ta} PUBLIC ${MY_PYTHON_INC})
  target_include_directories(${Ta} PUBLIC ${_include_directories})

  target_link_libraries(${Ta} ${MY_PYTHON_LIB})
  target_link_libraries(${Ta} ${_links_dir} ${_links_lib} ${_links_lib})
  target_link_libraries(${Ta} ${compo_lib_name})
  install(TARGETS ${Ta}
        LIBRARY DESTINATION swig_lib/${Ta_p})
endforeach(file)

install(DIRECTORY ${CMAKE_BINARY_DIR}/swig_lib DESTINATION .
        FILES_MATCHING PATTERN "**/*.py")

install(DIRECTORY swig DESTINATION .
        FILES_MATCHING PATTERN "*.i")
