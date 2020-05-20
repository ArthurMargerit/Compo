
#include "Components/{{COMPONENT.D_NAME.replace('::','/')}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.D_NAME.replace('::','/')}}.hpp"

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


  {% with INTERFACE=INTERFACE, CLS_NAME=COMPONENT.NAME+"_"+INTERFACE.NAME+"_"+NAME%}
  {% include "Components/provide/Function_helper.cpp" with context %}
  {% endwith %}

  {% with NAME=INTERFACE.NAME,
      DATA=INTERFACE.DATA,
      PARENT=INTERFACE.PARENT,
      CLS_NAME=COMPONENT.NAME+"_"+INTERFACE.NAME+"_"+NAME%}
  {% include "Components/provide/Get_Set_helper.cpp" with context %}
  {% endwith %}

  void {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}::save(std::ostream& os) const {
    os << "{";
    os << "type:" << "{{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}";

    {% if INTERFACE.DATA and not LINK_TO  %}
    os << ",data:{";
    {% for d in INTERFACE.DATA %}
    os << "{{d.NAME}}:" << this->get_{{d.NAME}}();
    {% if not loop.last -%}
    os << ",";
    {%- endif-%}
    {% endfor %}
    os << "}";
    {% endif %}

    os << "}";
  }


  void {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}::load(std::istream& is) {

  }

{% include "helper/namespace_close.hpp" with context %}
