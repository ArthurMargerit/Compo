set(_include_directories "")
set(_include_directories_swig "")

list(APPEND _include_directories      "./inc")
list(APPEND _include_directories_swig "./swig")

include("./compile/file/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/build/CompoMe_Tools/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/build/CompoMe_Tools/swig")
include("/home/ruhtra/compo/build/CompoMe_Tools/compile/CompoMe_Tools/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/build/CompoMe/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/build/CompoMe/swig")
include("/home/ruhtra/compo/build/CompoMe/compile/CompoMe/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/build/CompoMe_Log/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/build/CompoMe_Log/swig")
include("/home/ruhtra/compo/build/CompoMe_Log/compile/CompoMe_Log/Ext_import.cmake" OPTIONAL)





###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/build/CompoMe_Swig/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/build/CompoMe_Swig/swig")
include("/home/ruhtra/compo/build/CompoMe_Swig/compile/CompoMe_Swig/Ext_import.cmake" OPTIONAL)



