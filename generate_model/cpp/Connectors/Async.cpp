{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set ic = MAIN.INTERFACES[INTERFACE_ASYNC_CALL] %}
{% set ir = MAIN.INTERFACES[INTERFACE_ASYNC_RETURN] %}

#include "connectors/{{F_NAME}}.hpp"

{%include "helper/namespace_close.hpp" %}
{%include "Connectors/Async_Interface.cpp"%}

{{NAME}}::{{NAME}}(){%if PROVIDE.__len__ != 0%}:{%endif%}
  {%for p in PROVIDE %}{{p.NAME}}(this){%if not loop.last %},{%endif%}{%endfor%}{}

{{NAME}}::~{{NAME}}(){}

{%include "helper/namespace_close.hpp" %}
