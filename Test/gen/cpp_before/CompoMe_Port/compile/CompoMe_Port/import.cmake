set(_include_directories "")
set(_include_directories_swig "")

list(APPEND _include_directories      "./inc")
list(APPEND _include_directories_swig "./swig")

include("./compile/CompoMe_Port/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/build/CompoMe/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/build/CompoMe/swig")
include("/home/ruhtra/compo/build/CompoMe/compile/CompoMe/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/build/CompoMe_Log/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/build/CompoMe_Log/swig")
include("/home/ruhtra/compo/build/CompoMe_Log/compile/CompoMe_Log/Ext_import.cmake" OPTIONAL)



