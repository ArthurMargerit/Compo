cmake_minimum_required(VERSION 3.12.0)

PROJECT("CompoMe_Swig")

SET(CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

set (UseSWIG_TARGET_NAME_PREFERENCE STANDARD)
find_package(SWIG 4.0 COMPONENTS python)
if(SWIG_FOUND)
  message("SWIG found: ${SWIG_EXECUTABLE}")
endif()
include (UseSWIG)


include("compile/var.cmake")
include("compile/import.cmake")
include("compile/links.cmake")

find_package(PythonLibs COMPONENTS Development)
if(PYTHONLIBS_FOUND)
  set(MY_PYTHON ${PYTHON_INCLUDE_DIRS})
else()
  find_package(Python3 COMPONENTS Development)
  set(MY_PYTHON ${Python3_INCLUDE_DIRS})
endif()
set(SWIG_OUTFILE_DIR tmp)

FILE(GLOB_RECURSE file_compo swig/*.i)

foreach(file ${file_compo})
  get_filename_component(Ta ${file} NAME_WE)
  get_filename_component(Ta_pa ${file} DIRECTORY swig)
  string(REGEX REPLACE ".*/swig" "" Ta_p ${Ta_pa})

  set_property(SOURCE ${file} PROPERTY CPLUSPLUS ON)

  swig_add_library(${Ta} LANGUAGE python SOURCES ${file} OUTFILE_DIR swig_src/${Ta_p} OUTPUT_DIR swig_lib/${Ta_p})

  set_property(TARGET ${Ta} PROPERTY SWIG_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/inc ${CMAKE_SOURCE_DIR}/swig ${_include_directories})
  set_property(TARGET ${Ta} PROPERTY POSITION_INDEPENDENT_CODE ON)
  set_property(TARGET ${Ta} PROPERTY LIBRARY_OUTPUT_DIRECTORY swig_lib/${Ta_p})

  target_include_directories(${Ta} PUBLIC ${MY_PYTHON})
  target_include_directories(${Ta} PUBLIC ${_include_directories})

  target_link_libraries(${Ta} ${PYTHON_LIBRARIES})
  target_link_libraries(${Ta} ${_links_lib})
  install(TARGETS ${Ta}
        LIBRARY DESTINATION swig_lib/${Ta_p})
endforeach(file)

install(DIRECTORY ${CMAKE_BINARY_DIR}/swig_lib DESTINATION .
        FILES_MATCHING PATTERN "*.py")

install(DIRECTORY swig DESTINATION .
        FILES_MATCHING PATTERN "*.i")

install(FILES ${compo_project_name}.yaml DESTINATION .)
install(FILES compile/${compo_project_name}_links.cmake DESTINATION compile)
install(FILES compile/${compo_project_name}_import.cmake DESTINATION compile)
