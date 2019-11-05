#pragma once

{% set i = MAIN.INTERFACES[INTERFACE] %}

#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"

class {{NAME}} {

  {% include "Connectors/Logger_Interface.hpp" with context %}

 public:

  {{NAME}}(std::ostream& p_os = std::cout):os(&p_os)
            {%for p in PROVIDE %},{{p.NAME}}(this){%endfor%} {
  }

  std::ostream* os = NULL;
  
  {%include "provide_require.hpp" with context%}
};
