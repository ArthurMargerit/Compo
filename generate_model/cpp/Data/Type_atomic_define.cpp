

#include "Data/Type_{{NAME}}.hpp"

{%- if not NATIF %}

{% if ENUM %}
std::ostream& operator<<(std::ostream& os, const {{NAME}}& c)
{
  switch(c) {
  {% for enum_name,enum_val in ENUM.items() %}
  case {{NAME | upper }}_{{enum_name | upper}}:
  os << "{{NAME | upper }}_{{enum_name | upper}}";
  break;
 {% endfor %}
  }

 return os;
}
{% endif %}

{%- endif %}
