
#include "Components/{{COMPONENT.NAME}}/{{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.NAME}}/{{COMPONENT.NAME}}.hpp"

namespace {{COMPONENT.NAME}}
{

  {{INTERFACE.NAME}}_{{NAME}}::{{INTERFACE.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp):composant(comp){
    return;
  }

  //! Destructor
  {{INTERFACE.NAME}}_{{NAME}}::~{{INTERFACE.NAME}}_{{NAME}}() noexcept {
        return;
  }

  {% with INTERFACE=INTERFACE, CLS_NAME=INTERFACE.NAME+"_"+NAME%}
  {% include "Components/provide/Function_helper.cpp" with context %}
  {% endwith %}

}; // namespace {{COMPONENT.NAME}}

