{% for Composant in Composants %}
#include "{{composant}}.hpp"
{% endfor %}

int main(int argc, char *argv[])
{
  // CREATION INSTANCE //////////////////////////////////////////
  {% for Instance in Instances %}
  {{Instance.type}} {{Instance.name}};
  {% endfor %}

  // CREATION LINK //////////////////////////////////////////////
  {% for Link in Links %}
  {{Link.to}}.connect({{Link.Receptacle}});
  {% endfor %}

  // CONFIGURE //////////////////////////////////////////////////
  {% for Instance in Instances %}
  {{Instance.name}}.configuration();
  {% endfor %}

  // start //////////////////////////////////////////////////////
  {% for Instance in Instances %}
  {{Instance.name}}.start();
  {% endfor %}

  // stop ///////////////////////////////////////////////////////
  {% for Instance in Instances %}
  {{Instance.name}}.stop();
  {% endfor %}

  return 0;
}
