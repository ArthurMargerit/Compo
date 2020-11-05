#include "Deployments/{{F_NAME}}/{{NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context %}
// GET ////////////////////////////////////////////////////////////////////////
// COMPONENT
{%for inst in COMPONENT_INSTANCE %}
{{inst.COMPONENT.D_NAME}}&
{{NAME}}::get_{{inst.NAME}}() {
  return this->{{inst.NAME}};
}
{%endfor%}

// CONNECTOR
{%for inst in CONNECTOR_INSTANCE %}
{{inst.CONNECTOR.D_NAME}}&
{{NAME}}::get_{{inst.NAME}}() {
  return this->{{inst.NAME}};
}
{%endfor%}

// LINK
{%for link in LINK_INSTANCE %}
  {{link.TYPE.D_NAME}}&
  {{NAME}}::get_{{link.NAME}}() {
    return this->{{link.NAME}};
}
{%endfor%}
{% include "helper/namespace_close.hpp" with context%}
