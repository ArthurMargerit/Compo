{%if "PARENT" in ic and ic.PARENT != None and "PARENT" in ir and ir.PARENT != None %}
{% with ic=ic.PARENT, ir=ir.PARENT%}
{%include "Connectors/Async_Interface_function.hpp" %}
{% endwith %}
{% endif %}

// {{ic.NAME}}
{%for fc,fr in Function.zip(ic.FUNCTION,ir.FUNCTION) %}
void {{fc.NAME}} (
  {%- for p in fc.SIGNATURE -%}
  {{p.TYPE.D_NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
  {%- endfor -%}) override;
{%endfor%}
