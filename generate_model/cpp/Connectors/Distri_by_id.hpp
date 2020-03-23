{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set iwi  = MAIN.INTERFACES[INTERFACE_WITH_ID] %}

#include "Interfaces/{{i.D_NAME.replace('::','/')}}/{{i.NAME}}.hpp"
#include "Interfaces/{{iwi.D_NAME.replace('::','/')}}/{{iwi.NAME}}.hpp"

#include <vector>

{% include "helper/namespace_open.hpp" with context %}
class {{NAME}} {
 public:
  {% include "Connectors/Distri_by_id_interface.hpp" with context%}

  {{NAME}}():c(*this){}
  virtual ~{{NAME}}(){}
  std::vector<{{i.D_NAME}}*> list_r;
  {{NAME}}_{{iwi.NAME}} c;
};
{% include "helper/namespace_close.hpp" with context %}
