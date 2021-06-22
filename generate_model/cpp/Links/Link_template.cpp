#include "Links/{{F_NAME}}/{{NAME}}.hpp"

#include "Interfaces/Interface.hpp"

{%include "helper/namespace_open.hpp"%}
{{NAME}}::{{NAME}}() :{%if PARENT -%}{{PARENT.D_NAME}}(){% else -%} CompoMe::Link(){% endif -%}
{%- for p in PORT -%}
                                                                       ,{{p.NAME}}()
{%- endfor -%}
{
  {%- for p in PORT -%}
  this->{{p.NAME}}.set_link(*this);
  {%- endfor -%}
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

// one connect
 void {{NAME}}::one_connect(CompoMe::Require_helper &p_r, CompoMe::String p_key){}

 void {{NAME}}::one_connect(CompoMe::Interface &p_i, CompoMe::String p_key){}

// one disconnect
 void {{NAME}}::one_disconnect(CompoMe::Require_helper &p_r, CompoMe::String p_key){}

 void {{NAME}}::one_disconnect(CompoMe::Interface &p_i, CompoMe::String p_key){}

{%include "helper/namespace_close.hpp"%}
