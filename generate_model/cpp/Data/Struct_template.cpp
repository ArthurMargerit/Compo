#include "Data/{{NAMESPACE.replace('::','/')}}/Struct_{{NAME}}.hpp"
#include "Data/{{NAMESPACE.replace('::','/')}}/Struct_fac_{{NAME}}.hpp"
#include <iostream>
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

// GET SET ////////////////////////////////////////////////////////////////////
{%- for d in DATA %}
// get/set {{d.NAME}}
{{d.TYPE.D_NAME}} {{NAME}}::get_{{d.NAME}}() const {
    return this->{{d.NAME}};
}

void {{NAME}}::set_{{d.NAME}}(const {{d.TYPE.D_NAME}}& p_{{d.NAME}}) {
  this->{{d.NAME}} = p_{{d.NAME}};
}

{{d.TYPE.D_NAME}} & {{NAME}}::a_{{d.NAME}}() {
  return this->{{d.NAME}};
}
{%- endfor %}

// FUNCTION ///////////////////////////////////////////////////////////////////
{%- include "Data/struct_function.cpp" with context -%}

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool {{NAME}}::operator==(const {{NAME}} &other) const {
  return {%if PARENT%}
  {{PARENT.NAME}}::operator==(other) {# ask you parent !!! #}
  {%else%}
  true {# by default #}
  {%endif%}
  {%for l_d in DATA%}
  && this->{{l_d.NAME}} == other.{{l_d.NAME}}
  {%endfor%};
}

bool {{NAME}}::operator!=(const {{NAME}} &other) const {
  return !(*this == other); {# reverse of == #}
}

std::string {{NAME}}::to_string() const {
  std::stringstream ss;
  ss << *this;
  return std::string(ss.str());
}

{%include "helper/namespace_close.hpp" with context %}
