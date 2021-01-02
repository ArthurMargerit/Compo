cmake_minimum_required(VERSION 3.0)
PROJECT(Code_test)
include("compile/code/main.cmake")

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
SET(CMAKE_EXE_LINKER_FLAGS
   "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,. -Wl,-rpath -Wl,lib -Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")

# option(COMPOME_LOG_D "ACTIVATE/DESACTIVATE log system")
# add_compile_definitions(COMPOME_LOG=${COMPOME_LOG_D})

include("Perso.cmake" OPTIONAL)

add_executable(dep1 ${file_compo})
target_compile_options(dep1 PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-unused-variable -Wno-unused-private-field -Wno-string-plus-int)
target_include_directories(dep1 PUBLIC ${_include_directories})
target_link_libraries(dep1 ${_links_dir} ${_links_lib} ${_links_lib} ${compo_lib_name})
