cmake_minimum_required(VERSION 3.10)

PROJECT("compo_test")

SET(CMAKE_CXX_STANDARD 11)


# component ###################################################################
FILE(GLOB file_compo_par LIST_DIRECTORIES false src/Components/*.cpp)
ADD_LIBRARY(Component ${file_compo_par})
TARGET_INCLUDE_DIRECTORIES(Component PUBLIC "inc" )


FILE(GLOB list_dir LIST_DIRECTORIES true src/Components/*)
foreach(dir ${list_dir})
  if(IS_DIRECTORY ${dir})
    GET_FILENAME_COMPONENT(component_name ${dir} NAME)
    FILE(GLOB_RECURSE component_files LIST_DIRECTORIES false ${dir}/*.cpp)

    ADD_LIBRARY(Component_${component_name} ${component_files})
    TARGET_INCLUDE_DIRECTORIES(Component_${component_name} PUBLIC "inc" )
  endif(IS_DIRECTORY ${dir})
endforeach(dir)

# interface ###################################################################
FILE(GLOB file_inter_par LIST_DIRECTORIES false src/Interfaces/*.cpp)
ADD_LIBRARY(Interface ${file_inter_par})
TARGET_INCLUDE_DIRECTORIES(Interface PUBLIC "inc" )

FILE(GLOB list_dir LIST_DIRECTORIES true src/Interfaces/*)

foreach(dir ${list_dir})
  if(IS_DIRECTORY ${dir})
    GET_FILENAME_COMPONENT(interface_name ${dir} NAME)
    FILE(GLOB_RECURSE interface_files LIST_DIRECTORIES false ${dir}/*.cpp)

    ADD_LIBRARY(Interface_${interface_name} ${interface_files})
    TARGET_INCLUDE_DIRECTORIES(Interface_${interface_name} PUBLIC "inc" )
  endif(IS_DIRECTORY ${dir})
endforeach(dir)

# deploiment ##################################################################
FILE(GLOB file_deploy_par LIST_DIRECTORIES false src/Deployments/*.cpp)
ADD_LIBRARY(Deployment ${file_deploy_par})
TARGET_INCLUDE_DIRECTORIES(Deployment PUBLIC "inc" )

FILE(GLOB list_dir LIST_DIRECTORIES true src/Deployments/*)

foreach(dir ${list_dir})
  if(IS_DIRECTORY ${dir})
    GET_FILENAME_COMPONENT(deploiment_name ${dir} NAME)
    FILE(GLOB_RECURSE deploiment_files LIST_DIRECTORIES false ${dir}/*.cpp)

    ADD_LIBRARY(Deployment_${deploiment_name} ${deploiment_files})
    TARGET_INCLUDE_DIRECTORIES(Deployment_${deploiment_name} PUBLIC "inc" )
  endif(IS_DIRECTORY ${dir})
endforeach(dir)

# link ##################################################################
FILE(GLOB file_link_par LIST_DIRECTORIES false src/Links/*.cpp)
ADD_LIBRARY(Link ${file_link_par})
TARGET_INCLUDE_DIRECTORIES(Link PUBLIC "inc" )

FILE(GLOB list_dir LIST_DIRECTORIES true src/Links/*)

foreach(dir ${list_dir})
  if(IS_DIRECTORY ${dir})
    GET_FILENAME_COMPONENT(link_name ${dir} NAME)
    FILE(GLOB_RECURSE link_files LIST_DIRECTORIES false ${dir}/*.cpp)

    ADD_LIBRARY(Link_${link_name} ${link_files})
    TARGET_INCLUDE_DIRECTORIES(Link_${link_name} PUBLIC "inc" )
  endif(IS_DIRECTORY ${dir})
endforeach(dir)

# linker ##################################################################
FILE(GLOB file_linker_par LIST_DIRECTORIES false src/Linkers/*.cpp)
ADD_LIBRARY(Linker ${file_linker_par})
TARGET_INCLUDE_DIRECTORIES(Linker PUBLIC "inc" )

FILE(GLOB list_dir LIST_DIRECTORIES true src/Linkers/*)

foreach(dir ${list_dir})
  if(IS_DIRECTORY ${dir})
    GET_FILENAME_COMPONENT(linker_name ${dir} NAME)
    FILE(GLOB_RECURSE linker_files LIST_DIRECTORIES false ${dir}/*.cpp)

    ADD_LIBRARY(Linker_${linker_name} ${linker_files})
    TARGET_INCLUDE_DIRECTORIES(Linker_${linker_name} PUBLIC "inc" )
  endif(IS_DIRECTORY ${dir})
endforeach(dir)

# main ##################################################################
FILE(GLOB list_dir LIST_DIRECTORIES false src/*)

foreach(dir ${list_dir})
  GET_FILENAME_COMPONENT(exec_name ${dir} NAME)
  ADD_EXECUTABLE(Exec_${exec_name} ${dir})
  TARGET_INCLUDE_DIRECTORIES(Exec_${exec_name} PUBLIC "inc")
  FIND_PACKAGE(Threads)
  message(${CMAKE_THREAD_LIBS_INIT})
  target_link_libraries(Exec_${exec_name} Link_Udp_server Link_Udp_client Deployment_Dep1 Deployment_Dep2 Component_Calc Component_Math_P Interface_Math Interface Component Link  Deployment -lboost_system ${CMAKE_THREAD_LIBS_INIT} Link_Udp_server Link_Udp_client Link)
endforeach(dir)


# ADD_EXECUTABLE(dep1 ${file_compo})

# target_include_directories(dep1 PUBLIC "inc")
# target_link_libraries(dep1 pthread)
