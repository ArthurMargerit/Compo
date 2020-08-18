{%if "PARENT" in ic and ic.PARENT != None and "PARENT" in ir and ir.PARENT != None %}
{% with ic=ic.PARENT, ir=ir.PARENT%}
{%include "Connectors/Async_Interface_function.cpp" %}
{% endwith %}
{% endif %}

// {{ic.NAME}}
{%for fc,fr in Function.zip(ic.FUNCTION,ir.FUNCTION) %}

{% if fr.SIGNATURE == [] %}
{% set ret = dict({"D_NAME":"void"}) %}
{% else %}
{% set ret = fr.SIGNATURE[0].TYPE %}
{% endif %}

void {{CLS_I_NAME}}::{{fc.NAME}} (
  {%- for p in fc.SIGNATURE -%}
  {{p.TYPE.D_NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
  {%- endfor -%}) {

  if(! this->get_c().r.connected()) {
    throw std::runtime_error("The Interface {{ic.NAME}} is not connected the {{fc.NAME}} have been cancel");
  }

  std::shared_future<{{ret.D_NAME}}> sf = std::async([this{%- for p in fc.SIGNATURE -%},{{p.NAME}}{%- endfor -%}] {
    {% if ret.D_NAME != "void" -%}
    return this->get_c().r->{{fc.NAME}}(
      {%- for p in fc.SIGNATURE -%}{{p.NAME}}{% if not loop.last %},{%endif%}{%- endfor -%});
    {% else %}
    this->get_c().r->{{fc.NAME}}(
      {%- for p in fc.SIGNATURE -%}{{p.NAME}}{% if not loop.last %},{%endif%}{%- endfor -%});
    return;
    {%endif%}
  });


  {% if ret.D_NAME == "void" -%}
  auto back = [this](){this->get_c().rr->{{fr.NAME}}();};
  {%else%}
  auto back = [this]({{ret.D_NAME}} t){
    if(! this->get_c().rr.connected()) {
      throw std::runtime_error("The Return Interface {{ir.NAME}} is not connected, the return value of {{fc.NAME}} call is dropped.");
    }

    this->get_c().rr->{{fr.NAME}}(t);
  };
  {%endif%}

  auto f = new CompoMe::Async::Async_Call<{{ret.D_NAME}}>("{{ic.NAME}}::{{fc.NAME}}(...)", sf, back);
  this->get_c().add(f);

  return;
}
{%endfor%}
