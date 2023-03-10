// {{INTERFACE.NAME}} /////////////////////////////////////////////////////////
{%- for f in INTERFACE.FUNCTION %}
virtual {{ f.RETURN.D_NAME }} {{ f.NAME }}(
  {%- for a in f.SIGNATURE -%}
  {{a.TYPE.D_NAME}} {{a.NAME}}
  {%- if not loop.last%},{% endif %}
  {%- endfor-%}
  ) override;
{%- endfor %}

{% if INTERFACE.PARENT %}
{% with INTERFACE=INTERFACE.PARENT%}
{% include "Components/provide/Function_helper.hpp" with context %}
{% endwith %}
{% endif %}
