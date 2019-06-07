#pragma once
{% if INCLUDE %}
#include {{INCLUDE}}
{% endif %}

{%- if not NATIF %}
{%- if BEFORE %}
{{BEFORE}}
{%- endif %}

{% if DEFINITION %}
typedef {{DEFINITION}} {{NAME}};
{% elif ENUM %}
typedef enum {
  {% for enum_name,enum_val in ENUM.items() %}
  {{NAME | upper }}_{{enum_name | upper}} = {{enum_val}}{%if not loop.last%},{%endif%}
  {% endfor %}
} {{NAME}};
{% endif %}

{%- if AFTER %}
{{AFTER}}
{%- endif %}

{%- endif %}
