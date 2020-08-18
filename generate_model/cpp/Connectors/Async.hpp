#include <iostream>

{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set ic = MAIN.INTERFACES[INTERFACE_ASYNC_CALL] %}
{% set ir = MAIN.INTERFACES[INTERFACE_ASYNC_RETURN] %}

#include "Interfaces/{{i.F_NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{ir.F_NAME}}/{{ir.NAME}}.hpp"
#include "Interfaces/{{ic.F_NAME}}/{{ic.NAME}}.hpp"

#include "Components/Component.hpp"
#include "connectors/Async/Async_Connector.hpp"
#include "connectors/Async/Async_Call.hpp"

{%include "helper/namespace_open.hpp" %}

class {{NAME}};

{%include "Connectors/Async_Interface.hpp"%}

class {{NAME}}: public CompoMe::Async::Async_Connector {
 public:
  {{NAME}}();
  virtual ~{{NAME}}();

  {%include "provide_require.hpp" with context%}
};

{%include "helper/namespace_close.hpp" %}
