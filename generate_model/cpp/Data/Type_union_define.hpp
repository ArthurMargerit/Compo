#pragma once

{% for v in TYPES.values() -%}
{% if not v.NATIF or (OPTIONS and OPTIONS.TO_DBUS_STREAM) %}
#include "Types/{{v.F_NAME}}.hpp"
{%- endif %}
{%- endfor %}

{% for v,k in IMPORTS.items() -%}
// {{Function.os.path.basename(k["PATH"])}}
#include "Data/{{Function.os.path.basename(k["PATH"]).replace('.yaml','')}}.hpp"
{% endfor %}

#include "Data/{{Function.os.path.basename(FILE).replace('.yaml','')}}_template.hpp"

void init_{{Function.os.path.basename(FILE).replace('.yaml','')}}();
