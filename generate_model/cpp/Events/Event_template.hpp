#pragma once

{%if PARENT %}
#include "Events/{{PARENT.F_NAME}}.hpp"
{%else%}
#include "Events/Event.hpp"
{%endif%}

// TYPES
{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
{% if d.NATIF != true %}
#include "Types/{{d.F_NAME}}.hpp"
{%if d.POINTER == true%}
#include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}.hpp"
#include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}_fac.hpp"
{% endif -%}
{% endif -%}
{% endfor -%}

// STRUCTS
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
#include "Structs/{{d.F_NAME}}.hpp"
{% endfor%}

namespace DBus{
  class MessageIterator;
  class MessageAppendIterator;
}

{%include "helper/namespace_open.hpp" with context %}

class {{NAME}} : public {%if PARENT %}{{PARENT.D_NAME}}{%else%}CompoMe::Event{%endif%} {
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

  void to_stream(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const override;
  void from_stream(std::istream& is, CompoMe::Serialization_context_import& p_ctx) override;

  {%if OPTIONS and OPTIONS.DBUS%}
  void to_stream(DBusMessageIter&, CompoMe::Serialization_context_export&) const override;
  void from_stream(DBusMessageIter&, CompoMe::Serialization_context_import&) override;
  {% endif %}

  {% if EXTRA %}
  void extra_export(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const;
  void extra_import(std::istream& is, CompoMe::Serialization_context_import& p_ctx);
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
