#include "Events/{{F_NAME}}.hpp"

{%include "helper/namespace_open.hpp" with context %}
// GET SET ////////////////////////////////////////////////////////////////////
{%- for d in DATA %}
// get/set {{d.NAME}}
{{d.TYPE.D_NAME}} {{NAME}}::get_{{d.NAME}}() const {
  return this->{{d.NAME}};
                                          }

void {{NAME}}::set_{{d.NAME}}(const {{d.TYPE.D_NAME}}& p_{{d.NAME}}) {
  this->{{d.NAME}} = p_{{d.NAME}};
                             }

{{d.TYPE.D_NAME}} & {{NAME}}::a_{{d.NAME}}() {
  return this->{{d.NAME}};
                                          }
{%- endfor %}

{%include "helper/namespace_close.hpp" with context %}
