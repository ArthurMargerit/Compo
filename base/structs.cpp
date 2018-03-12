#include "types.hpp"
#include "structs.hpp"

#include <ostream>

{% for key,value in STRUCTS.items() %}

std::ostream& operator<<(std::ostream& os, const {{key}}&  c)
{
  os << "{"
  {%- for d in value["DATA"] %}
     << "{{d["NAME"]}}:"<< c.{{d["NAME"]}}
    {%- if not loop.last -%}
     <<","
    {%- endif -%}
  {%- endfor %}
     << "}";
  return os;
}

  {{value["NAME"]}}::{{value["NAME"]}}(
    {%- for value_data in value["DATA"] -%}
    {{value_data["TYPE"]["NAME"]}} p_{{value_data["NAME"]}}
    {%- if not loop.last -%}
    ,
    {%- endif -%}
    {%- endfor %})
  :{%- for value_data in value["DATA"] %}
    {{value_data["NAME"]}}(p_{{value_data["NAME"]}})
    {%- if not loop.last -%}
        ,
    {%- endif -%}
    {% endfor %}
  {

  }

  {{value["NAME"]}}::{{value["NAME"]}}()
  :{%- for value_data in value["DATA"] %}
    {{value_data["NAME"]}}()
    {%- if not loop.last -%}
        ,
    {%- endif -%}
    {% endfor %}
  {
    
  }


{% endfor %}
