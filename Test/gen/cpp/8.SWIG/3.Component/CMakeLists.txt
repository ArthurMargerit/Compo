cmake_minimum_required(VERSION 3.0)

PROJECT("compo_test")

SET(CMAKE_CXX_STANDARD 11)

FILE(GLOB_RECURSE file_compo_dep src/*/*.cpp )

add_library(_l SHARED ${file_compo_dep})
find_package(Python3 COMPONENTS Development)

FILE(GLOB_RECURSE file_i swig/*/*.cxx)
foreach(file ${file_i})
  message(${file})
  get_filename_component(plib ${file} NAME_WE)
  string(REPLACE "_wrap" "" plib ${plib})
  add_library(_${plib} MODULE ${file})

  target_include_directories(_${plib} PUBLIC "inc")
  target_include_directories(_${plib} PUBLIC ${Python3_INCLUDE_DIRS})

  target_link_libraries(_${plib} _l)

  execute_process(COMMAND ln -s lib_${plib}.so _${plib}.so)
endforeach(file)


target_include_directories(_l PUBLIC "inc")

