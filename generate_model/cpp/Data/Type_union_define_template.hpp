#pragma once

{% for i_t in TYPES.values() -%}
{% if i_t.OPTIONS and i_t.OPTIONS.TO_DBUS_STREAM and i_t.DYNAMIC -%}
{% if ("inc/Types/"+i_t.F_NAME+"_dbus.hpp") in generator.files -%}
#include "Types/{{i_t.F_NAME}}_dbus.hpp"
{%else%}
// {{i_t.F_NAME}} is not generate
{%endif -%}
{%endif -%}
{% endfor %}
