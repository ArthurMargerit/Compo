{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set iwi  = MAIN.INTERFACES[INTERFACE_WITH_ID] %}

#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{iwi.NAME}}/{{iwi.NAME}}.hpp"

#include <vector>

class {{NAME}} {
 public:
  {% include "Distri_by_id_interface.hpp" with context%}

  {{NAME}}():c(*this){}
  virtual ~{{NAME}}(){}
  std::vector<{{i.NAME}}*> list_r;
  {{NAME}}_{{iwi.NAME}} c;
};
