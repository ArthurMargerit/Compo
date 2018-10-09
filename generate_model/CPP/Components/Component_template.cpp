
#include <iostream>

#include "Components/{{NAME}}/{{NAME}}.hpp"

namespace {{NAME}}{

  {{NAME}}::{{NAME}}()

  {%for provide in PROVIDE%}
  {% if loop.first  %}:{% endif %}
  {{provide["NAME"]}}(this){%- if not loop.last%},{% endif %}
  {% endfor %}
                      {
                        std::cout << "--CONST : {{NAME}}" << std::endl;
                        return;
                      }


  //! Destructor
  {{NAME}}::~{{NAME}}() noexcept
                       {
                         std::cout << "--DEST  : {{NAME}}" << std::endl;
                         return;
                       }


  void {{NAME}}::configuration() {
    std::cout << "--CONF  : {{NAME}}" << std::endl;
    return;
  }

  void {{NAME}}::connection() {
    std::cout << "--CONECT: {{NAME}}" << std::endl;
    return;
  }

  void {{NAME}}::start() {
    std::cout << "--START : {{NAME}}" << std::endl;
    return;
  }


  void {{NAME}}::step() {
    std::cout << "--STEP  : {{NAME}}" << std::endl;
    return;
  }


  void {{NAME}}::stop() {
    std::cout << "--STOP  : {{NAME}}" << std::endl;
    return;
  }

  void {{NAME}}::status()
                   {
                     std::cout << "--STATUS: {{NAME}}" << std::endl;
                     return;
                   }

  {% for f in FUNCTION %}
  {{f["RETURN"]["NAME"]}} {{NAME}}::{{f["NAME"]}}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"]}}
    {%- if not loop.last%},{% endif -%}
    {%- endfor-%}
    )
   {

   }
  {% endfor %}

}
