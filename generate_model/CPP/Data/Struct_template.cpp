#include "Data/Types.hpp"

#include "Data/Struct_{{NAME}}.hpp"

#include <ostream>
#include <istream>


std::ostream& operator<<(std::ostream& os, const {{NAME}}&  c)
{
  os << "{"
  {%- for d in DATA %}
     << "{{d["NAME"]}}:"<< c.{{d["NAME"]}}
    {%- if not loop.last -%}
     <<","
    {%- endif -%}
  {%- endfor %}
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, {{NAME}}& c)
{
  is.ignore(100, '{');
  {%- for d in DATA %}
  is.ignore(100, ':') >> c.{{d["NAME"]}} ;
  {%- if not loop.last -%}
  is.ignore(1, ',');
  {%- endif -%}
  {%- endfor %}
  is.ignore(1, '}');

  return is;
}


  {{NAME}}::{{NAME}}(
    {%- for value_data in DATA -%}
    {{value_data["TYPE"]["NAME"]}} p_{{value_data["NAME"]}}
    {%- if not loop.last -%}
    ,
    {%- endif -%}
    {%- endfor %})
  :{%- for value_data in DATA %}
    {{value_data["NAME"]}}(p_{{value_data["NAME"]}})
    {%- if not loop.last -%}
        ,
    {%- endif -%}
    {% endfor %}
  {

  }

  {{NAME}}::{{NAME}}()
  :{%- for value_data in DATA %}
    {{value_data["NAME"]}}()
    {%- if not loop.last -%}
        ,
    {%- endif -%}
    {% endfor %}
  {
  }

