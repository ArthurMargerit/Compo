{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set ic = MAIN.INTERFACES[INTERFACE_ASYNC_CALL] %}
{% set ir = MAIN.INTERFACES[INTERFACE_ASYNC_RETURN] %}

#include "Interfaces/{{i.D_NAME.replace('::','/')}}/{{i.NAME}}.hpp"
#include "Interfaces/{{ir.D_NAME.replace('::','/')}}/{{ir.NAME}}.hpp"
#include "Interfaces/{{ic.D_NAME.replace('::','/')}}/{{ic.NAME}}.hpp"

#include "Interfaces/{{i.D_NAME.replace('::','/')}}/{{i.NAME}}_fake.hpp"
#include "Interfaces/{{ir.D_NAME.replace('::','/')}}/{{ir.NAME}}_fake.hpp"
#include "Interfaces/{{ic.D_NAME.replace('::','/')}}/{{ic.NAME}}_fake.hpp"

#include "Components/Component.hpp"

{%include "helper/namespace_open.hpp" %}

class {{NAME}};

{%include "Connectors/Async_Interface.hpp"%}

class {{NAME}} {
 public:
  {{NAME}}();
  virtual ~{{NAME}}();

  {%include "provide_require.hpp" with context%}
};

{%include "helper/namespace_close.hpp" %}
