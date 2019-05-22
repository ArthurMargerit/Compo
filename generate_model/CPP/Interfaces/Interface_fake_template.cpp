#include "Interfaces/{{NAME}}/{{NAME}}_fake.hpp"


 {{NAME}}_fake::{{NAME}}_fake(Function_stream& out, Return_stream& in):
 {%if PARENT%}{{PARENT.NAME}}_fake(out,in){%else%}Fake(),o(out),i(in){%endif%}
 {

 }


 {{NAME}}_fake::~{{NAME}}_fake() noexcept{}

///////////////////////////////////////////////////////////////////////////////
//                                  FUNCTION                                 //
///////////////////////////////////////////////////////////////////////////////
{% set FUNC_GENERATED=[] %}

{% if PARENT %}
{%- with START=NAME, INTERFACE=PARENT, FUNC_GENERATED=FUNC_GENERATED-%}
{%- include "helper/fake_func_mapping.cpp" with context -%}
{%- endwith -%}
{% endif %}

// INTERFACE Function {{NAME}} ////////////////////////////////////////////////
{%- for f in FUNCTION %}
{% if f.NAME not in  FUNC_GENERATED %}
{%set _ = FUNC_GENERATED.append(f.NAME) %}
  {{ f["RETURN"]["NAME"] }} {{ NAME }}_fake::{{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )
  {
    o.start();
    o << "{{f["NAME"]}}("
      {% for a in f["SIGNATURE"] %}
    << {{a["NAME"] }}
    {%- if not loop.last%}
    << ","
         {% endif %}
    {%endfor%}
    << ")";
    o.call();

    i.pull();
    {% if f["RETURN"]["NAME"] != "void" %}
    {{f["RETURN"]["NAME"]}} ri;
    i >> ri;
    i.end();
    return ri;
    {% endif %}
  }
{% endif %}
{%- endfor %}

///////////////////////////////////////////////////////////////////////////////
//                                    DATA                                   //
///////////////////////////////////////////////////////////////////////////////
  {%set DATA_GENERATED = [] %}
  {%if PARENT%}
  {%- with START=NAME, INTERFACE=PARENT, DATA_GENERATED=DATA_GENERATED-%}
  {%- include "helper/fake_getset_mapping.cpp" with context -%}
  {%- endwith -%}
  {%endif%}

// INTERFACE get/set {{NAME}} /////////////////////////////////////////////////
  {%- for v in DATA %}
  {{v["TYPE"]["NAME"]}} {{NAME}}_fake::get_{{v["NAME"]}}() const {
    o.start();
    o << "get_{{v["NAME"]}}()" ;
    o.call();

    i.pull();
    {{v["TYPE"]["NAME"]}} ret;
    i >> ret;
    i.end();

    return ret;
}

void
{{ NAME }}_fake::set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}}) {

  o << "set_{{v["NAME"]}}("
    << {{v["NAME"]}}
  << ")";

  std::string empty;
  std::getline(i, empty);
  return;
}
  {%- endfor %}
