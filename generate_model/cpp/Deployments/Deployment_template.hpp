#pragma once

#include "Deployments/Deployment.hpp"

{%for inst in INSTANCE %}
#include "Components/{{inst.COMPONENT.NAME}}/{{inst.COMPONENT.NAME}}.hpp"
{%endfor%}

{%for linker in LINKER_INSTANCE %}
#include "Linkers/{{linker.TYPE.NAME}}/{{linker.TYPE.NAME}}.hpp"
{%endfor%}

{% for l in LINK_INSTANCE %}
    {% if "LINKER" not in l%}
#include "Links/{{l.TYPE.NAME}}/{{l.TYPE.NAME}}.hpp"
    {%endif%}
{% endfor %}


class {{NAME}} : public {%if PARENT %}{{PARENT.NAME}}{%else%}Deployment{%endif%}
{
 private:
  {%for inst in INSTANCE %}
  {{inst.COMPONENT.NAME}}::{{inst.COMPONENT.NAME}} {{inst.NAME}};
  {%endfor%}


  {%for linker in LINKER_INSTANCE %}
  {{linker.TYPE.NAME}} {{linker.NAME}};
  {%endfor%}

  {%for link in LINK_INSTANCE %}
  {{link.TYPE.NAME}} {{link.NAME}};
  {%endfor%}

 public:

  {{NAME}}();
  virtual ~{{NAME}}();

  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();
};
