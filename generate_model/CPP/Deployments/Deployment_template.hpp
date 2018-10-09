#pragma once

#include "Deployments/Deployment.hpp"

{%for inst in INSTANCE %}
#include "Components/{{inst.COMPONENT.NAME}}/{{inst.COMPONENT.NAME}}.hpp"
{%endfor%}



class {{NAME}} : public Deployment
{
 private:
  {%for inst in INSTANCE %}
  {{inst.COMPONENT.NAME}}::{{inst.COMPONENT.NAME}} {{inst.NAME}};
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
