#include "types.hpp"
#include "structs.hpp"

#include <ostream>
#include <istream>

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


std::istream& operator>>(std::istream& is, {{key}}& c)
{
  is.ignore(100, '{');
  {%- for d in value["DATA"] %}
  is.ignore(100, ':') >> c.{{d["NAME"]}} ;
  {%- if not loop.last -%}
  is.ignore(1, ',');
  {%- endif -%}
  {%- endfor %}
  is.ignore(1, '}');

  return is;
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
