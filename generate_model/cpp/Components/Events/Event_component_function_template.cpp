#include "Components/{{COMPONENT.F_NAME}}_{{BUS.NAME}}_{{NAME}}.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}

    {% with EVENTS=BUS.EVENTS, SUB_BUS=BUS.SUB_BUS,impl_invt = []%}
    {% include "Components/Events/Event_component_event_m.cpp" with context%}
    {% endwith %}

{% include "helper/namespace_close.hpp" with context %}
