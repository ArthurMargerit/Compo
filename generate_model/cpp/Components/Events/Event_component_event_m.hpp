{%- for e in EVENTS %}
{% if e.EVENT.D_NAME not in impl_invt %}
{% set _ = impl_invt.append(e.EVENT.D_NAME) %}
void m({{e.EVENT.D_NAME}}& e) override {}
{% endif %}
{%- endfor %}

{%- for sb in SUB_BUS %}
{% with EVENTS=sb.BUS.EVENTS, SUB_BUS=sb.BUS.SUB_BUS%}
{%include "Components/Events/Event_component_event_m.hpp" with context%}
{% endwith %}
{%- endfor %}

