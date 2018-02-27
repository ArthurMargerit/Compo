#include <iostream>

{% for comp in COMPOSANTS -%}
#include "{{comp}}.hpp"
{% endfor %}

int main(int argc, char *argv[])
{
  // CREATION INSTANCE //////////////////////////////////////////
  std::cout << "INIT" << "\n";
  {% for Instance in INSTANCE %}
  {{Instance["COMPOSANT"]["NAME"]}} {{Instance["NAME"]}};
  {%- endfor %}

  // CREATION LINK //////////////////////////////////////////////
  std::cout << "LINK" << "\n";
  {% for link in LINK %}
  std::cout << "{{link["FROM"]}}"
            << " --> "
            << "{{link["TO"]}}" << "\n";
  {{link["FROM"]}} = &{{link["TO"]}};
  {%- endfor %}

  // CONFIGURE //////////////////////////////////////////////////
  std::cout << "CONF" << "\n";
  {% for inst in INSTANCE %}
  {{inst["NAME"]}}.configuration();
  {%- endfor %}

  // start //////////////////////////////////////////////////////
  std::cout << "START" << "\n";
  {% for inst in INSTANCE %}
  {{inst["NAME"]}}.start();
  {%- endfor %}

  // stop ///////////////////////////////////////////////////////
  std::cout << "STOP" << "\n";
  {% for inst in INSTANCE %}
  {{inst["NAME"]}}.stop();
  {%- endfor %}

  std::cout << "END" << "\n";
  return 0;
}
