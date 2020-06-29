{% if INTERFACE.PARENT %}
{%- with START=START,INTERFACE=INTERFACE.PARENT, DATA_GENERATED=DATA_GENERATED-%}
{%- include "helper/fake_getset_mapping.cpp" with context -%}
{%- endwith -%}
{% endif %}

// INTERFACE get/set {{INTERFACE.NAME}} ////////////////////////////////////////
{%- for v in INTERFACE.DATA %}
{%if v.NAME not in DATA_GENERATED%}
{%set _ = DATA_GENERATED.append(v.NAME)%}

{{v.TYPE.D_NAME}} {{START}}_fake_stream::get_{{v.NAME}}() const {
  return {{INTERFACE.NAME}}_fake_stream::get_{{v.NAME}}();
}

void {{START}}_fake_stream::set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& p_{{v.NAME}}) {
  {{INTERFACE.NAME}}_fake_stream::set_{{v.NAME}}( p_{{v.NAME}});
}
{%endif%}
{%- endfor %}
