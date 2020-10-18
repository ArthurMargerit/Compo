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
enum {{NAME}} {
  {% for enum_name,enum_val in ENUM.items() %}
  {{NAME | upper }}_{{enum_name | upper}} = {{enum_val}}{%if not loop.last%},{%endif%}
  {% endfor %}
};

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
  {{l_arg.split(" ")[-1]}}{%if not loop.last%},{%endif -%}
                         {%- endfor -%}
                         >{% endif %}&){% if DYNAMIC %} {return os;} {% else %};{% endif %}

{%if DYNAMIC%}
template<
{%- for l_arg in ARG -%}
{% if " " in l_arg %}{{l_arg}}{%else%}typename {{l_arg}}{%endif%}
{% if not loop.last %},{% endif -%}
{%- endfor -%}
>{% endif %}
std::istream& operator>>(std::istream& is, {{D_NAME}}{% if DYNAMIC %}
                         <
  {%- for l_arg in ARG -%}
                         {{l_arg.split(" ")[-1]}}{% if not loop.last %},{% endif -%}
  {%- endfor -%}
                         >{% endif %}&){% if DYNAMIC %} {return is;} {% else %};{% endif %}
}
{% endif %}

{%- if AFTER %}
{{AFTER}}
{%- endif %}
