#pragma once

#include <ostream>

#include "types.hpp"


{% for key,value in STRUCTS.items() %}
struct {{value["NAME"]}} {

  {%- for value_data in value["DATA"] %}
  {{value_data["TYPE"]["NAME"]}} {{value_data["NAME"]}};
  {%- endfor %}

  {{value["NAME"]}}();

  {{value["NAME"]}}({%- for value_data in value["DATA"] -%}
    {{value_data["TYPE"]["NAME"]}} p_{{value_data["NAME"]}}
    {%- if not loop.last -%}
,
    {%- endif -%}
    {%- endfor %});

};

std::ostream& operator<<(std::ostream& os, const {{value["NAME"]}}& c);


{% endfor %}

