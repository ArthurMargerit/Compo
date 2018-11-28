
#include <iostream>

#include "Components/{{NAME}}/{{NAME}}.hpp"

namespace {{NAME}}{

  {{NAME}}::{{NAME}}()
  {%- if PROVIDE.__len__() != 0  or REQUIRE.__len__() != 0 or DATA.__len__() !=0 -%}
  :
  {%- endif -%}
  {%- if PROVIDE.__len__() %}
  /* PROVIDE */
  {% endif -%}
  {%-for provide in PROVIDE-%}
  {{provide["NAME"]}}(this){%- if not loop.last-%},{%- endif -%}
  {%- endfor -%}
  {%- if REQUIRE.__len__() != 0 and PROVIDE.__len__() !=0  -%},{%- endif -%}
  {%- if REQUIRE.__len__() %}
  /* REQUIRE */
  {% endif -%}
  {%-for req in REQUIRE-%}
  {{req["NAME"]}}(NULL){%- if not loop.last-%},{%- endif -%}
  {%- endfor -%}
  {%-if DATA.__len__() != 0  and (PROVIDE.__len__() != 0  or REQUIRE.__len__() != 0) -%},{%- endif -%}
  {%- if DATA.__len__() %}
  /* DATA */
  {% endif -%}
  {%- for value_data in DATA -%}
  {{value_data["NAME"]}}({%- with TYPE=value_data.TYPE, def=value_data.DEFAULT-%}
                         {%- include "helper/lap.cpp" with context -%}
                         {%- endwith -%})
                         {%- if not loop.last -%},{%- endif -%}
                         {%- endfor %}
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
     {% if "DEFAULT" in f.RETURN%}
     return {{f.RETURN.DEFAULT}};
     {% else %}
     return {{f.RETURN.NAME}}();
     {% endif %}
   }
  {% endfor %}

}
