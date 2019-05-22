{% if INTERFACE.PARENT %}
{%- with START=START,INTERFACE=INTERFACE.PARENT, DATA_GENERATED=DATA_GENERATED-%}
{%- include "helper/fake_getset_mapping.cpp" with context -%}
{%- endwith -%}
{% endif %}

// INTERFACE get/set {{INTERFACE.NAME}} ////////////////////////////////////////
{%- for v in INTERFACE.DATA %}
{%if v.NAME not in DATA_GENERATED%}
{%set _ = DATA_GENERATED.append(v.NAME)%}

{{v.TYPE.NAME}} {{START}}_fake::get_{{v.NAME}}() const {
  return {{INTERFACE.NAME}}_fake::get_{{v.NAME}}();
                                                       }

void {{START}}_fake::set_{{v.NAME}}(const {{v.TYPE.NAME}} p_{{v.NAME}}) {
  {{INTERFACE.NAME}}_fake::set_{{v.NAME}}( p_{{v.NAME}});
                      }
{%endif%}
{%- endfor %}
