#include <iostream>
#include <thread>

#include "types.hpp"
#include "structs.hpp"

{% for comp in COMPOSANTS -%}
#include "{{comp}}/{{comp}}.hpp"
{% endfor %}

int main(int argc, char *argv[])
{
  // CREATION INSTANCE //////////////////////////////////////////
  std::cout << "INIT" << "\n";
  {% for Instance in INSTANCE %}
  {{Instance["COMPOSANT"]["NAME"]}}::{{Instance["COMPOSANT"]["NAME"]}} {{Instance["NAME"]}};
  {%- endfor %}

  // CREATION LINK //////////////////////////////////////////////
  std::cout << "LINK" << "\n";
  {% for link in LINK %}
  {{link["FROM"]["INSTANCE"]["NAME"]}}.{{link["FROM"]["INTERFACE"]["NAME"]}} = &{{link["TO"]["INSTANCE"]["NAME"]}}.{{link["TO"]["INTERFACE"]["NAME"]}};
  std::cout << "{{link["FROM"]["INSTANCE"]["NAME"]}}.{{link["FROM"]["INTERFACE"]["NAME"]}} -> {{link["TO"]["INSTANCE"]["NAME"]}}.{{link["TO"]["INTERFACE"]["NAME"]}}" << "\n";
  {%- endfor %}

  // CONFIGURE //////////////////////////////////////////////////
  std::cout << "CONF" << "\n";
  {% for inst in INSTANCE %}
  {{inst["NAME"]}}.configuration();
  {%- endfor %}

  // start //////////////////////////////////////////////////////

  std::cout << "START" << "\n";
  {% for inst in INSTANCE %}
  auto t_{{inst["NAME"]}} =  std::thread(
                                         &{{inst["COMPOSANT"]["NAME"]}}::{{inst["COMPOSANT"]["NAME"]}}::start,
                                         &{{inst["NAME"]}}
                                     );
                                           //  {{inst["NAME"]}}.start();

  t_{{inst["NAME"]}}.join();
  {%- endfor %}

  // stop ///////////////////////////////////////////////////////
  std::cout << "STOP" << "\n";
  {% for inst in INSTANCE %}
  {{inst["NAME"]}}.stop();
  {%- endfor %}

  std::cout << "END" << "\n";
  return 0;
}
