cmake_minimum_required(VERSION 3.0)

PROJECT("Dbus_client_bin")
SET(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(DBUS REQUIRED "dbus-cxx-1.0")

FILE(GLOB_RECURSE file_compo src/*.cpp)

ADD_EXECUTABLE(dbus_client_bin ${file_compo})

TARGET_INCLUDE_DIRECTORIES(dbus_client_bin PUBLIC ${DBUS_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(dbus_client_bin PUBLIC "inc")

TARGET_LINK_LIBRARIES(dbus_client_bin ${DBUS_LIBRARIES})

TARGET_COMPILE_OPTIONS(dbus_client_bin PUBLIC ${DBUS_CFLAGS_OTHER})



