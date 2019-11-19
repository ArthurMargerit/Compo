#include "Interfaces/{{NAME}}/{{NAME}}_fake.hpp"
#include "Errors/Error.hpp"

{{NAME}}_fake::{{NAME}}_fake(Function_stream& out, Return_stream& in):
{%if PARENT%}{{PARENT.NAME}}_fake(out,in){%else%}Fake(out,in){%endif%} {

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
  {{ f.RETURN.NAME }} {{ NAME }}_fake::{{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )
  {
    this->get_o().start();
    this->get_o() << "{{f.NAME}}("
      {% for a in f.SIGNATURE %}
    << {{a.NAME }}
    {%- if not loop.last%}
    << ","
         {% endif %}
    {%endfor%}
    << ")";
    this->get_o().call();

    this->get_i().pull();
    {% if f.RETURN.NAME != "void" %}
    {{f.RETURN.NAME}} ri = {{f.RETURN.NAME}}{%if f.RETURN.DEFAULT %} ({{f.RETURN.DEFAULT}}){%else%}(){%endif%};

    if(this->get_i().get_si()->peek() == '!') {
      this->get_i().get_si()->get();
      std::shared_ptr<Error> l_e;
      this->get_i() >> l_e;
      l_e->real();
    } else {
      this->get_i() >> ri;
    }

    this->get_i().end();
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
  {{v.TYPE.NAME}} {{NAME}}_fake::get_{{v.NAME}}() const {
    this->get_o().start();
    this->get_o() << "get_{{v.NAME}}()" ;
    this->get_o().call();

    this->get_i().pull();
    if(this->get_i().get_si()->peek() == '!'){
      this->get_i().get_si()->get();
      std::shared_ptr<Error> l_e;
      this->get_i() >> l_e;
      l_e->real();
    }

    {{v.TYPE.NAME}} ret;
    this->get_i() >> ret;
    this->get_i().end();

    return ret;
}

void
{{ NAME }}_fake::set_{{v.NAME}}(const {{v.TYPE.NAME}}& {{v.NAME}}) {
  this->get_o().start();
  this->get_o() << "set_{{v.NAME}}("
    << {{v.NAME}}
  << ")";
  this->get_o().call();

  this->get_i().pull();

  if(this->get_i().get_si()->peek() == '!'){
    this->get_i().get_si()->get();
    std::shared_ptr<Error> l_e;
    this->get_i() >> l_e;
    l_e->real();
  }else{
    std::string empty;
    std::getline(this->get_i(), empty);
    if(empty!=""){
      throw "Error: set return something";
    }
  }
  this->get_i().end();
  return;
}
{%- endfor %}
