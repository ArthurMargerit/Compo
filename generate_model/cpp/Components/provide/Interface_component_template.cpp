

#include "Components/{{COMPONENT.F_NAME}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.F_NAME}}.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}


  {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}::{{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp):composant(comp)
                                                            {%if not LINK_TO %}{%for d in INTERFACE.DATA %},{{d.NAME}}(){%endfor%}{%endif%}{
    return;
  }

  //! Destructor
  {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}::~{{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}() noexcept {
        return;
  }

  {{COMPONENT.NAME}}& {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}::get_c() const {
    return *this->composant;
  }

{% include "helper/namespace_close.hpp" with context %}
