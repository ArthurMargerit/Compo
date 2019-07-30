// {{NAME}} ///////////////////////////////////////////////////////////////////
{%- for v in DATA %}
// get/set {{v["NAME"]}}
virtual
    {{v.TYPE.NAME}} get_{{v.NAME}}() const  {
      return {{v.NAME}};
}

virtual
void set_{{v.NAME}}(const {{v.TYPE.NAME}} {{v.NAME}})  {
  this->{{v.NAME}} = {{v.NAME}};
}
{%- endfor %}

{% if PARENT %}
{% with NAME=PARENT.NAME, DATA=PARENT.DATA, PARENT=PARENT.PARENT %}
{% include "Components/provide/Get_Set_helper.hpp" with context %}
{% endwith %}
{% endif %}
