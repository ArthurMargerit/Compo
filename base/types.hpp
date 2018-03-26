#pragma once
{% set include_key = [] %}
{% for key,value in TYPES.items() -%}
{%- if "INCLUDE" in value %}
{%- if value["INCLUDE"] not in include_key %}
#include {{value["INCLUDE"]}}
{% set _ = include_key.append(value["INCLUDE"]) -%}
{% endif -%}
{% endif -%}
{% endfor %}


{% for key,value in TYPES.items() %}
{%- if not value["NATIF"] %}
typedef {{value["DEFINITION"]}} {{value["NAME"]}};
{%- endif %}
{%- endfor %}
