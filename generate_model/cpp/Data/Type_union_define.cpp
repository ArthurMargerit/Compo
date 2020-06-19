#include "Data/{{FILE.replace(".yaml","")}}.hpp"
{% for k,v in STRUCTS.items() %}
#include "Data/{{v.F_NAME}}_fac.hpp"
{%- endfor %}
{% for k,v in ERRORS.items() %}
#include "Errors/{{v.F_NAME}}_fac.hpp"
{%- endfor %}
{% for k,v in COMPONENTS.items() %}
#include "Components/{{v.F_NAME}}_fac.hpp"
{%- endfor %}


void init_{{FILE.replace(".yaml","")}}() {

  static bool already_run=false;
  if(already_run) {
    return;
  }
  already_run = true;

  {% for k,v in IMPORTS.items() -%}
  init_{{k.replace(".yaml","")}}();
  {% endfor %}

  {% for k,v in STRUCTS.items() %}
  {{v.D_NAME}}_fac::get_inst();
  {%- endfor %}

  {% for k,v in ERRORS.items() %}
  {{v.D_NAME}}_fac::get_inst();
  {%- endfor %}

  {% for k,v in COMPONENTS.items() %}
  {{v.D_NAME}}_fac::get_inst();
  {%- endfor %}

}
