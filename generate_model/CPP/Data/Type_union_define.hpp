#pragma once


{% for t,v in TYPES.items() %}
{% if not v.NATIF %}
#include "Data/Type_{{t}}.hpp"
{% endif %}
{% endfor %}


