{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set ic = MAIN.INTERFACES[INTERFACE_ASYNC_CALL] %}
{% set ir = MAIN.INTERFACES[INTERFACE_ASYNC_RETURN] %}

#include "connectors/{{F_NAME}}.hpp"

{%include "helper/namespace_close.hpp" %}
{%include "Connectors/Async_Interface.cpp"%}

{{NAME}}::{{NAME}}():CompoMe::Async::Async_Connector()
{%for p in PROVIDE %},{{p.NAME}}(this){%endfor%}{}

{{NAME}}::~{{NAME}}(){}

{%include "helper/namespace_close.hpp" %}
