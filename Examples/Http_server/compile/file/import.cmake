set(_include_directories "")
set(_include_directories_swig "")

list(APPEND _include_directories      "./inc")
list(APPEND _include_directories_swig "./swig")

include("./compile/file/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo_inst/CompoMe_Http/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo_inst/CompoMe_Http/swig")
include("/home/ruhtra/compo_inst/CompoMe_Http/compile/CompoMe_Http/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo_inst/CompoMe/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo_inst/CompoMe/swig")
include("/home/ruhtra/compo_inst/CompoMe/compile/CompoMe/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo_inst/CompoMe_Log/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo_inst/CompoMe_Log/swig")
include("/home/ruhtra/compo_inst/CompoMe_Log/compile/CompoMe_Log/Ext_import.cmake" OPTIONAL)





###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo_inst/CompoMe_Tools/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo_inst/CompoMe_Tools/swig")
include("/home/ruhtra/compo_inst/CompoMe_Tools/compile/CompoMe_Tools/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo_inst/CompoMe_Swig/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo_inst/CompoMe_Swig/swig")
include("/home/ruhtra/compo_inst/CompoMe_Swig/compile/CompoMe_Swig/Ext_import.cmake" OPTIONAL)





###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo_inst/CompoMe_Port/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo_inst/CompoMe_Port/swig")
include("/home/ruhtra/compo_inst/CompoMe_Port/compile/CompoMe_Port/Ext_import.cmake" OPTIONAL)



