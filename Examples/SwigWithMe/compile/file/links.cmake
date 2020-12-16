set(_links_lib "")
include("${CMAKE_CURRENT_LIST_DIR}/Ext_links.cmake" OPTIONAL)

list(APPEND _links_lib "-L/home/ruhtra/compo/CompoMe/lib" "CompoMe")
include("/home/ruhtra/compo/CompoMe/compile/CompoMe/Ext_links.cmake" OPTIONAL)


list(APPEND _links_lib "-L/home/ruhtra/compo/CompoMe/lib" "CompoMe_Swig")
include("/home/ruhtra/compo/CompoMe/compile/CompoMe_Swig/Ext_links.cmake" OPTIONAL)

list(APPEND _links_lib "-L/home/ruhtra/compo/CompoMe/lib" "CompoMe")
include("/home/ruhtra/compo/CompoMe/compile/CompoMe/Ext_links.cmake" OPTIONAL)



