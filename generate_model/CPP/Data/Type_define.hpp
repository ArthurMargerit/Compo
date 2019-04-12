#pragma once
{% set include_key = [] %}
{% for key,value in TYPES.items() -%}
{%- if "INCLUDE" in value -%}
{%- if value["INCLUDE"] not in include_key -%}
#include {{value["INCLUDE"]}}
{% set _ = include_key.append(value["INCLUDE"]) -%}
{% endif -%}
{% endif -%}
{% endfor -%}

{% for key,value in TYPES.items() %}

{%- if not value["NATIF"] %}
{%- if "BEFORE" in value %}
{{value["BEFORE"]}}
{%- endif %}

{% if "DEFINITION" in value %}
typedef {{value["DEFINITION"]}} {{value["NAME"]}};
{% elif "ENUM" in value %}
typedef {
  {% for enum_name,enum_val in value["ENUM"].items() %}
 {{VALUE["NAME"] | upper }}_{{enum_name}} = enum_val;
{% endfor %}
} {{VALUE["NAME"]}};
{% endif %}

{%- if "AFTER" in value %}
{{value["AFTER"]}}
{%- endif %}
{%- endif %}


{%- endfor %}
