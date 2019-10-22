{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set imr  = MAIN.INTERFACES[INTERFACE_MANY_RETURN] %}

#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{imr.NAME}}/{{imr.NAME}}.hpp"

#include <vector>
#include <random>

class {{NAME}} {
 public:

  {% include "Distri_many_return_interface.hpp" with context %}

  {{NAME}}():c(*this){}
  virtual ~{{NAME}}(){}

  std::vector<{{i.NAME}}*> list_r;
  {{NAME}}_{{imr.NAME}} c;
};
