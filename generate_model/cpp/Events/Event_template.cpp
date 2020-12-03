#include "Events/{{F_NAME}}.hpp"

#include <ostream>
#include <istream>
#include <sstream>

{%include "helper/namespace_open.hpp" with context %}

{% set d =  Function.model_get.get_all_field(DATA, PARENT, Function.model_get.remove_default) %}
{% if d.__len__() %}
{{NAME}}::{{NAME}}():{{NAME}}({% for i_d in d %}{{Function.model_get.get_data_default(i_d).replace("=","")}}{%if not loop.last %},{%endif%}{%endfor%}){}
{% endif %}

{{NAME}}::{{NAME}}(
  {%- for value_data in Function.model_get.get_all_field(DATA, PARENT) -%}
  {{value_data.TYPE.D_NAME}} p_{{value_data.NAME}}
  {%- if not loop.last -%}
  ,
  {%- endif -%}
  {%- endfor %})
:{% if PARENT %}{{PARENT.D_NAME}}(){%else%}CompoMe::Event(){%endif%}
  {%- for value_data in DATA %}
                                             ,{{value_data.NAME}}(p_{{value_data.NAME}})
                                             {% endfor %} {
  }

{{NAME}}::~{{NAME}}(){}

{%include "helper/namespace_close.hpp" with context %}


