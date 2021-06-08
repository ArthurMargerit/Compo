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
    this->get_{{c.LINK.NAME}}().get_{{c.PORT.NAME}}().connect_require({% if "AT" in c%}{{c.AT}},{%endif%}
                                        this->get_{{c.FROM.INSTANCE.NAME}}().{{c.FROM.TYPE.NAME}});
    {% elif "TO" in c%}
    this->get_{{c.LINK.NAME}}().get_{{c.PORT.NAME}}().connect_interface({% if "AT" in c %}{{c.AT}},{% endif %}
                                       this->get_{{c.TO.INSTANCE.NAME}}().get_{{c.TO.TYPE.NAME}}());
    {% endif %}
    {% else %}
    {% if c.FROM and c.FROM.KIND=="set" %}
    // internal interface link
    this->get_{{c.FROM.INSTANCE.NAME}}().{{c.FROM.TYPE.NAME}}.{{c.FROM.KIND}}(&this->get_{{c.TO.INSTANCE.NAME}}().get_{{c.TO.TYPE.NAME}}());
    {% elif c.FROM and c.FROM.KIND=="add" %}
    // internal interface link
    this->get_{{c.FROM.INSTANCE.NAME}}().{{c.FROM.TYPE.NAME}}.{{c.FROM.KIND}}(&this->get_{{c.TO.INSTANCE.NAME}}().get_{{c.TO.TYPE.NAME}}());
    {% else %}
    // internal event link
    this->get_{{c.FROM.INSTANCE.NAME}}().{{c.FROM.TYPE.NAME}}.inscribe(&this->get_{{c.TO.INSTANCE.NAME}}().get_{{c.TO.TYPE.NAME}}());
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
  this->{{inst.NAME}}.main_connect();
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
  this->{{inst.NAME}}.main_disconnect();
  {%endfor%}
}

{% include "helper/namespace_close.hpp" with context%}
