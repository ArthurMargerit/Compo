set(compo_project_name "{{options.project.name}}")
set(compo_lib_name "{{FILE.replace('.yaml','')}}")

set(src_file {{' \n'.join(Function.filter(Function.contain_f('.cpp'),generator.files))}})

set(inc_file {{' \n'.join(Function.filter(Function.contain_f('.hpp'),generator.files))}})

set(swig_file {{' \n'.join(Function.filter(Function.contain_f('.swig'),generator.files))}})

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)

