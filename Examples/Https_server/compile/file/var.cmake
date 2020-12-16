set(compo_project_name "Https_server")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Interfaces/Information_I/Information_I.cpp 
src/Interfaces/Thermal_Sensor_I/Thermal_Sensor_I.cpp 
src/Interfaces/Information_I/Information_I_fake_stream.cpp 
src/Interfaces/Thermal_Sensor_I/Thermal_Sensor_I_fake_stream.cpp 
src/Interfaces/Information_I/Information_I_caller_stream.cpp 
src/Interfaces/Thermal_Sensor_I/Thermal_Sensor_I_caller_stream.cpp 
src/Components/Sensor.cpp 
src/Components/Sensor_serialization.cpp 
src/Components/Sensor_function.cpp 
src/Components/Sensor_get_set.cpp 
src/Components/Sensor_fac.cpp 
src/Components/Sensor_Information_I_information.cpp 
src/Components/Sensor_Thermal_Sensor_I_capteur1.cpp 
src/Components/Sensor_Information_I_information_get_set.cpp 
src/Components/Sensor_Thermal_Sensor_I_capteur1_get_set.cpp 
src/Components/Sensor_Information_I_information_fac.cpp 
src/Components/Sensor_Thermal_Sensor_I_capteur1_fac.cpp 
src/Components/Sensor_Information_I_information_function.cpp 
src/Components/Sensor_Thermal_Sensor_I_capteur1_function.cpp 
src/Deployments/Dep_on_kitchen/Dep_on_kitchen.cpp 
src/Deployments/Dep_on_kitchen/Dep_on_kitchen_get_set.cpp)

set(inc_file inc/Data/file.hpp 
inc/Interfaces/Information_I/Information_I.hpp 
inc/Interfaces/Thermal_Sensor_I/Thermal_Sensor_I.hpp 
inc/Interfaces/Information_I/Information_I_fake_stream.hpp 
inc/Interfaces/Thermal_Sensor_I/Thermal_Sensor_I_fake_stream.hpp 
inc/Interfaces/Information_I/Information_I_caller_stream.hpp 
inc/Interfaces/Thermal_Sensor_I/Thermal_Sensor_I_caller_stream.hpp 
inc/Components/Sensor.hpp 
inc/Components/Sensor_fac.hpp 
inc/Components/Sensor_Information_I_information.hpp 
inc/Components/Sensor_Thermal_Sensor_I_capteur1.hpp 
inc/Deployments/Dep_on_kitchen/Dep_on_kitchen.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
