
#include "Structs/{{F_NAME}}_builder.hpp"
#include "Structs/{{F_NAME}}_fac.hpp"

{%include "helper/namespace_open.hpp" with context %}
{{NAME}}_builder::{{NAME}}_builder()
{%if PARENT %}:{{PARENT.D_NAME}}_builder(){%endif%}
{%if DATA %}{%if not PARENT %}:{%else%},{%endif%}{%endif%}
{%for d in DATA%}
  {{d.NAME}}()
  {%if not loop.last%},{%endif%}
{% endfor %}
 {}
{{NAME}}_builder::~{{NAME}}_builder() {}


{% if PARENT %}
{% for i_d in  Function.model_get.get_all_field(PARENT.DATA,PARENT.PARENT) %}
{{NAME}}_builder& {{NAME}}_builder::set_{{i_d.NAME}}(const {{i_d.TYPE.D_NAME}}& p_{{i_d.NAME}}){
  {{PARENT.NAME}}_builder::set_{{i_d.NAME}}(p_{{i_d.NAME}});
  return *this;
}
{% endfor %}
{% endif %}

{%for i_d in DATA %}
{{NAME}}_builder& {{NAME}}_builder::set_{{i_d.NAME}}(const {{i_d.TYPE.D_NAME}}& p_{{i_d.NAME}}){
    this->{{i_d.NAME}} = p_{{i_d.NAME}};
    return *this;
}
{% endfor %}

void {{NAME}}_builder::asign({{D_NAME}}& p_{{NAME}}) {
  {% if PARENT %}
  {{PARENT.D_NAME}}_builder::asign(p_{{NAME}});
  {% endif %}

  {%for i_d in DATA -%}
  p_{{NAME}}.set_{{i_d.NAME}}(this->{{i_d.NAME}});
  {% endfor %}
}

{{NAME}} {{NAME}}_builder::build() {
    {{NAME}} p_this;
    this->asign(p_this);
    return p_this;
}

{{NAME}}* {{NAME}}_builder::build_p() {
  {{NAME}}* p_this = new {{NAME}}();
  this->asign(*p_this);
  return p_this;
}

std::shared_ptr<{{NAME}}> {{NAME}}_builder::build_sp() {
  auto p_this = std::make_shared<{{NAME}}>();
  this->asign(*p_this);
  return p_this;
}
{%include "helper/namespace_close.hpp" with context %}
