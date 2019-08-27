// {{NAME}} ///////////////////////////////////////////////////////////////////
{%- for v in DATA %}
// get/set {{v["NAME"]}}
virtual
    {{v.TYPE.NAME}} get_{{v.NAME}}() const  {
      {% if LINK_TO %}
      this->get_c().get_sc_{{LINK_TO.INSTANCE.NAME}}().get_{{LINK_TO.INTERFACE.NAME}}()->get_{{v.NAME}}();
      {% else %}
      return this->{{v.NAME}};
      {% endif %}
}

virtual
void set_{{v.NAME}}(const {{v.TYPE.NAME}} {{v.NAME}})  {
  {% if LINK_TO %}
  this->get_c().get_sc_{{LINK_TO.INSTANCE.NAME}}().get_{{LINK_TO.INTERFACE.NAME}}()->set_{{v.NAME}}({{v.NAME}});
  {% else %}
  this->{{v.NAME}} = {{v.NAME}};
  {% endif %}
}
{%- endfor %}

{% if PARENT %}
{% with NAME=PARENT.NAME, DATA=PARENT.DATA, PARENT=PARENT.PARENT %}
{% include "Components/provide/Get_Set_helper.hpp" with context %}
{% endwith %}
{% endif %}
