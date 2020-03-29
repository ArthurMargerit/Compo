#include "Deployments/{{D_NAME.replace('::','/')}}/{{NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context%}
void {{NAME}}::save(std::ostream& os) const {
  os << "{";
  os << "addr:" << (void*)this;
  os << ",type:" << "{{NAME}}";

  {% if PARENT -%}
  os << ",parent:";
  {{PARENT.D_NAME}}::save(os);
  {%- endif-%}

  {% if DATA -%}
  os << ",data: {";
  {% for d in DATA %}
  os << "{{d.NAME}}:" << this->{{d.NAME}};
  {% endfor %}
  os << "}";
  {% endif %}
  os << ",components_instances: [";
  for (auto& i_sc : this->components) {
    os << i_sc;
    if(i_sc != this->components.back()){ os << ","; }
  }
  os << "]";

  // // os << ",connector_instance: [";
  // // for (auto& i_sc : this->connector_instance) {
  // //   os << i_sc;
  // //   if(i_sc != this->connector_instance.back()){ os << ","; }
  // // }
  // // os << "]";

  // os << ",links_instances: [";
  // for (auto& i_sc : this->links) {
  //   os << i_sc;
  //   if(i_sc != this->links.back()){ os << ","; }
  // }
  os << "]";
  os << "}";
               }

void {{NAME}}::load(std::istream& is) {
  // TODO
               }

{% include "helper/namespace_close.hpp" with context%}
