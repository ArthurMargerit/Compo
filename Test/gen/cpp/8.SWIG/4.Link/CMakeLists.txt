cmake_minimum_required(VERSION 3.12.0)

PROJECT("CompoMe_Swig")

SET(CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

include("compile/var.cmake")
include("compile/import.cmake")
include("compile/links.cmake")

message(${_include_directories_swig})

FILE(GLOB_RECURSE file_compo src/*.cpp)
add_library(${compo_project_name} SHARED ${file_compo})
target_link_libraries(${compo_project_name} ${_links_lib})
target_include_directories(${compo_project_name} PUBLIC ${_include_directories} inc)
install(TARGETS ${compo_project_name}
  LIBRARY DESTINATION lib/)

include(CompoMe_Swig.cmake)
