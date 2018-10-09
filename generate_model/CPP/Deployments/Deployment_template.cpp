
#include "Deployments/{{NAME}}.hpp"

{% for l in LINK%}
#include "Links/{{l.TYPE.NAME}}.hpp"
{% endfor %}

{{NAME}}::{{NAME}}() {
  
}

{{NAME}}::~{{NAME}}() {
  
}

void {{NAME}}::init() {
  Deployment::init();

  {%for inst in INSTANCE %}
  this->components_add(&{{inst.NAME}});
  {%endfor%}
}

void {{NAME}}::configuration() {
  Deployment::configuration();

  {%for inst in INSTANCE %}
  this->{{inst.NAME}}.configuration();
  {%endfor%}
}

void {{NAME}}::link() {

  {% for l in LINK %}
  {
    

    {{l.TYPE.NAME}}<{{l.FROM.INTERFACE.INTERFACE.NAME}}>* l = new {{l.TYPE.NAME}}<{{l.FROM.INTERFACE.INTERFACE.NAME}}>({{l.FROM.INSTANCE.NAME}}.{{l.FROM.INTERFACE.NAME}}, &{{l.TO.INSTANCE.NAME}}.{{l.TO.INTERFACE.NAME}});

    l->set_name_from("{{l.FROM.INSTANCE.NAME}}.{{l.FROM.INTERFACE.NAME}}");
    l->set_name_to("{{l.TO.INSTANCE.NAME}}.{{l.TO.INTERFACE.NAME}}");

    this->link_add(l);
  }
  {% endfor %}

  Deployment::link();

  {%for inst in INSTANCE %}
  this->{{inst.NAME}}.connection();
  {%endfor%}
}

void {{NAME}}::start() {
  Deployment::start();

  {%for inst in INSTANCE %}
  this->{{inst.NAME}}.start();
  {%endfor%}
}

void {{NAME}}::stop() {
  Deployment::stop();

  {%for inst in INSTANCE %}
  this->{{inst.NAME}}.stop();
  {%endfor%}
}

void {{NAME}}::quit() {
  
}

