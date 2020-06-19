#pragma once

#include <ostream>
#include <iostream>
#include <memory>

{%if PARENT %}
#include "Data/{{PARENT.F_NAME}}.hpp"
{%else%}
#include "Data/Struct.hpp"
{%endif%}

{% set include_key = [] %}
{% for d in DATA %}
{%- if d.TYPE.D_NAME not in include_key -%}
{% if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
#include "Data/{{d.TYPE.F_NAME}}.hpp"
{% set _ = include_key.append(d.TYPE.D_NAME) -%}
{% elif d.TYPE.NATIF != true   %}
#include "Data/{{d.TYPE.F_NAME}}.hpp"
{%if d.TYPE.POINTER == true%}
#include "Data/{{d.TYPE.NAMESPACE.replace('::','/')}}/{{d.TYPE.POINTER_OF}}.hpp"
#include "Data/{{d.TYPE.NAMESPACE.replace('::','/')}}/{{d.TYPE.POINTER_OF}}_fac.hpp"
{% endif %}
{% endif %}
{% endif %}
{% endfor %}

{%include "helper/namespace_open.hpp" with context %}

class {{NAME}} : public {%if PARENT %}{{PARENT.D_NAME}}{%else%}Struct{%endif%} {
 public:

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  {% set d =  Function.model_get.get_all_field(DATA, PARENT, Function.model_get.remove_default) %}

  {% if d.__len__() %}
  {{NAME}}();
  {% endif %}

  virtual ~{{NAME}}();

  {{NAME}}({%- for value_data in Function.model_get.get_all_field(DATA, PARENT) -%}
    {{value_data.TYPE.D_NAME}} p_{{value_data.NAME}} {%if "DEFAULT" in value_data%} = {{value_data.DEFAULT}}{% endif %}
    {%- if not loop.last -%}, {%- endif -%}
    {%- endfor %});

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  {{value_data.TYPE.D_NAME}} get_{{value_data.NAME}}() const;
  void set_{{value_data.NAME}}(const {{value_data.TYPE.D_NAME}}&);
  {{value_data.TYPE.D_NAME}} & a_{{value_data.NAME}}();
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////
  {%- include "Data/struct_function.hpp" -%}

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const {{D_NAME}} &other) const;
  bool operator!=(const {{D_NAME}} &other) const;

  std::ostream& to_stream(std::ostream& os, Serialization_context_export& p_ctx) const override;
  std::istream& from_stream(std::istream& is, Serialization_context_import& p_ctx) override;
  {% if EXTRA %}
  void extra_export(std::ostream& os, Serialization_context_export& p_ctx) const;
  void extra_import(std::istream& is, Serialization_context_import& p_ctx);
  {% endif %}
  
 private:
  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  {{value_data.TYPE.D_NAME}} {{value_data.NAME}};
  {%- endfor %}

};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
// Simple
std::ostream& operator<<(std::ostream& os, const {{NAME}}& c);
std::istream& operator>>(std::istream& os, {{NAME}}& c);
///////////////////////////////////////////////////////////////////////////////
{%include "helper/namespace_close.hpp" with context %}
