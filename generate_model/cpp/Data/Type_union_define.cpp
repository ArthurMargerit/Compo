#include "Data/{{FILE.replace(".yaml","")}}.hpp"
{% for k,v in STRUCTS.items() %}
#include "Data/{{v.NAMESPACE.replace('::' ,'/')}}/Struct_fac_{{v.NAME}}.hpp"
{%- endfor %}

{% for k,v in ERRORS.items() %}
#include "Errors/{{v.D_NAME.replace('::','/')}}_fac.hpp"
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

}
