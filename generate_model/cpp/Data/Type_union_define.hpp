#pragma once
{% for v,k in IMPORTS.items() -%}
#include "Data/{{v.replace('.yaml','')}}.hpp"
{% endfor %}

{% for v in TYPES.values() -%}
{% if not v.NATIF %}
#include "Data/{{v.NAMESPACE.replace('::', '/')}}/Type_{{v.NAME}}.hpp"
{%- endif %}
{%- endfor %}

void init_{{FILE.replace('.yaml','')}}();
