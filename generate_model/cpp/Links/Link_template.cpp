#include "Links/{{F_NAME}}/{{NAME}}.hpp"

#include "Interfaces/Interface.hpp"

{%include "helper/namespace_open.hpp"%}
{{NAME}}::{{NAME}}() :{%if PARENT -%}{{PARENT.D_NAME}}() {% else -%} CompoMe::Link(){% endif -%} {

}

{{NAME}}::~{{NAME}}() {

}

void {{NAME}}::step() {
  {%if PARENT -%}
  {{PARENT.D_NAME}}::step();
  {% else -%}
  Link::step();
  {% endif -%}
}

void {{NAME}}::connect() {
  {%if PARENT -%}
  {{PARENT.D_NAME}}::connect();
  {% else -%}
  Link::connect();
  {% endif -%}
}

void {{NAME}}::disconnect() {
  {%if PARENT -%}
  {{PARENT.D_NAME}}::disconnect();
  {% else -%}
  Link::disconnect();
  {% endif -%}
}

{%- if PORT.MAP_OUT or PORT.MAP_MAP_OUT or PORT.ARRAY_OUT or PORT.DBUS_OUT -%}
void {{NAME}}::connect(CompoMe::Require_helper& p_i) {

}

void {{NAME}}::disconnect(CompoMe::Require_helper& p_i) {

}
{%- endif -%}
{%include "helper/namespace_close.hpp"%}
