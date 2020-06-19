{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set im  = MAIN.INTERFACES[INTERFACE_MANY] %}

#include "Interfaces/{{i.F_NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{im.F_NAME}}/{{im.NAME}}.hpp"

#include <vector>

{% include "helper/namespace_open.hpp" with context %}
class {{NAME}} {
 public:
  {% include "Connectors/Distri_many_interface.hpp" with context %}

  {{NAME}}():c(*this){}
  virtual ~{{NAME}}(){}
  std::vector<{{i.D_NAME}}*> list_r;
  {{NAME}}_{{im.NAME}} c;
};
{% include "helper/namespace_close.hpp" with context %}
