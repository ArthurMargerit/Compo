cmake_minimum_required(VERSION 3.0)

PROJECT("Dbus_server_bin")
SET(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(DBUS REQUIRED "dbus-cxx-1.0")

FILE(GLOB_RECURSE file_compo src/*/*.cpp)

ADD_LIBRARY(libI1 ${file_compo})

include("compile/import.cmake")
include("compile/links.cmake")

TARGET_INCLUDE_DIRECTORIES(libI1 PUBLIC ${_include_directories})

TARGET_LINK_LIBRARIES(libI1 ${_links_lib} -lCatch_thread_static)
TARGET_LINK_LIBRARIES(libI1 ${DBUS_LIBRARIES})
TARGET_COMPILE_OPTIONS(libI1 PUBLIC ${DBUS_CFLAGS_OTHER})

ADD_EXECUTABLE(server src/server.cpp)
ADD_EXECUTABLE(dep1 src/client.cpp)
TARGET_INCLUDE_DIRECTORIES(server PUBLIC ${_include_directories})
TARGET_INCLUDE_DIRECTORIES(dep1 PUBLIC ${_include_directories})

TARGET_LINK_LIBRARIES(server libI1 ${_links_lib})
TARGET_LINK_LIBRARIES(dep1 libI1 ${_links_lib})
