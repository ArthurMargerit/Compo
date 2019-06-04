#pragma once
{% for v,k in IMPORTS.items() -%}
#include "Data/{{v.replace(".yaml","")}}.hpp"
{% endfor %}

{% for t,v in TYPES.items() -%}
{% if not v.NATIF %}
#include "Data/Type_{{t}}.hpp"
{%- endif %}
{%- endfor %}
