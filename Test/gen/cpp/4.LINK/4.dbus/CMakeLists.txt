cmake_minimum_required(VERSION 3.0)

PROJECT("Dbus_server_bin")
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
SET(CMAKE_EXE_LINKER_FLAGS
  "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,. -Wl,-rpath -Wl,lib -Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(DBUS REQUIRED "dbus-cxx-1.0")

FILE(GLOB_RECURSE file_compo src/*/*.cpp)

ADD_LIBRARY(libI1 ${file_compo})

include("compile/code/import.cmake")
include("compile/code/links.cmake")

TARGET_INCLUDE_DIRECTORIES(libI1 PUBLIC ${_include_directories})

TARGET_LINK_LIBRARIES(libI1 ${_links_dir} ${_links_lib} ${_links_lib})
TARGET_LINK_LIBRARIES(libI1 ${DBUS_LIBRARIES})
TARGET_COMPILE_OPTIONS(libI1 PUBLIC ${DBUS_CFLAGS_OTHER})

ADD_EXECUTABLE(dbus_server_test src/server.cpp)
ADD_EXECUTABLE(dep1 src/client.cpp)
TARGET_INCLUDE_DIRECTORIES(dbus_server_test PUBLIC ${_include_directories})
TARGET_INCLUDE_DIRECTORIES(dep1 PUBLIC ${_include_directories})

TARGET_LINK_LIBRARIES(dbus_server_test libI1 ${_links_dir} ${_links_lib} ${_links_lib})
TARGET_LINK_LIBRARIES(dep1 libI1 ${_links_dir} ${_links_lib} ${_links_lib})
