
include("compile/A/main.cmake")
include("compile/B/main.cmake")
include("compile/C/main.cmake")

file(GLOB_RECURSE file_compo src/main.cpp)
set( _links_lib A B C code CompoMe CompoMe_Log)