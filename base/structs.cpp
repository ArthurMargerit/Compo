#include "types.hpp"
#include "structs.hpp"

#include <ostream>

{% for key,value in STRUCTS.items() %}

std::ostream& operator<<(std::ostream& os, const {{key}}&  c)
{
  os << "{"
     <<
  {% for d in value["DATA"] %}
   "{{d["NAME"]}}:"<< c.{{d["NAME"]}}
    {%- if not loop.last %}
     <<","
    {%- endif -%}
  {%- endfor %}
     << "}";
  return os;
}

{% endfor %}
