set(_links_lib "")
include("./compile/CompoMe_Async_links.cmake")

set(_links_lib ${_links_lib} "-L/home/ruhtra/compo/CompoMe/lib" "libCompoMe_static.a")
include("/home/ruhtra/compo/CompoMe/compile/CompoMe_links.cmake")


