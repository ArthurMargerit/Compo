cmake_minimum_required(VERSION 3.0)

PROJECT("Dbus_server_bin")
SET(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(DBUS REQUIRED "dbus-cxx-1.0")

FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(dep1 ${file_compo})

include("compile/import.cmake")
include("compile/links.cmake")

TARGET_INCLUDE_DIRECTORIES(dep1 PUBLIC ${_include_directories})
TARGET_INCLUDE_DIRECTORIES(dep1 PUBLIC ${DBUS_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(dep1 ${_links_lib} -lCatch_static)
TARGET_LINK_LIBRARIES(dep1 ${DBUS_LIBRARIES})
TARGET_COMPILE_OPTIONS(dep1 PUBLIC ${DBUS_CFLAGS_OTHER})



