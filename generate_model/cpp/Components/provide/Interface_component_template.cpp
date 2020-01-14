
#include "Components/{{COMPONENT.NAME}}/{{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.NAME}}/{{COMPONENT.NAME}}.hpp"

namespace {{COMPONENT.NAME}} {

  {{INTERFACE.NAME}}_{{NAME}}::{{INTERFACE.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp):composant(comp)
                                                            {%if not LINK_TO %}{%for d in INTERFACE.DATA %},{{d.NAME}}(){%endfor%}{%endif%}{
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

  void {{INTERFACE.NAME}}_{{NAME}}::save(std::ostream& os) const {
    os << "{";
    os << "type:" << "{{INTERFACE.NAME}}_{{NAME}}";

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


  void {{INTERFACE.NAME}}_{{NAME}}::load(std::istream& is) {

  }

} // namespace {{COMPONENT.NAME}}
