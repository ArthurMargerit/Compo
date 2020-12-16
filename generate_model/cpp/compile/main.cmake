list(APPEND CMAKE_MODULE_PATH "compile/{{FILE.replace('.yaml','')}}")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)

include("${CMAKE_CURRENT_LIST_DIR}/var.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/option.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/import.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/links.cmake")

PROJECT(${compo_project_name})
SET(CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

ADD_LIBRARY(${compo_lib_name} ${src_file})
set_property(TARGET ${compo_lib_name} PROPERTY POSITION_INDEPENDENT_CODE ON)
TARGET_INCLUDE_DIRECTORIES(${compo_lib_name} PUBLIC ${_include_directories})
TARGET_LINK_LIBRARIES(${compo_lib_name} ${_links_lib} ${_links_lib} ${_links_dir})
include("${CMAKE_CURRENT_LIST_DIR}/install.cmake")
include(CompoMe_Swig)


