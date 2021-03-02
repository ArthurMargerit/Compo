set(compo_project_name "Car")
set(compo_lib_name "file")

set(src_file src/Data/file.cpp 
src/Interfaces/Car/Gate/Locker/Locker.cpp 
src/Interfaces/Car/Gate/Window/Window.cpp 
src/Interfaces/Car/Reporter/Reporter.cpp 
src/Interfaces/Car/Gate/Locker/Locker_fake_stream.cpp 
src/Interfaces/Car/Gate/Window/Window_fake_stream.cpp 
src/Interfaces/Car/Reporter/Reporter_fake_stream.cpp 
src/Interfaces/Car/Gate/Locker/Locker_caller_stream.cpp 
src/Interfaces/Car/Gate/Window/Window_caller_stream.cpp 
src/Interfaces/Car/Reporter/Reporter_caller_stream.cpp 
src/Components/Car/Gates/controller.cpp 
src/Components/Car/Gates/controller_serialization.cpp 
src/Components/Car/Gates/controller_function.cpp 
src/Components/Car/Gates/controller_get_set.cpp 
src/Components/Car/Gates/controller_fac.cpp 
src/Components/Car/Gates/controller_Window_win.cpp 
src/Components/Car/Gates/controller_Locker_locker.cpp 
src/Components/Car/Gates/controller_Window_win_get_set.cpp 
src/Components/Car/Gates/controller_Locker_locker_get_set.cpp 
src/Components/Car/Gates/controller_Window_win_fac.cpp 
src/Components/Car/Gates/controller_Locker_locker_fac.cpp 
src/Components/Car/Gates/controller_Window_win_function.cpp 
src/Components/Car/Gates/controller_Locker_locker_function.cpp)

set(inc_file inc/Data/file.hpp 
inc/Data/file_template.hpp 
inc/Interfaces/Car/Gate/Locker/Locker.hpp 
inc/Interfaces/Car/Gate/Window/Window.hpp 
inc/Interfaces/Car/Reporter/Reporter.hpp 
inc/Interfaces/Car/Gate/Locker/Locker_fake_stream.hpp 
inc/Interfaces/Car/Gate/Window/Window_fake_stream.hpp 
inc/Interfaces/Car/Reporter/Reporter_fake_stream.hpp 
inc/Interfaces/Car/Gate/Locker/Locker_caller_stream.hpp 
inc/Interfaces/Car/Gate/Window/Window_caller_stream.hpp 
inc/Interfaces/Car/Reporter/Reporter_caller_stream.hpp 
inc/Components/Car/Gates/controller.hpp 
inc/Components/Car/Gates/controller_fac.hpp 
inc/Components/Car/Gates/controller_Window_win.hpp 
inc/Components/Car/Gates/controller_Locker_locker.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
