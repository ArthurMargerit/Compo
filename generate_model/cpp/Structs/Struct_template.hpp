#pragma once

#include <ostream>
#include <memory>

{% if PARENT %}
#include "Structs/{{PARENT.F_NAME}}.hpp"
{% else %}
#include "Structs/Struct.hpp"
{% endif %}

// TYPES
{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
// d.D_NAME
{% if d.NATIF != True %}
#include "Types/{{d.F_NAME}}.hpp"
{% if d.POINTER == True %}
#include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}.hpp"
#include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}_fac.hpp"
{%endif%} {%endif%} {%endfor%}

// STRUCTS
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}

{% with NAMESPACE = d.NAMESPACE %} {% include "helper/namespace_open.hpp" with context %}{% endwith%}
class {{d.NAME}};
{% with NAMESPACE = d.NAMESPACE %} {% include "helper/namespace_close.hpp" with context %} {% endwith %}
#include "Structs/{{d.F_NAME}}.hpp"
{% endfor%}

struct DBusMessageIter;

{%include "helper/namespace_open.hpp" with context %}

class {{NAME}} : public {%if PARENT %}{{PARENT.D_NAME}}{%else%}CompoMe::Struct{%endif%} {
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
  {%- include "Structs/Struct_function.hpp" -%}

  // OPERATOR == and != ///////////////////////////////////////////////////////
  bool operator==(const {{D_NAME}} &other) const;
  bool operator!=(const {{D_NAME}} &other) const;

  {%include "seria/seria.hpp" with context %}

 private:
  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  {{value_data.TYPE.D_NAME}} {{value_data.NAME}};
  {%- endfor %}
};

// ///////////////////////////////////////////////////////////////////////////////
// //                               << STREAM >>                                //
// ///////////////////////////////////////////////////////////////////////////////
// // Simple
// std::ostream& operator<<(std::ostream& os, const {{NAME}}& c);
// std::istream& operator>>(std::istream& os, {{NAME}}& c);
// ///////////////////////////////////////////////////////////////////////////////
{%include "helper/namespace_close.hpp" with context %}
