{% for comp in COMPOSANTS %}

#include "{{comp}}.hpp"
{% endfor %}

int main(int argc, char *argv[])
{
  // CREATION INSTANCE //////////////////////////////////////////
  {% for Instance in INSTANCE %}
  {{Instance["COMPOSANT"]["NAME"]}} {{Instance["NAME"]}};
  {%- endfor %}

  // CREATION LINK //////////////////////////////////////////////
  {% for link in LINK %}

  {% endfor %}

  // CONFIGURE //////////////////////////////////////////////////
  {% for inst in INSTANCE %}
  {{inst["NAME"]}}.configuration();
  {% endfor %}

  // start //////////////////////////////////////////////////////
  {% for inst in INSTANCE %}
  {{inst["NAME"]}}.start();
  {% endfor %}

  // stop ///////////////////////////////////////////////////////
  {% for inst in INSTANCE %}
  {{inst["NAME"]}}.stop();
  {% endfor %}

  return 0;
}
