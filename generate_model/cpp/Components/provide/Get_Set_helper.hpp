// {{NAME}} ///////////////////////////////////////////////////////////////////
{%- for v in DATA %}
// get/set {{v.NAME}}
{{v.TYPE.D_NAME}} get_{{v.NAME}}() const override;
void set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}}) override;
{%- endfor %}

{% if PARENT %}
{% with NAME=PARENT.NAME, DATA=PARENT.DATA, PARENT=PARENT.PARENT %}
{% include "Components/provide/Get_Set_helper.hpp" with context %}
{% endwith %}
{% endif %}
