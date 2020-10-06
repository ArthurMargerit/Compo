cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

include("compile/var.cmake")
project("compo_test")
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
SET(CMAKE_EXE_LINKER_FLAGS
  "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,. -Wl,-rpath -Wl,lib -Wl,-rpath -Wl,${CMAKE_INSTALL_PREFIX}/lib")

option(COMPOME_LOG_D "ACTIVATE/DESACTIVATE log system")
add_compile_definitions(COMPOME_LOG=${COMPOME_LOG_D})

file(GLOB_RECURSE file_compo src/*.cpp)

add_executable(dep1 ${file_compo})
target_compile_options(dep1 PRIVATE -Wall -Wextra -pedantic -Wno-unused-parameter -Wno-unused-variable -Wno-unused-private-field -Wno-string-plus-int)

include("compile/import.cmake")
target_include_directories(dep1 PUBLIC ${_include_directories})

include("compile/links.cmake")
target_link_libraries(dep1 ${_links_lib})

include("CompoMe_Swig.cmake")
