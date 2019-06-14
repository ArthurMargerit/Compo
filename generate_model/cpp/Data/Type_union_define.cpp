#include "data/{{options.project.name}}.hpp"

void init_{{options.project.name}}() {
  {% for v,k in IMPORTS.items() -%}

  {% endfor %}

  {% for k,v in STRUCTS.items() -%}
  {% if v.PARENT %}
  {{v.NAME}}_factory::parent_subscribe();
  {%- endif %}
  {%- endfor %}

}
