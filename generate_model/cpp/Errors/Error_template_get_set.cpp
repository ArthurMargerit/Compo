#include "Errors/{{F_NAME}}.hpp"

{%include "helper/namespace_open.hpp" with context%}

{%- for value_data in DATA %}
{{value_data.TYPE.D_NAME}}
{{NAME}}::get_{{value_data.NAME}}() const {
  return this->{{value_data.NAME}};
}

void
{{NAME}}::set_{{value_data.NAME}}(const {{value_data.TYPE.D_NAME}}& value) {
  this->{{value_data.NAME}} = value;
}

{%- endfor %}

{%include "helper/namespace_close.hpp" with context%}
