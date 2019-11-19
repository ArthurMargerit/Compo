#pragma once

#include <ostream>
#include <iostream>
#include "Data/{{FILE.replace('.yaml','')}}.hpp"

{%if PARENT %}
#include "Data/Struct_{{PARENT.NAME}}.hpp"
{%else%}
#include "Data/Struct.hpp"
{%endif%}


{% set include_key = [] %}
{% for d in DATA %}
{% if Function.model_test.is_struct(d["TYPE"]["NAME"], STRUCTS) %}
{%- if d["TYPE"]["NAME"] not in include_key -%}
#include "Data/Struct_{{d["TYPE"]["NAME"]}}.hpp"
{% set _ = include_key.append(d["TYPE"]["NAME"]) -%}
{% endif %}
{% endif %}
{% endfor %}

struct {{NAME}} : public {%if PARENT %}{{PARENT.NAME}}{%else%}Struct{%endif%} {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  {{value_data.TYPE.NAME}} {{value_data.NAME}} ;
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  {% set d =  Function.model_get.get_all_field(DATA, PARENT, Function.model_get.remove_default) %}

  {% if d.__len__() %}
  {{NAME}}();
  {% endif %}

  virtual ~{{NAME}}();

  {{NAME}}({%- for value_data in Function.model_get.get_all_field(DATA, PARENT) -%}
    {{value_data.TYPE.NAME}} p_{{value_data.NAME}} {%if "DEFAULT" in value_data%} = {{value_data.DEFAULT}}{% endif %}
    {%- if not loop.last -%}, {%- endif -%}
    {%- endfor %});

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  {{value_data.TYPE.NAME}} get_{{value_data.NAME}}() const;
  void set_{{value_data.NAME}}(const {{value_data.TYPE.NAME}}&);
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////
  {%- include "Data/struct_function.hpp" -%}

  virtual void to_stream(std::ostream& d = std::cout)  const override;
  virtual std::string to_string() const override;

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const {{NAME}} &other) const;
  bool operator!=(const {{NAME}} &other) const;
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const {{NAME}}& c);
std::istream& operator>>(std::istream& os,{{NAME}}& c);
