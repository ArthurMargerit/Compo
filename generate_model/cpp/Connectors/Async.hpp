{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set ic = MAIN.INTERFACES[INTERFACE_ASYNC_CALL] %}
{% set ir = MAIN.INTERFACES[INTERFACE_ASYNC_RETURN] %}

#include "Interfaces/{{i.D_NAME.replace('::','/')}}/{{i.NAME}}.hpp"
#include "Interfaces/{{ir.D_NAME.replace('::','/')}}/{{ir.NAME}}.hpp"
#include "Interfaces/{{ic.D_NAME.replace('::','/')}}/{{ic.NAME}}.hpp"

class {{NAME}} {
 public:
  {%include "Connectors/Async_Interface.hpp"%}

 public:
  {{NAME}}(){%if PROVIDE.__len__ != 0%}:{%endif%}
  {%for p in PROVIDE %}{{p.NAME}}(*this){%if not loop.last %},{%endif%}{%endfor%}{}
  virtual ~{{NAME}}(){}

  {%include "provide_require.hpp" with context%}
};
