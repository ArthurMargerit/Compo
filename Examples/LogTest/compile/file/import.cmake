set(_include_directories "")
set(_include_directories_swig "")

list(APPEND _include_directories      "./inc")
list(APPEND _include_directories_swig "./swig")

include("./compile/file/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Udp/inc")
list(APPEND _include_directories_swig "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Udp/swig")
include("/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Udp/compile/CompoMe_Udp/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe/inc")
list(APPEND _include_directories_swig "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe/swig")
include("/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe/compile/CompoMe/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Log/inc")
list(APPEND _include_directories_swig "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Log/swig")
include("/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Log/compile/CompoMe_Log/Ext_import.cmake" OPTIONAL)





###############################################################################
list(APPEND _include_directories      "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Port/inc")
list(APPEND _include_directories_swig "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Port/swig")
include("/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Port/compile/CompoMe_Port/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Tools/inc")
list(APPEND _include_directories_swig "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Tools/swig")
include("/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Tools/compile/CompoMe_Tools/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Swig/inc")
list(APPEND _include_directories_swig "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Swig/swig")
include("/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Swig/compile/CompoMe_Swig/Ext_import.cmake" OPTIONAL)







###############################################################################
list(APPEND _include_directories      "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Json/inc")
list(APPEND _include_directories_swig "/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Json/swig")
include("/home/ruhtra/correction_speed/OMEGA_Embedded_sw/build_t/compo/CompoMe_Json/compile/CompoMe_Json/Ext_import.cmake" OPTIONAL)


