cmake_minimum_required(VERSION 3.0)

PROJECT("Interface_bin")

SET(CMAKE_CXX_STANDARD 11)

include("compile/var.cmake")
include("compile/import.cmake")
include("compile/links.cmake")

FILE(GLOB_RECURSE file_compo src/*.cpp)

option(COMPOME_LOG_D "ACTIVATE/DESACTIVATE log system" 1)
if(COMPOME_LOG_D)
  add_compile_definitions(COMPOME_LOG=1)
else(COMPOME_LOG_D)
  add_compile_definitions(COMPOME_LOG=0)
endif(COMPOME_LOG_D)

ADD_EXECUTABLE(Http_server_bin ${file_compo})
TARGET_INCLUDE_DIRECTORIES(Http_server_bin PUBLIC ${_include_directories})

TARGET_LINK_LIBRARIES(Http_server_bin ${_links_lib})
