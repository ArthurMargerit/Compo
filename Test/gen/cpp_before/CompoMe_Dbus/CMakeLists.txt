cmake_minimum_required(VERSION 3.0)

PROJECT("CompoMe")
SET(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(DBUS REQUIRED "dbus-cxx-1.0")

FILE(GLOB_RECURSE file_compo src/*.cpp)

add_library(CompoMe_Dbus_static STATIC ${file_compo})
add_library(CompoMe_Dbus_shared SHARED ${file_compo})
add_library(CompoMe_Dbus_module MODULE ${file_compo})

# target_include_directories(CompoMe_Dbus_module PUBLIC "inc")
# target_include_directories(CompoMe_Dbus_static PUBLIC "inc")
# target_include_directories(CompoMe_Dbus_shared PUBLIC "inc")

TARGET_INCLUDE_DIRECTORIES(CompoMe_Dbus_module PUBLIC ${DBUS_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(CompoMe_Dbus_static PUBLIC ${DBUS_INCLUDE_DIRS})
TARGET_INCLUDE_DIRECTORIES(CompoMe_Dbus_shared PUBLIC ${DBUS_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(CompoMe_Dbus_module ${DBUS_LIBRARIES})
TARGET_LINK_LIBRARIES(CompoMe_Dbus_static ${DBUS_LIBRARIES})
TARGET_LINK_LIBRARIES(CompoMe_Dbus_shared ${DBUS_LIBRARIES})

include("compile/import.cmake")
TARGET_INCLUDE_DIRECTORIES(CompoMe_Dbus_module PUBLIC ${_include_directories})
TARGET_INCLUDE_DIRECTORIES(CompoMe_Dbus_static PUBLIC ${_include_directories})
TARGET_INCLUDE_DIRECTORIES(CompoMe_Dbus_shared PUBLIC ${_include_directories})

include("compile/links.cmake")
TARGET_LINK_LIBRARIES(CompoMe_Dbus_module ${_links_lib})
TARGET_LINK_LIBRARIES(CompoMe_Dbus_static ${_links_lib})
TARGET_LINK_LIBRARIES(CompoMe_Dbus_shared ${_links_lib})

install(TARGETS CompoMe_Dbus_static CompoMe_Dbus_shared CompoMe_Dbus_module
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY inc/ DESTINATION inc
        FILES_MATCHING PATTERN "*.hpp")

install(FILES CompoMe_Dbus.yaml DESTINATION .)
