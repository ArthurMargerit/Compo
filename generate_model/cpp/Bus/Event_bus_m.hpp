{%for e in EVENTS %}
{% if e.EVENT.D_NAME not in impl_invt %}
{% set _ = impl_invt.append(e.EVENT.D_NAME) %}
virtual void m({{e.EVENT.D_NAME}}& p_e) = 0;
{% endif %}
{%endfor%}

{%for sb in SUB_BUS %}
{% with EVENTS=sb.BUS.EVENTS, SUB_BUS=sb.BUS.SUB_BUS %}
{% include "Events/Event_bus_m.hpp" with context %}
{% endwith %}
{%endfor%}
