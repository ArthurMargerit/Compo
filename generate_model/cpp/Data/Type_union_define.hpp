#pragma once
{% for v,k in IMPORTS.items() -%}
#include "Data/{{v.replace('.yaml','')}}.hpp"
{% endfor %}

{% for v in TYPES.values() -%}
{% if not v.NATIF %}
#include "Data/{{v.D_NAME.replace('::', '/')}}.hpp"
{%- endif %}
{%- endfor %}

void init_{{FILE.replace('.yaml','')}}();
