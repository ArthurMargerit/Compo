#pragma once

{%if PARENT%}
#include "Deployments/{{PARENT.F_NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Deployments/Deployment.hpp"
{%endif%}

{%for inst in COMPONENT_INSTANCE %}
#include "Components/{{inst.COMPONENT.F_NAME}}.hpp"
{%endfor%}

{%for inst in CONNECTOR_INSTANCE %}
#include "connectors/{{inst.CONNECTOR.F_NAME}}.hpp"
{%endfor%}

{%set l_uniq = []%}
{% for i_link in LINK_INSTANCE %}
    {% if i_link.TYPE.NAME not in l_uniq%}
#include "Links/{{i_link.TYPE.F_NAME}}/{{i_link.TYPE.NAME}}.hpp"
{%set _ = l_uniq.append(i_link.TYPE.NAME)%}
    {%endif%}
{% endfor %}

{% include "helper/namespace_open.hpp" with context %}

class {{NAME}} : public {%if PARENT %}{{PARENT.D_NAME}}{%else%}CompoMe::Deployment{%endif%}
{
 private:
  // COMPONENT
  {%for inst in COMPONENT_INSTANCE %}
  {{inst.COMPONENT.D_NAME}} {{inst.NAME}};
  {%endfor%}

  // CONNECTOR
  {%for inst in CONNECTOR_INSTANCE %}
  {{inst.CONNECTOR.D_NAME}} {{inst.NAME}};
  {%endfor%}

  // DATA
  {%for d in DATA %}
  {{d.TYPE.D_NAME}} {{d.NAME}};
  {%endfor%}

  // LINK
  {%for link in LINK_INSTANCE %}
  {{link.TYPE.D_NAME}} {{link.NAME}};
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

  // GET //////////////////////////////////////////////////////////////////////
  // COMPONENT
  {%for inst in COMPONENT_INSTANCE %}
  {{inst.COMPONENT.D_NAME}}& get_{{inst.NAME}}();
  {%endfor%}

  // CONNECTOR
  {%for inst in CONNECTOR_INSTANCE %}
  {{inst.CONNECTOR.D_NAME}}& get_{{inst.NAME}}();
  {%endfor%}

  // LINK
  {%for link in LINK_INSTANCE %}
  {{link.TYPE.D_NAME}}& get_{{link.NAME}}();
  {%endfor%}

  void save(std::ostream& os) const;
  void load(std::istream& is);
};
{% include "helper/namespace_close.hpp" with context %}
