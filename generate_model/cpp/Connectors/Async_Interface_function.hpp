{%if "PARENT" in ic and ic.PARENT != None and "PARENT" in ir and ir.PARENT != None %}
{% with ic=ic.PARENT, ir=ir.PARENT%}
{%include "Connectors/Async_Interface_function.hpp" %}
{% endwith %}
{% endif %}

// {{ic.NAME}}
{%for fc,fr in Function.zip(ic.FUNCTION,ir.FUNCTION) %}
virtual
void {{fc.NAME}} (
  {%- for p in fc.SIGNATURE -%}
  {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
  {%- endfor -%}) {

  {% if fr.SIGNATURE != [] %}
  auto l_return =
    {%- endif -%}
    this->get__c().get_r()->{{fc.NAME}}(
      {%- for p in fc.SIGNATURE -%}
      {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%});

  if(this->get__c().get_rr() == NULL) {
    std::cerr << "warning return value lost"<<std::endl;
  } else {
    {% if fr.SIGNATURE != [] -%}
    this->get__c().get_rr()->{{fr.NAME}}(l_return);
    {%-else-%}
    this->get__c().get_rr()->{{fr.NAME}}();
    {%-endif%}
  }
  return;
}
{%endfor%}
