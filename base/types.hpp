#pragma once

{% for key,value in TYPES.items() %}
typedef {{value["DEFINITION"]}} {{value["NAME"]}} ;
{% endfor %}
