#include "Components/{{COMPONENT.F_NAME}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.F_NAME}}.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}

  {% with INTERFACE=INTERFACE, CLS_NAME=COMPONENT.NAME+"_"+INTERFACE.NAME+"_"+NAME%}
  {% include "Components/provide/Function_helper.cpp" with context %}
  {% endwith %}

{% include "helper/namespace_close.hpp" with context %}
