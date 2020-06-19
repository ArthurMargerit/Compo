{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set imr  = MAIN.INTERFACES[INTERFACE_MANY_RETURN] %}

#include "Interfaces/{{i.F_NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{imr.F_NAME}}/{{imr.NAME}}.hpp"

#include <vector>
#include <random>

{% include "helper/namespace_open.hpp" with context %}

class {{NAME}} {
 public:

  {% include "Connectors/Distri_many_return_interface.hpp" with context %}

  {{NAME}}():c(*this){}
  virtual ~{{NAME}}(){}

  std::vector<{{i.D_NAME}}*> list_r;
  {{NAME}}_{{imr.NAME}} c;
};
{% include "helper/namespace_close.hpp" with context %}
