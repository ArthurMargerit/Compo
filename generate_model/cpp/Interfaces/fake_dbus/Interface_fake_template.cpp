#include "Interfaces/{{F_NAME}}/{{NAME}}_fake_dbus.hpp"

#include "Interfaces/Function_dbus_send.hpp"
#include "Interfaces/Return_dbus_recv.hpp"

#include "Errors/Error.hpp"

{% include "helper/namespace_open.hpp" with context %}

{{NAME}}::T_p_dbus
{{NAME}}::get_fake_dbus(CompoMe::Function_dbus_send &fs,
                        CompoMe::Return_dbus_recv &rs) {
  {{NAME}}_fake_dbus * a = new {{NAME}}_fake_dbus(fs, rs);
  std::tuple<{{NAME}}_fake_dbus*,
             CompoMe::Fake_dbus*,
               {{NAME}}*> rr(a, a, a);
  return rr;
}

{{NAME}}_fake_dbus::{{NAME}}_fake_dbus(CompoMe::Function_dbus_send& out,
                                       CompoMe::Return_dbus_recv& in):
{%if PARENT%}{{PARENT.D_NAME}}_fake_dbus(out,in){%else%}CompoMe::Fake_dbus(out,in){%endif%} {

 }

{{NAME}}_fake_dbus::~{{NAME}}_fake_dbus() noexcept{}

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
  {{ f.RETURN.D_NAME }} {{ NAME }}_fake_dbus::{{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )
  {
    this->get_o().start();
    this->get_o().set_function("{{f.NAME}}");
    CompoMe::Serialization_context_export p_ctx;
    {% for a in f.SIGNATURE -%}
    {% if Function.model_test.is_struct(a.TYPE.D_NAME, MAIN)-%}
    {{a.NAME}}.to_dbus(this->get_o().get_so(), p_ctx);
    {% else -%}
    this->get_o() << {{a.NAME}};
    {% endif -%}
    {%- endfor -%}
    this->get_o().send();

    this->get_i().pull();
    // TODO: error
    // // if(this->get_i().get_si().peek() == '!') {
    // //   this->get_i().get_si().get(); // remove !
    // //   std::shared_ptr<Error> l_e;
    // //   this->get_i() >> l_e;
    //   this->get_i().end();
    //   //l_e->real();
    //   //    }

    {% if f.RETURN.NAME != "void" %}
    CompoMe::Serialization_context_import p_ctx_i;
    {{f.RETURN.D_NAME}} ri = {{f.RETURN.D_NAME}}{%if f.RETURN.DEFAULT %} ({{f.RETURN.DEFAULT}}){%else%}(){%endif%};
    {% if Function.model_test.is_struct(f.RETURN.D_NAME, MAIN)-%}
    ri.from_dbus(this->get_i().get_si(), p_ctx_i);
    {% else -%}
    this->get_i() >> ri;
    {% endif -%}


    this->get_i().end();
    return ri;
    {% else %}
    this->get_i().end();
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
  {{v.TYPE.D_NAME}} {{NAME}}_fake_dbus::get_{{v.NAME}}() const {
    this->get_o().start();
    this->get_o().set_function("get_{{v.NAME}}") ;
    this->get_o().send();

    this->get_i().pull();
    // // if(this->get_i().get_si().peek() == '!'){
    // //   this->get_i().get_si().get();
    // //   std::shared_ptr<Error> l_e;
    // //   this->get_i() >> l_e;
    //   this->get_i().end();
    // //   l_e->real(); // throw inside;
    // // }

    {{v.TYPE.D_NAME}} ret;
    this->get_i() >> ret;
    this->get_i().end();
    return ret;
}

void
{{ NAME }}_fake_dbus::set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}}) {
   this->get_o().start();
   this->get_o().set_function("set_{{v.NAME}}");
   this->get_o() << {{v.NAME}};
   this->get_o().send();

   this->get_i().pull();
  // // if(this->get_i().get_si().peek() == '!'){
  // //   this->get_i().get_si().get();
  // //   std::shared_ptr<Error> l_e;
  // //   this->get_i() >> l_e;
  // //   this->get_i().end();
  // //   l_e->real();
  // // }
   this->get_i().end();
   return;
}
{%- endfor %}

{% include "helper/namespace_close.hpp" with context%}
