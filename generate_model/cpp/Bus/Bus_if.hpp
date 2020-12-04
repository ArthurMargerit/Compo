{%for e in EVENTS %}
{% if e.EVENT.D_NAME not in impl_invt %}
{% set _ = impl_invt.append(e.EVENT.D_NAME) %}
if(typeid(*e).hash_code() == typeid({{e.EVENT.D_NAME}}).hash_code()) {
  m(*({{e.EVENT.D_NAME}}*)e);
  return;
 }
{% endif %}
{%endfor%}

{%for sb in SUB_BUS %}
{% with EVENTS=sb.BUS.EVENTS, SUB_BUS=sb.BUS.SUB_BUS %}
{% include "Events/Bus_if.hpp" with context %}
{% endwith %}
{%endfor%}
