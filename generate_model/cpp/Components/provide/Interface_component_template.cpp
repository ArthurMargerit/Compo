

#include "Components/{{COMPONENT.F_NAME}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.F_NAME}}.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}

constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}


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


std::ostream &
  {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}::to_stream(std::ostream& os, Serialization_context_export& p_ctx) const {
    os << "{";
    os << "type:" << "{{COMPONENT.D_NAME}}_{{INTERFACE.NAME}}_{{NAME}}";

    {% if INTERFACE.DATA and not LINK_TO  %}
    {% for d in INTERFACE.DATA %}
    os << ",{{d.NAME}}:" << this->get_{{d.NAME}}();
    {% endfor %}
    {% endif %}

    os << "}";
    return os;
  }

std::istream&
  {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}::from_stream(std::istream& is,
                                                              Serialization_context_import& p_ctx) {
    char l_c = is.get();
    if(l_c != '{') {
      std::cerr << "Wrong start: '" <<  l_c << "' != '{'";
      throw "Wrong start: '"  "' != '{'";
    }

    do {
      std::string args;
      std::getline(is, args, ':');

      switch(str2int(args.c_str())) {
      case str2int("type"): {
        auto t = get_word(is, {',','}'});
        if(t.first != "{{COMPONENT.D_NAME}}_{{INTERFACE.NAME}}_{{NAME}}") {
          throw "Wrong Type: ";
        }
        break;
      }

        {% if not LINK_TO %}
        {%- for i_d in INTERFACE.DATA if INTERFACE.HIDE == NULL or d.NAME not in INTERFACE.HIDE %}
      case str2int("{{i_d.NAME}}"):
        {% if Function.model_test.is_struct(i_d.TYPE.D_NAME, MAIN) -%}
        this->{{i_d.NAME}}.from_stream(is, p_ctx);
        {% elif Function.model_test.is_a_pointer_type(i_d.TYPE) -%}
        p_from_stream(is, (Serializable_Item*&) this->{{i_d.NAME}}, p_ctx);
        {% else -%}
        is >> this->{{i_d.NAME}};
        {% endif -%}
        break;
        {% endfor %}
        {% endif %}
      default:
        std::cerr << "wrong attribute: \""<< args <<"\" not in provide {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}";
        throw "wrong attribute: \""+ args +"\" not in provide {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}";
        break;
      }

      l_c = is.get();
    } while(l_c == ',');

    return is;
}


{% include "helper/namespace_close.hpp" with context %}
