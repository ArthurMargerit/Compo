#include "Components/{{COMPONENT.F_NAME}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.F_NAME}}.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}

  {% with NAME=INTERFACE.NAME,
      DATA=INTERFACE.DATA,
      PARENT=INTERFACE.PARENT,
      CLS_NAME=COMPONENT.NAME+"_"+INTERFACE.NAME+"_"+NAME%}
  {% include "Components/provide/Get_Set_helper.cpp" with context %}
  {% endwith %}

{% include "helper/namespace_close.hpp" with context %}
