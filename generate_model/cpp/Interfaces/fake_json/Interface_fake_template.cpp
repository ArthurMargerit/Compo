#include "Interfaces/{{F_NAME}}/{{NAME}}_fake_json.hpp"

#include "Interfaces/Function_stream_send.hpp"
#include "Interfaces/Return_stream_recv.hpp"

#include "Errors/Error.hpp"

{% include "helper/namespace_open.hpp" with context %}

{{NAME}}::T_p_json
{{NAME}}::get_fake_json(CompoMe::Function_json_send &fs,
                        CompoMe::Return_json_recv &rs) {
  {{NAME}}_fake_json * a = new {{NAME}}_fake_json(fs, rs);
  std::tuple<{{NAME}}_fake_json*,
             CompoMe::Fake_json*,
               {{NAME}}*> rr(a, a, a);
  return rr;
}

{{NAME}}_fake_json::{{NAME}}_fake_json(CompoMe::Function_json_send& out,
                                       CompoMe::Return_json_recv& in):
{%if PARENT%}{{PARENT.D_NAME}}_fake_json(out,in){%else%}CompoMe::Fake_json(out,in){%endif%} {

 }

{{NAME}}_fake_json::~{{NAME}}_fake_json() noexcept{}

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
  {{ f.RETURN.D_NAME }} {{ NAME }}_fake_json::{{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )
  {
    this->get_o().start();
    this->get_o().set_function("{{f.NAME}}");

    {% for a in f.SIGNATURE -%}
    {% if Function.model_test.is_struct(a.TYPE.D_NAME, MAIN)-%}
    {{a.NAME}}.to_json(this->get_o().get_data()["params"]["{{a.NAME}}"],
                       this->get_o().get_ctx());
    {% else -%}
    this->get_o().get_data()["params"]["{{a.NAME}}"] = {{a.NAME}};
    {% endif -%}
    {%- endfor -%}
    this->get_o().send();

    this->get_i().pull();
    // // TODO: error
    // // // if(this->get_i().get_si().peek() == '!') {
    // // //   this->get_i().get_si().get(); // remove !
    // // //   std::shared_ptr<Error> l_e;
    // // //   this->get_i() >> l_e;
    // //   this->get_i().end();
    // //   //l_e->real();
    // //   //    }

    {% if f.RETURN.NAME != "void" %}

    {{f.RETURN.D_NAME}} ri = {{f.RETURN.D_NAME}}{%if f.RETURN.DEFAULT %} ({{f.RETURN.DEFAULT}}){%else%}(){%endif%};
    {% if Function.model_test.is_struct(f.RETURN.D_NAME, MAIN)-%}
    ri.from_json(this->get_i().get_data()["result"], this->get_i().get_ctx());
    {% else -%}
    this->get_i().get_data()["result"].get_to(ri);
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
  {{v.TYPE.D_NAME}} {{NAME}}_fake_json::get_{{v.NAME}}() const {
    this->get_o().start();
    this->get_o().set_function("get_{{v.NAME}}") ;
    this->get_o().send();

    this->get_i().pull();

    //if(this->get_i().get_si().peek() == '!'){
    // // //   this->get_i().get_si().get();
    // // //   std::shared_ptr<Error> l_e;
    // // //   this->get_i() >> l_e;
    // //   this->get_i().end();
    // // //   l_e->real(); // throw inside;
    //}

    {{v.TYPE.D_NAME}} ret;
    {% if Function.model_test.is_struct(v.TYPE.D_NAME, MAIN) -%}
    ret.from_json(this->get_i().get_data()["result"],
                  this->get_i().get_ctx());
    {% else -%}
    this->get_i().get_data()["result"].get_to(ret);
    {% endif -%}

    this->get_i().end();
    return ret;
}

void
{{ NAME }}_fake_json::set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& p_{{v.NAME}}) {
  this->get_o().start();
  this->get_o().set_function("set_{{v.NAME}}");

  this->get_o().get_data()["params"] = nlohmann::json::array({nullptr});
  {% if Function.model_test.is_struct(v.TYPE.D_NAME, MAIN) -%}
  p_{{v.NAME}}.to_json(this->get_o().get_data()["params"][0], this->get_o().get_ctx());
  {% else -%}
  this->get_o().get_data()["params"][0] = p_{{v.NAME}};
  {% endif %}
  this->get_o().send();

  this->get_i().pull();
  this->get_i().end();
   return;
}
{%- endfor %}

{% include "helper/namespace_close.hpp" with context%}
