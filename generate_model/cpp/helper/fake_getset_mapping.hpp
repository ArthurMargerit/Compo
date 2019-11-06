{% if INTERFACE.PARENT %}
{%- with INTERFACE=INTERFACE.PARENT, DATA_GENERATED=DATA_GENERATED-%}
{%- include "helper/fake_getset_mapping.hpp" with context -%}
{%- endwith -%}
{% endif %}

// INTERFACE get/set {{INTERFACE.NAME}} ////////////////////////////////////////
{%- for v in INTERFACE.DATA %}
{%if v.NAME not in DATA_GENERATED%}
{%set _ = DATA_GENERATED.append(v.NAME)%}
virtual
  {{v.TYPE.NAME}} get_{{v.NAME}}() const;

virtual
void set_{{v.NAME}}(const {{v.TYPE.NAME}}& {{v.NAME}});
{%endif%}
{%- endfor %}
