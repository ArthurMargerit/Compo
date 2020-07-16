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

{%- if PORT.MAP_IN or PORT.MAP_OUT or PORT.ARRAY_IN or PORT.ARRAY_OUT or PORT.DBUS_OUT or PORT.DBUS_IN  -%}
void {{NAME}}::connect(Require_helper& p_i) {

}

void {{NAME}}::disconnect(Require_helper& p_i) {

}
{%- endif -%}


// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
  {{data.TYPE.D_NAME}} {{NAME}}::get_{{data.NAME}}() const {
    return this->{{data.NAME}};
   }

void {{NAME}}::set_{{data.NAME}}(const {{data.TYPE.D_NAME}} p_{{data.NAME}}) {
  this->{{data.NAME}} = p_{{data.NAME}};
}
{%- endfor %}
{%include "helper/namespace_close.hpp"%}
