set(_include_directories "")

set(_include_directories ${_include_directories} "./inc")
include("./compile/file_import.cmake")

set(COMPOME_PREFIX "/home/ruhtra/compo/CompoMe")
set(_include_directories ${_include_directories} "${COMPOME_PREFIX}/inc")
include("${COMPOME_PREFIX}/compile/CompoMe_import.cmake")


set(COMPOME_PREFIX "/home/ruhtra/compo/CompoMe")
set(_include_directories ${_include_directories} "${COMPOME_PREFIX}/inc")
include("${COMPOME_PREFIX}/compile/CompoMe_Swig_import.cmake")

set(COMPOME_PREFIX "/home/ruhtra/compo/CompoMe")
set(_include_directories ${_include_directories} "${COMPOME_PREFIX}/inc")
include("${COMPOME_PREFIX}/compile/CompoMe_import.cmake")



