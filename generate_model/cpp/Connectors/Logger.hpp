#pragma once

#include <iostream>
#include "CompoMe/Log.hpp"

{% set i = MAIN.INTERFACES[INTERFACE] %}
#include "Interfaces/{{i.F_NAME}}/{{i.NAME}}.hpp"
#include "Components/Component.hpp"

// require
{% for r in REQUIRE %}
#include "Interfaces/{{r.INTERFACE.F_NAME}}/{{r.INTERFACE.NAME}}.hpp"
{% endfor %}

{% include "helper/namespace_open.hpp" with context %}
class {{NAME}};

{% include "Connectors/Logger_Interface.hpp" with context %}

class {{NAME}} {
 public:
  {{NAME}}():{%for r in REQUIRE %}{{r.NAME}}(NULL),{%endfor%}
            {%for p in PROVIDE %}{{p.NAME}}(this){%endfor%} {
               this->log = _log_output;
               }

 private:
 {%include "provide_require.hpp" with context%}
};
{% include "helper/namespace_close.hpp" with context %}
