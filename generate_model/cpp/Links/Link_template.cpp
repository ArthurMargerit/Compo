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

{% for f in FUNCTION %}
{{f.RETURN.D_NAME}} {{NAME}}::{{f.NAME}}(
  {%- for p in f.SIGNATURE -%}
  {{p.TYPE.D_NAME}} {{p.NAME}} {% if not loop.last%},{% endif %}
  {%- endfor -%}) {
  {%- if f.RETURN.D_NAME == "void" %}
  return;
  {%- else %}
  {{f.RETURN.D_NAME}} {{NAME}};
  return {{NAME}};
  {%- endif %}
}

{% endfor%}


// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
{{data.TYPE.D_NAME}} {{NAME}}::get_{{data.NAME}}() const {
    return this->{{data.NAME}};
}

void {{NAME}}::set_{{data.NAME}}(const {{data.TYPE.D_NAME}} p_{{data.NAME}}) {
  this->{{data.NAME}} = p_{{data.NAME}};
}

{{data.TYPE.D_NAME}} & {{NAME}}::a_{{data.NAME}}() {
  return this->{{data.NAME}};
}


{%- endfor %}
{%include "helper/namespace_close.hpp"%}
