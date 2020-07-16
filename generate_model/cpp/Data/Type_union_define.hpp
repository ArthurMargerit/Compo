#pragma once
{% for v,k in IMPORTS.items() -%}
#include "Data/{{v.replace('.yaml','')}}.hpp"
{% endfor %}

{% for v in TYPES.values() -%}
{% if not v.NATIF %}
#include "Types/{{v.F_NAME}}.hpp"
{%- endif %}
{%- endfor %}

void init_{{FILE.replace('.yaml','')}}();
