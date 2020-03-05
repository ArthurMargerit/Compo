#pragma once

#include <ostream>
#include <iostream>
#include <memory>
#include "Serialization_context.hpp"

{%if PARENT %}
#include "Data/Struct_{{PARENT.NAME}}.hpp"
{%else%}
#include "Data/Struct.hpp"
{%endif%}


{% set include_key = [] %}
{% for d in DATA %}
{%- if d.TYPE.NAME not in include_key -%}
{% if Function.model_test.is_struct(d.TYPE.NAME, STRUCTS) %}
#include "Data/Struct_{{d.TYPE.NAME}}.hpp"
{% set _ = include_key.append(d.TYPE.NAME) -%}
{% elif d.TYPE.NATIF != true   %}
#include "Data/Type_{{d.TYPE.NAME}}.hpp"
{%if d.TYPE.POINTER == true%}
#include "Data/Struct_{{d.TYPE.POINTER_OF}}.hpp"
#include "Data/Struct_fac_{{d.TYPE.POINTER_OF}}.hpp"
{% endif %}
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
  {{value_data.TYPE.NAME}} & a_{{value_data.NAME}}();
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////
  {%- include "Data/struct_function.hpp" -%}

  //virtual void to_stream(std::ostream& d = std::cout)  const override;
  virtual std::string to_string() const override;

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const {{NAME}} &other) const;
  bool operator!=(const {{NAME}} &other) const;

  std::ostream& to_stream(std::ostream& os, Serialization_context& p_ctx) const override;
  std::istream& from_stream(std::istream& is, Serialization_context& p_ctx) override;
};


///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////

// Simple
std::ostream& operator<<(std::ostream& os, const {{NAME}}& c);
std::istream& operator>>(std::istream& os, {{NAME}}& c);
// Pointer
std::istream& operator>>(std::istream& is, {{NAME}} *&c);
std::ostream& operator<<(std::ostream& os, const {{NAME}} *c);
// SmartPointer
std::istream& operator>>(std::istream& is, std::shared_ptr<{{NAME}}> &c);
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<{{NAME}}> &c);
///////////////////////////////////////////////////////////////////////////////
