{%- for e in EVENTS %}
{% if e.EVENT.D_NAME not in impl_invt %}
{% set _ = impl_invt.append(e.EVENT.D_NAME) %}
void {{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}}::m({{e.EVENT.D_NAME}}& e) {

  /* ... write/replace this comment by the component event code .. */

}
{% endif %}
{%- endfor %}

{%- for sb in SUB_BUS %}
{% with EVENTS=sb.BUS.EVENTS, SUB_BUS=sb.BUS.SUB_BUS%}
{%include "Components/Events/Event_component_event_m.cpp" with context%}
{% endwith %}
{%- endfor %}
