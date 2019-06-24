#pragma once

{% if INCLUDE %}
{% if INCLUDE.__class__ == str %}
#include {{INCLUDE}}
{%elif INCLUDE.__class__ == list %}
{%for l_include in INCLUDE %}
#include {{l_include}}
{%endfor%}
{%else%}
#include {{INCLUDE}}
{%endif%}
{%endif%}


{%- if not NATIF %}
{%- if BEFORE %}
{{BEFORE}}
{%- endif %}

{% if DEFINITION %}
{% if DYNAMIC %}
template <
{%-for l_arg in ARG -%}
  typename {{l_arg}}{%if not loop.last%},{%endif -%}
{%-endfor-%}
> using {{NAME}} = {{DEFINITION}};
{%else%}
using {{NAME}} = {{DEFINITION}};
{%endif%}

{% elif ENUM %}
typedef enum {
  {% for enum_name,enum_val in ENUM.items() %}
  {{NAME | upper }}_{{enum_name | upper}} = {{enum_val}}{%if not loop.last%},{%endif%}
  {% endfor %}
} {{NAME}};
{% endif %}

{% endif %}

{%if TOSTRING%}
#include <istream>
#include <ostream>
{%if DYNAMIC%}
template<
{%-for l_arg in ARG -%}
  typename {{l_arg}}{%if not loop.last%},{%endif -%}
{%-endfor-%}
>{%endif%}
std::ostream& operator<<(std::ostream& os, const {{NAME}}{%if DYNAMIC%}
                         <
  {%-for l_arg in ARG -%}
                         {{l_arg}}{%if not loop.last%},{%endif -%}
  {%-endfor-%}
                         >{%endif%}&){%if DYNAMIC%} {return os;} {%else%};{%endif%}

{%if DYNAMIC%}
template<
{%-for l_arg in ARG -%}
  typename {{l_arg}}{%if not loop.last%},{%endif -%}
{%-endfor-%}
>{%endif%}
std::istream& operator>>(std::istream& is, {{NAME}}{%if DYNAMIC%}
                         <
  {%-for l_arg in ARG -%}
                         {{l_arg}}{%if not loop.last%},{%endif -%}
  {%-endfor-%}
                         >{%endif%}&){%if DYNAMIC%} {return is;} {%else%};{%endif%}
{%endif%}

{%- if AFTER %}
{{AFTER}}
{%- endif %}
