set(compo_project_name "CompoMe_esp32")
set(compo_lib_name "CompoMe_esp32")

set(src_file src/Types/Embded/IO/Pin_State.cpp 
src/Data/CompoMe_esp32.cpp 
src/Events/Embded/IO/Pin_change.cpp 
src/Events/Embded/IO/Pin_change_serialization.cpp 
src/Events/Embded/IO/Pin_change_get_set.cpp 
src/Events/Embded/IO/Pin_change_function.cpp 
src/Events/Embded/IO/Pin_change_fac.cpp 
src/Interfaces/Embded/IO/Pin_out/Pin_out.cpp 
src/Interfaces/Embded/IO/Pin_in/Pin_in.cpp 
src/Interfaces/Embded/IO/Pin_out/Pin_out_fake_stream.cpp 
src/Interfaces/Embded/IO/Pin_in/Pin_in_fake_stream.cpp 
src/Interfaces/Embded/IO/Pin_out/Pin_out_caller_stream.cpp 
src/Interfaces/Embded/IO/Pin_in/Pin_in_caller_stream.cpp 
src/Components/Embded/IO/esp32/Control_output.cpp 
src/Components/Embded/IO/esp32/Control_output_serialization.cpp 
src/Components/Embded/IO/esp32/Control_input.cpp 
src/Components/Embded/IO/esp32/Control_input_serialization.cpp 
src/Components/Embded/IO/esp32/Control_output_function.cpp 
src/Components/Embded/IO/esp32/Control_input_function.cpp 
src/Components/Embded/IO/esp32/Control_output_get_set.cpp 
src/Components/Embded/IO/esp32/Control_input_get_set.cpp 
src/Components/Embded/IO/esp32/Control_output_fac.cpp 
src/Components/Embded/IO/esp32/Control_input_fac.cpp 
src/Components/Embded/IO/esp32/Control_output_Pin_out_control.cpp 
src/Components/Embded/IO/esp32/Control_input_Pin_in_control.cpp 
src/Components/Embded/IO/esp32/Control_output_Pin_out_control_get_set.cpp 
src/Components/Embded/IO/esp32/Control_input_Pin_in_control_get_set.cpp 
src/Components/Embded/IO/esp32/Control_output_Pin_out_control_fac.cpp 
src/Components/Embded/IO/esp32/Control_input_Pin_in_control_fac.cpp 
src/Components/Embded/IO/esp32/Control_output_Pin_out_control_function.cpp 
src/Components/Embded/IO/esp32/Control_input_Pin_in_control_function.cpp)

set(inc_file inc/Types/Embded/IO/Pin_State.hpp 
inc/Data/CompoMe_esp32.hpp 
inc/Events/Embded/IO/Pin_change.hpp 
inc/Events/Embded/IO/Pin_change_fac.hpp 
inc/Interfaces/Embded/IO/Pin_out/Pin_out.hpp 
inc/Interfaces/Embded/IO/Pin_in/Pin_in.hpp 
inc/Interfaces/Embded/IO/Pin_out/Pin_out_fake_stream.hpp 
inc/Interfaces/Embded/IO/Pin_in/Pin_in_fake_stream.hpp 
inc/Interfaces/Embded/IO/Pin_out/Pin_out_caller_stream.hpp 
inc/Interfaces/Embded/IO/Pin_in/Pin_in_caller_stream.hpp 
inc/Components/Embded/IO/esp32/Control_output.hpp 
inc/Components/Embded/IO/esp32/Control_input.hpp 
inc/Components/Embded/IO/esp32/Control_output_fac.hpp 
inc/Components/Embded/IO/esp32/Control_input_fac.hpp 
inc/Components/Embded/IO/esp32/Control_output_Pin_out_control.hpp 
inc/Components/Embded/IO/esp32/Control_input_Pin_in_control.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
