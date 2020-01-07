#include "Links/{{NAME}}/{{NAME}}.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"
#include "Interfaces/Interface.hpp"

{{NAME}}::{{NAME}}() :{%if PARENT -%}{{PARENT.NAME}}() {% else -%} Link(){% endif -%} {

}

{{NAME}}::~{{NAME}}() {


}

void {{NAME}}::step() {
  {%if PARENT -%}
  {{PARENT.NAME}}::step();
  {% else -%}
  Link::step();
  {% endif -%}
}

void {{NAME}}::connect() {
  {%if PARENT -%}
  {{PARENT.NAME}}::connect();
  {% else -%}
  Link::connect();
  {% endif -%}
}

void {{NAME}}::disconnect() {
  {%if PARENT -%}
  {{PARENT.NAME}}::disconnect();
  {% else -%}
  Link::disconnect();
  {% endif -%}
}
// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
  {{data.TYPE.NAME}} {{NAME}}::get_{{data.NAME}}() const {
    return {{data.NAME}};
   }

void {{NAME}}::set_{{data.NAME}}(const {{data.TYPE.NAME}} {{data.NAME}}) {
  this->{{data.NAME}} = {{data.NAME}};
  }
  {%- endfor %}

