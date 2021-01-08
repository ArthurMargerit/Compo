LIST(APPEND inc_file "inc/Types/CompoMe/String_d.hpp")
LIST(APPEND src_file "src/Types/CompoMe/String_d.cpp")

FILE(GLOB_RECURSE src_file_component "src/Components/CompoMe/Component_Core*.cpp" )

LIST(APPEND src_file ${src_file_component})
