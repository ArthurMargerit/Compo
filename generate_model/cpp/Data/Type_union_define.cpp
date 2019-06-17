#include "Data/{{options.project.name}}.hpp"
{% for k,v in STRUCTS.items() %}
#include "Data/Struct_fac_{{v.NAME}}.hpp"
{%- endfor %}



void init_{{options.project.name}}() {
  {% for k,v in IMPORTS.items() -%}

  {% endfor %}

  {% for k,v in STRUCTS.items() %}
  {{v.NAME}}_fac::get_inst();
  {%- endfor %}

}
