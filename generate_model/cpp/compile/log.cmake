

include(CMakeDependentOption)

option(CompoMe_Log_{{FILE.replace(".yaml","")}} "CompoMe Log System for {{FILE}}" 0)

{%for a in Function.filter(Function.contain_f('.cpp'), generator.files) %}
## {{a}} ##
set({{a}}_log_act 0)
set({{a}}_log_output _log_output)
{%endfor%}

include(${CMAKE_CURRENT_LIST_DIR}/Int_log.cmake OPTIONAL)