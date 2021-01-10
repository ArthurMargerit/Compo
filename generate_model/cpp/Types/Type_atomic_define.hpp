#pragma once

{%if TOSTRING or ENUM %}
#include <istream>
#include <ostream>
{%endif%}

{% if INCLUDE %}
{% if INCLUDE.__class__.__name__ == "str" %}
#include {{INCLUDE}}
{%elif INCLUDE.__class__.__name__ == "list" %}
{%for l_include in INCLUDE %}
#include {{l_include}}
{%endfor%}
{%else%}
#include {{INCLUDE}}
{%endif%}
{%endif%}

{% include "helper/namespace_open.hpp" %}

{%- if BEFORE %}
{{BEFORE}}
{%- endif %}

{%- if not NATIF %}
{% if DEFINITION %}
{% if DYNAMIC %}
template <
{%- for l_arg in ARG -%}
{% if " " in l_arg %}{{l_arg}}{%else%}typename {{l_arg}}{%endif%}
{%- if not loop.last%},{%endif -%}
{%- endfor -%}
> using {{NAME}} = {{DEFINITION}};
{%else%}
using {{NAME}} = {{DEFINITION}};
{%endif%}

{% elif ENUM %}
enum class {{NAME}} {%if OPTIONS and OPTIONS.ENUM_CLS %}:{{OPTIONS.ENUM_CLS}}{%endif%} {
  {% for enum_name,enum_val in ENUM.items() %}
  {{enum_name | upper}} = {{enum_val}}{%if not loop.last%},{%endif%}
  {% endfor %}
};

{%if OPTIONS and OPTIONS.ENUM_FLAGS %}
{%if not OPTIONS.ENUM_CLS %}{% set OPTIONS.ENUM_CLS = "int" %}{%endif%}
inline {{NAME}} operator|(const {{NAME}} a, const {{NAME}} b)
{
  return static_cast<{{NAME}}>(static_cast<{{OPTIONS.ENUM_CLS}}>(a) | static_cast<{{OPTIONS.ENUM_CLS}}>(b));
}

inline {{NAME}} operator&(const {{NAME}} a, const {{NAME}} b)
{
  return static_cast<{{NAME}}>(static_cast<{{OPTIONS.ENUM_CLS}}>(a) & static_cast<{{OPTIONS.ENUM_CLS}}>(b));
}

inline bool is(const {{NAME}} a, const {{NAME}} b)
{
  return (a & b) == b;
}

{%endif%}

{% endif %}
{% endif %}


{% include "helper/namespace_close.hpp" %}

{%if TOSTRING or ENUM %}
namespace std {
{%if DYNAMIC%}
template<
{%-for l_arg in ARG -%}
{% if " " in l_arg %}{{l_arg}}{%else%}typename {{l_arg}}{%endif%}
{% if not loop.last %},{%endif -%}
{%-endfor-%}
>{%endif%}
std::ostream& operator<<(std::ostream& os, const {{D_NAME}}{%if DYNAMIC%}<
                         {%- for l_arg in ARG -%}
  {% if "..." in l_arg %}{{l_arg.replace("...","")}}...{% else -%}{{l_arg.split(" ")[-1]}}{% endif %}{% if not loop.last %},{% endif -%}
                         {%- endfor -%}>{% endif %}&){% if DYNAMIC %} {return os;} {% else %};{% endif %}

{%if DYNAMIC%}
template<
{%- for l_arg in ARG -%}
{% if " " in l_arg %}{{l_arg}}{%else%}typename {{l_arg}}{%endif%}
{% if not loop.last %},{% endif -%}
{%- endfor -%}
>{% endif %}
std::istream& operator>>(std::istream& is, {{D_NAME}}{% if DYNAMIC %}
                         <{%- for l_arg in ARG -%}
  {% if "..." in l_arg %}{{l_arg.replace("...","")}}...{% else -%}{{l_arg.split(" ")[-1]}}{% endif %}{% if not loop.last %},{% endif -%}
                         {%- endfor -%}>{% endif %}&){% if DYNAMIC %} {return is;} {% else %};{% endif %}
}
{% endif %}

{%- if AFTER %}
{{AFTER}}
{%- endif %}
