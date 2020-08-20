cmake_minimum_required(VERSION 3.0)

PROJECT("Dbus_client_bin")
SET(CMAKE_CXX_STANDARD 11)

include("compile/var.cmake")
include("compile/import.cmake")
include("compile/links.cmake")

FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(dbus_client_bin ${file_compo})
TARGET_INCLUDE_DIRECTORIES(dbus_client_bin PUBLIC ${_include_directories})
TARGET_LINK_LIBRARIES(dbus_client_bin ${_links_lib})
TARGET_COMPILE_OPTIONS(dbus_client_bin PUBLIC ${DBUS_CFLAGS_OTHER})



