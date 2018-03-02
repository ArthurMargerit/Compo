#include "types.hpp"
#include "structs.hpp"


{% for key,value in STRUCTS.items() %}

struct {{value["NAME"]}} {
{%- for value_data in value["DATA"] %}
    {{value_data["TYPE"]["NAME"]}} {{value_data["NAME"]}};
{%- endfor %}
};
{% endfor %}
