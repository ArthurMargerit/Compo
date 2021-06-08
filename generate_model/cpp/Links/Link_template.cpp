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

void {{NAME}}::main_connect() {
  {%if PARENT -%}
  {{PARENT.D_NAME}}::main_connect();
  {% else -%}
  Link::main_connect();
  {% endif -%}
}

void {{NAME}}::main_disconnect() {
  {%if PARENT -%}
  {{PARENT.D_NAME}}::main_disconnect();
  {% else -%}
  Link::main_disconnect();
  {% endif -%}
}

{%include "helper/namespace_close.hpp"%}
