
#include "Deployments/{{NAME}}/{{NAME}}.hpp"


{{NAME}}::{{NAME}}() {

}

{{NAME}}::~{{NAME}}() {

}

void {{NAME}}::init() {
  Deployment::init();

  {%for inst in COMPONENT_INSTANCE %}
  this->components_add(&{{inst.NAME}});
  {%endfor%}
}

void {{NAME}}::configuration() {
  Deployment::configuration();

  {%for inst in COMPONENT_INSTANCE %}
  {%if "WITH" in inst%}
  {%for key,val in inst.WITH.items() %}
  this->{{inst.NAME}}.set_{{key}}({{val}});
  {% endfor %}
  {% endif %}
  this->{{inst.NAME}}.configuration();
  {%endfor%}
}

void {{NAME}}::link() {

  {% for c in CONNECTION %}
  {
    {% if "LINK" in c %}

    {% if "WITH" in c.LINK %}
    {%for key,val in c.LINK.WITH.items() %}
    this->get_{{c.LINK.NAME}}().set_{{key}}({{val}});
    {% endfor %}
    {% endif %}

    this->get_{{c.LINK.NAME}}().connect();
    this->link_add(&this->get_{{c.LINK.NAME}}());
    {% else %}

    {{c.FROM.INSTANCE.NAME}}.{{c.FROM.KIND}}_{{c.FROM.INTERFACE.NAME}}(&{{c.TO.INSTANCE.NAME}}.get_{{c.TO.INTERFACE.NAME}}());
    {% endif %}

  }
  {% endfor %}

  {%if PARENT -%}
  {{PARENT["NAME"]}}::link();
  {%else-%}
  Deployment::link();
  {%endif-%}

  {%for inst in COMPONENT_INSTANCE %}
  this->{{inst.NAME}}.connection();
  {%endfor%}
}

void {{NAME}}::start() {
  {%if PARENT -%}
  {{PARENT["NAME"]}}::start();
  {%else-%}
  Deployment::start();
  {%endif-%}

  {%for inst in COMPONENT_INSTANCE %}
  this->{{inst.NAME}}.start();
  {%endfor%}
}

void {{NAME}}::stop() {
  {%if PARENT -%}
  {{PARENT["NAME"]}}::stop();
  {%else-%}
  Deployment::stop();
  {%endif-%}

  {%for inst in COMPONENT_INSTANCE %}
  this->{{inst.NAME}}.stop();
  {%endfor%}
}

void {{NAME}}::quit() {
  {%if PARENT -%}
  {{PARENT["NAME"]}}::quit();
  {%else-%}
  Deployment::quit();
  {%endif-%}
}

{%for inst in COMPONENT_INSTANCE %}
{{inst.COMPONENT.NAME}}::{{inst.COMPONENT.NAME}}&
  {{NAME}}::get_{{inst.NAME}}() {
    return this->{{inst.NAME}};
}
{%endfor%}
