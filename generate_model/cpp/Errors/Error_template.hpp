#pragma once

#include <ostream>

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

{%if PARENT %}
#include "Errors/{{PARENT.NAME}}.hpp"
{%else%}
#include "Errors/Error.hpp"
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


struct {{NAME}} : public {%if PARENT %}{{PARENT.NAME}}{%else%}Error{%endif%} {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  {{value_data.TYPE.NAME}} {{value_data.NAME}};
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  {{NAME}}();

  {% if DATA.__len__() != 0 %}

  {{NAME}}({%- for value_data in DATA -%}
    {{value_data.TYPE.NAME}} p_{{value_data.NAME}}
    {%- if not loop.last -%},{%- endif -%}
    {%- endfor %}
);
  {% endif %}

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
  {%- with NAME=NAME, FUNCTION=FUNCTION, PARENT=PARENT -%}
  {%- include "Data/struct_function.hpp" with context -%}
  {%- endwith -%}

  virtual void to_stream(std::ostream&) const;
  virtual std::string what();

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const {{NAME}} &other) const;
  bool operator!=(const {{NAME}} &other) const;

  virtual void real(){
    throw *this;
  }
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const {{NAME}}& c);
std::istream& operator>>(std::istream& os,{{NAME}}& c);

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const {{NAME}}*& c);
std::istream& operator>>(std::istream& os,{{NAME}}*& c);
