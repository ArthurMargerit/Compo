{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set im  = MAIN.INTERFACES[INTERFACE_MANY] %}

#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{im.NAME}}/{{im.NAME}}.hpp"

#include <vector>

class {{NAME}} {
 public:
  {% include "Distri_many_interface.hpp" with context %}

  {{NAME}}():c(*this){}
  virtual ~{{NAME}}(){}
  std::vector<{{i.NAME}}*> list_r;
  {{NAME}}_{{im.NAME}} c;
};
