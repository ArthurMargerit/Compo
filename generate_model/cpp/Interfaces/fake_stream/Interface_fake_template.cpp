#include "Interfaces/{{F_NAME}}/{{NAME}}_fake_stream.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"
#include <tuple>

{% include "helper/namespace_open.hpp" with context %}
{{NAME}}::T_p_stream
{{NAME}}::get_fake_stream(CompoMe::Function_stream_send &fs,
                          CompoMe::Return_stream_recv &rs) {
  {{NAME}}_fake_stream * a = new {{NAME}}_fake_stream(fs, rs);
  std::tuple<{{NAME}}_fake_stream*,
             CompoMe::Fake_stream*,
               {{NAME}}*> rr(a, a, a);
  return rr;
}

{{NAME}}_fake_stream::{{NAME}}_fake_stream(CompoMe::Function_stream_send& out, CompoMe::Return_stream_recv& in):
{%if PARENT%}{{PARENT.D_NAME}}_fake_stream(out,in){%else%}CompoMe::Fake_stream(out,in){%endif%} {}

{{NAME}}_fake_stream::~{{NAME}}_fake_stream() noexcept{}


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
  {{ f.RETURN.D_NAME }} {{ NAME }}_fake_stream::{{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )
  {
    this->get_o().start();
    this->get_o() << "{{f.NAME}}("
    {% for a in f.SIGNATURE -%}
    << {{a.NAME }}
    {%- if not loop.last%}<< ","{% endif %}
    {%- endfor -%}
    << ")";
    this->get_o().send();

    this->get_i().pull();
    if(this->get_i().get_si().peek() == '!') {
      this->get_i().get_si().get(); // remove !
      std::shared_ptr<CompoMe::Error> l_e;
      this->get_i() >> l_e;
      this->get_i().end();
      l_e->real();
    }

    {% if f.RETURN.NAME != "void" %}
    {{f.RETURN.D_NAME}} ri = {{f.RETURN.D_NAME}}{%if f.RETURN.DEFAULT %} ({{f.RETURN.DEFAULT}}){%else%}(){%endif%};
    this->get_i() >> ri;
    this->get_i().end();
    return ri;
    {% else %}
    return;
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
  {{v.TYPE.D_NAME}} {{NAME}}_fake_stream::get_{{v.NAME}}() const {
    this->get_o().start();
    this->get_o() << "get_{{v.NAME}}()" ;
    this->get_o().send();

    this->get_i().pull();
    if(this->get_i().get_si().peek() == '!'){
      this->get_i().get_si().get();
      std::shared_ptr<CompoMe::Error> l_e;
      this->get_i() >> l_e;
      this->get_i().end();
      l_e->real(); // throw inside;
    }

    {{v.TYPE.D_NAME}} ret;
    this->get_i() >> ret;
    this->get_i().end();
    return ret;
}

void
{{ NAME }}_fake_stream::set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}}) {
  this->get_o().start();
  this->get_o() << "set_{{v.NAME}}("
                << {{v.NAME}}
                << ")";
  this->get_o().send();

  this->get_i().pull();
  if(this->get_i().get_si().peek() == '!'){
    this->get_i().get_si().get();
    std::shared_ptr<CompoMe::Error> l_e;
    this->get_i() >> l_e;
    this->get_i().end();
    l_e->real();
  }

  this->get_i().end();
  return;
}
{%- endfor %}

{% include "helper/namespace_close.hpp" with context%}
