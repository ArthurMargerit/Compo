#pragma once

{%if PARENT%}
#include "Deployments/{{PARENT.NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Deployments/Deployment.hpp"
{%endif%}

{%for inst in COMPONENT_INSTANCE %}
#include "Components/{{inst.COMPONENT.NAME}}/{{inst.COMPONENT.NAME}}.hpp"
{%endfor%}

{%for inst in CONNECTOR_INSTANCE %}
#include "connectors/{{inst.CONNECTOR.NAME}}.hpp"
{%endfor%}


{%set l_uniq = []%}
{% for i_link in LINK_INSTANCE %}
    {% if i_link.TYPE.NAME not in l_uniq%}
#include "Links/{{i_link.TYPE.NAME}}/{{i_link.TYPE.NAME}}.hpp"
{%set _ = l_uniq.append(i_link.TYPE.NAME)%}
    {%endif%}
{% endfor %}


class {{NAME}} : public {%if PARENT %}{{PARENT.NAME}}{%else%}Deployment{%endif%}
{
 private:
  {%for inst in COMPONENT_INSTANCE %}
  {{inst.COMPONENT.NAME}}::{{inst.COMPONENT.NAME}} {{inst.NAME}};
  {%endfor%}

  {%for link in LINK_INSTANCE %}
  {{link.TYPE.NAME}} {{link.NAME}};
  {%endfor%}

 public:

  {{NAME}}();
  virtual ~{{NAME}}();

  {%if PARENT%}
  virtual void init();
  virtual void configuration();
  virtual void link();
  virtual void start();
  virtual void stop();
  virtual void quit();

  {%else%}
  void init() override;
  void configuration() override;
  void link() override;
  void start() override;
  void stop() override;
  void quit() override;
  {%endif%}

  {%for inst in COMPONENT_INSTANCE %}
  {{inst.COMPONENT.NAME}}::{{inst.COMPONENT.NAME}}& get_{{inst.NAME}}();
  {%endfor%}

  {%for inst in CONNECTOR_INSTANCE %}
  {{inst.CONNECTOR.NAME}} {{inst.NAME}};
  {%endfor%}

  {%for link in LINK_INSTANCE %}
  {{link.TYPE.NAME}}& get_{{link.NAME}}(){
    return this->{{link.NAME}};
  }
  {%endfor%}


};
