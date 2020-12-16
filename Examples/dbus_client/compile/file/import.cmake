set(_include_directories "")
set(_include_directories_swig "")

list(APPEND _include_directories      "./inc")
list(APPEND _include_directories_swig "./swig")

include("./compile/file/Ext_import.cmake" OPTIONAL)
###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/CompoMe/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/CompoMe/swig")
include("/home/ruhtra/compo/CompoMe/compile/CompoMe/Ext_import.cmake" OPTIONAL)


###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/CompoMe/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/CompoMe/swig")
include("/home/ruhtra/compo/CompoMe/compile/CompoMe_Dbus/Ext_import.cmake" OPTIONAL)

###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/CompoMe/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/CompoMe/swig")
include("/home/ruhtra/compo/CompoMe/compile/CompoMe/Ext_import.cmake" OPTIONAL)



