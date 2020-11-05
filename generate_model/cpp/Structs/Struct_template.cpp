#include "Structs/{{F_NAME}}.hpp"
#include "Structs/{{F_NAME}}_fac.hpp"

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
  :{% if PARENT %}{{PARENT.D_NAME}}(){%else%}Struct(){%endif%}
  {%- for value_data in DATA %}
     ,{{value_data.NAME}}(p_{{value_data.NAME}})
  {% endfor %} {
}

{{NAME}}::~{{NAME}}(){}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool {{NAME}}::operator==(const {{D_NAME}} &other) const {
  return {%if PARENT%}
  {{PARENT.D_NAME}}::operator==(other) {# ask you parent !!! #}
  {%else%}
  true {# by default #}
  {%endif%}
  {%for l_d in DATA%}
  && this->{{l_d.NAME}} == other.{{l_d.NAME}}
  {%endfor%};
}

bool {{NAME}}::operator!=(const {{D_NAME}} &other) const {
  return !(*this == other); {# reverse of == #}
}

{%include "helper/namespace_close.hpp" with context %}
