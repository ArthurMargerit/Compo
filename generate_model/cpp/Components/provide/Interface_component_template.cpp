
#include "Components/{{COMPONENT.NAME}}/{{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.NAME}}/{{COMPONENT.NAME}}.hpp"

namespace {{COMPONENT.NAME}} {

  {{INTERFACE.NAME}}_{{NAME}}::{{INTERFACE.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp):composant(comp)
                                                            {%for d in INTERFACE.DATA %},{{d.NAME}}(){%endfor%}{
    return;
  }

  //! Destructor
  {{INTERFACE.NAME}}_{{NAME}}::~{{INTERFACE.NAME}}_{{NAME}}() noexcept {
        return;
  }

  {{COMPONENT.NAME}}& {{INTERFACE.NAME}}_{{NAME}}::get_c() const {
    return *this->composant;
  }


  {% with INTERFACE=INTERFACE, CLS_NAME=INTERFACE.NAME+"_"+NAME%}
  {% include "Components/provide/Function_helper.cpp" with context %}
  {% endwith %}

  {% with NAME=INTERFACE.NAME,
      DATA=INTERFACE.DATA,
      PARENT=INTERFACE.PARENT,
      CLS_NAME=INTERFACE.NAME+"_"+NAME%}
  {% include "Components/provide/Get_Set_helper.cpp" with context %}
  {% endwith %}

} // namespace {{COMPONENT.NAME}}
