#pragma once

#include <ostream>

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

{%if PARENT %}
#include "Errors/{{PARENT.D_NAME.replace('::','/')}}.hpp"
{%else%}
#include "Errors/Error.hpp"
{%endif%}

{% set include_key = [] %}
{% for d in DATA %}
{% if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
{%- if d.TYPE.D_NAME not in include_key -%}
#include "Data/{{d.TYPE.D_NAME.replace('::','/')}}.hpp"
{% set _ = include_key.append(d.TYPE.D_NAME) -%}
{% endif %}
{% endif %}
{% endfor %}

{% include "helper/namespace_open.hpp" with context %}

class {{NAME}} : public {%if PARENT %}{{PARENT.D_NAME}}{%else%}Error{%endif%} {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
 private:
  {%- for value_data in DATA %}
  {{value_data.TYPE.D_NAME}} {{value_data.NAME}};
  {%- endfor %}

 public:
  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  {{NAME}}();
  virtual ~{{NAME}}();

  // {% if DATA.__len__() != 0 %}
  // {{NAME}}({%- for value_data in DATA -%}
  //   {{value_data.TYPE.D_NAME}} p_{{value_data.NAME}}
  //   {%- if not loop.last -%},{%- endif -%}
  //   {%- endfor %});
  // {% endif %}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  {{value_data.TYPE.D_NAME}} get_{{value_data.NAME}}() const;
  void set_{{value_data.NAME}}(const {{value_data.TYPE.D_NAME}}&);

  {%- endfor %}


  /////////////////////////////////////////////////////////////////////////////
  //                               FUNCTION                                  //
  /////////////////////////////////////////////////////////////////////////////
  {%- with NAME=NAME, FUNCTION=FUNCTION, PARENT=PARENT -%}
  {%- include "Data/struct_function.hpp" with context -%}
  {%- endwith -%}

  std::string what() override;
  void real() override;

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const {{D_NAME}} &other) const;
  bool operator!=(const {{D_NAME}} &other) const;

  std::ostream &to_stream(std::ostream &,
                                  Serialization_context_export &) const override;
  std::istream &from_stream(std::istream &is,
                                    Serialization_context_import &p_ctx) override;


};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const {{D_NAME}}& c);
std::istream& operator>>(std::istream& os,{{D_NAME}}& c);

{%include "helper/namespace_close.hpp" with context%}
