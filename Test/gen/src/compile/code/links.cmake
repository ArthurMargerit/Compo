set(_links_lib "")

include("${CMAKE_CURRENT_LIST_DIR}/Ext_links.cmake" OPTIONAL)



list(APPEND _links_dir "-L/home/ruhtra/compo/build/CompoMe_Test/lib")
list(APPEND _links_lib "CompoMe_Test")
include("/home/ruhtra/compo/build/CompoMe_Test/compile/CompoMe_Test/Ext_links.cmake" OPTIONAL)




list(APPEND _links_dir "-L/home/ruhtra/compo/build/CompoMe/lib")
list(APPEND _links_lib "CompoMe")
include("/home/ruhtra/compo/build/CompoMe/compile/CompoMe/Ext_links.cmake" OPTIONAL)



list(APPEND _links_dir "-L/home/ruhtra/compo/build/CompoMe_Log/lib")
list(APPEND _links_lib "CompoMe_Log")
include("/home/ruhtra/compo/build/CompoMe_Log/compile/CompoMe_Log/Ext_links.cmake" OPTIONAL)



