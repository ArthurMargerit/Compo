#pragma once

{% for v in TYPES.values() -%}
{% if not v.NATIF %}
#include "Types/{{v.F_NAME}}.hpp"
{%- endif %}
{%- endfor %}

{% for v,k in IMPORTS.items() -%}
// {{Function.os.path.basename(k["PATH"])}}
#include "Data/{{Function.os.path.basename(k["PATH"]).replace('.yaml','')}}.hpp"
{% endfor %}

void init_{{Function.os.path.basename(FILE).replace('.yaml','')}}();
