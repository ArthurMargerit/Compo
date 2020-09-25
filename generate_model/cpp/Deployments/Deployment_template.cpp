#include "Deployments/{{F_NAME}}/{{NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context %}
// CONSTRUCTOR ////////////////////////////////////////////////////////////////
{{NAME}}::{{NAME}}():{%if PARENT %}{{PARENT.D_NAME}}(){% else %}Deployment(){% endif %} {

}

{{NAME}}::~{{NAME}}() {

}

// DEPLOYMENT BASIC FUNCTION //////////////////////////////////////////////////
void {{NAME}}::init() {
  {% if PARENT%}
  {{PARENT.D_NAME}}::init();
  {% else %}
  Deployment::init();
  {% endif %}

  {%for inst in LINK_INSTANCE %}
  this->link_add(&{{inst.NAME}});
  {%endfor%}

  {%for inst in COMPONENT_INSTANCE %}
  this->components_add(&{{inst.NAME}});
  {%endfor%}
}

void {{NAME}}::configuration() {
  {% if PARENT%}
  {{PARENT.D_NAME}}::configuration();
  {% else %}
  Deployment::configuration();
  {% endif %}

  {%for inst in LINK_INSTANCE %}
  {%if "WITH" in inst%}
  {%for key,val in inst.WITH.items() %}
  this->{{inst.NAME}}.set_{{key}}({{val}});
  {% endfor %}
  {% endif %}
  this->{{inst.NAME}}.configuration();
  {%endfor%}

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
    // external link
    {% if "FROM" in c %}
    this->get_{{c.LINK.NAME}}().set_out(
                                        {% if "AT" in c%}{{c.AT}},{%endif%}
                                        this->get_{{c.FROM.INSTANCE.NAME}}().{{c.FROM.INTERFACE.NAME}});
    {% elif "TO" in c%}
    this->get_{{c.LINK.NAME}}().set_in(
                                       {% if "AT" in c %}{{c.AT}},{% endif %}
                                       &this->get_{{c.TO.INSTANCE.NAME}}().get_{{c.TO.INTERFACE.NAME}}());
    {% endif %}
    {% else %}
    // internal link
    {% if c.FROM.KIND=="set" %}
    this->get_{{c.FROM.INSTANCE.NAME}}().{{c.FROM.INTERFACE.NAME}}.{{c.FROM.KIND}}(&this->get_{{c.TO.INSTANCE.NAME}}().get_{{c.TO.INTERFACE.NAME}}());
    {% else %}
    this->get_{{c.FROM.INSTANCE.NAME}}().{{c.FROM.INTERFACE.NAME}}.{{c.FROM.KIND}}(&this->get_{{c.TO.INSTANCE.NAME}}().get_{{c.TO.INTERFACE.NAME}}());
    {% endif %}
    {% endif %}
  }
  {% endfor %}

  {%if PARENT -%}
  {{PARENT.D_NAME}}::link();
  {%else-%}
  Deployment::link();
  {%endif-%}

  {%for inst in LINK_INSTANCE %}
  this->{{inst.NAME}}.connect();
  {%endfor%}

  {%for inst in COMPONENT_INSTANCE %}
  this->{{inst.NAME}}.connection();
  {%endfor%}
}

void {{NAME}}::start() {
  {%if PARENT -%}
  {{PARENT.D_NAME}}::start();
  {%else-%}
  Deployment::start();
  {%endif-%}

  {%for inst in COMPONENT_INSTANCE %}
  this->{{inst.NAME}}.start();
  {%endfor%}
}

void {{NAME}}::stop() {
  {%if PARENT -%}
  {{PARENT.D_NAME}}::stop();
  {%else-%}
  Deployment::stop();
  {%endif-%}

  {%for inst in COMPONENT_INSTANCE %}
  this->{{inst.NAME}}.stop();
  {%endfor%}
}

void {{NAME}}::quit() {
  {%if PARENT -%}
  {{PARENT.D_NAME}}::quit();
  {%else-%}
  Deployment::quit();
  {%endif-%}

  {%for inst in LINK_INSTANCE %}
  this->{{inst.NAME}}.disconnect();
  {%endfor%}
}

// GET ////////////////////////////////////////////////////////////////////////
// COMPONENT
{%for inst in COMPONENT_INSTANCE %}
{{inst.COMPONENT.D_NAME}}&
  {{NAME}}::get_{{inst.NAME}}() {
    return this->{{inst.NAME}};
}
{%endfor%}

// CONNECTOR
{%for inst in CONNECTOR_INSTANCE %}
{{inst.CONNECTOR.D_NAME}}&
  {{NAME}}::get_{{inst.NAME}}() {
    return this->{{inst.NAME}};
}
{%endfor%}

// LINK
{%for link in LINK_INSTANCE %}
  {{link.TYPE.D_NAME}}&
   {{NAME}}::get_{{link.NAME}}() {
    return this->{{link.NAME}};
}
{%endfor%}

{% include "helper/namespace_close.hpp" with context%}
