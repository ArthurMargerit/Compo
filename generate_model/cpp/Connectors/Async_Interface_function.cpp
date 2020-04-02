{%if "PARENT" in ic and ic.PARENT != None and "PARENT" in ir and ir.PARENT != None %}
{% with ic=ic.PARENT, ir=ir.PARENT%}
{%include "Connectors/Async_Interface_function.cpp" %}
{% endwith %}
{% endif %}

// {{ic.NAME}}
{%for fc,fr in Function.zip(ic.FUNCTION,ir.FUNCTION) %}
void {{CLS_I_NAME}}::{{fc.NAME}} (
  {%- for p in fc.SIGNATURE -%}
  {{p.TYPE.D_NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
  {%- endfor -%}) {

  {% if fr.SIGNATURE != [] %}
  auto l_return =
    {%- endif -%}
    this->get_c().r->{{fc.NAME}}(
      {%- for p in fc.SIGNATURE -%}
      {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%});

  if(! this->get_c().rr.connected()) {
    std::cerr << "warning return value lost"<<std::endl;
    return;
  }

  {% if fr.SIGNATURE != [] -%}
  this->get_c().rr->{{fr.NAME}}(l_return);
  {%-else-%}
  this->get_c().rr->{{fr.NAME}}();
  {%-endif%}

  return;
}
{%endfor%}
