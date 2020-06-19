#pragma once
{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set im  = MAIN.INTERFACES[INTERFACE_MANY] %}
{% set imr  = MAIN.INTERFACES[INTERFACE_MANY_RETURN] %}
{% set iwi  = MAIN.INTERFACES[INTERFACE_WITH_ID] %}
#include "Interfaces/{{i.F_NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{iwi.F_NAME}}/{{iwi.NAME}}.hpp"
#include <vector>

{% include "helper/namespace_open.hpp" with context %}

class {{NAME}} {
 public:
  {% include "Connectors/Distri_by_id_interface.hpp" with context%}
  {% include "Connectors/Distri_many_interface.hpp" with context%}
  {% include "Connectors/Distri_many_return_interface.hpp" with context%}

  {{NAME}}():cmr(*this),cm(*this),cwi(*this){}
  virtual ~{{NAME}}(){}

  std::vector<{{i.D_NAME}}*> list_r;

  {{NAME}}_{{imr.NAME}} cmr;
  {{NAME}}_{{im.NAME}} cm;
  {{NAME}}_{{iwi.NAME}} cwi;
};

{% include "helper/namespace_close.hpp" with context %}
