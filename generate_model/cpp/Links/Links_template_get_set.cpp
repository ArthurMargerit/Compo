#include "Links/{{F_NAME}}/{{NAME}}.hpp"

{%include "helper/namespace_open.hpp"%}
{% for data in DATA %}
//============================= {{data.NAME}} =============================
{{data.TYPE.D_NAME}} {{NAME}}::get_{{data.NAME}}() const {
  return this->{{data.NAME}};
}

void {{NAME}}::set_{{data.NAME}}(const {{data.TYPE.D_NAME}} p_{{data.NAME}}) {
  this->{{data.NAME}} = p_{{data.NAME}};
}

{{data.TYPE.D_NAME}} & {{NAME}}::a_{{data.NAME}}() {
  return this->{{data.NAME}};
}
//--------------------------------------------------------------------------
{%- endfor %}
{%include "helper/namespace_close.hpp"%}
