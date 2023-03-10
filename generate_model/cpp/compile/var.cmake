set(compo_project_name "{{options.project.name}}")
set(compo_lib_name {%if options.lib and options.lib.name %}{{options.lib.name}}{%else%}"{{FILE.replace('.yaml','')}}"{%endif%})

set(src_file {{' \n'.join(Function.filter(Function.contain_f('.cpp'),generator.files))}})

set(inc_file {{' \n'.join(Function.filter(Function.contain_f('.hpp'),generator.files))}})

set(swig_file {{' \n'.join(Function.filter(Function.contain_f('.i'),generator.files))}})

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)

