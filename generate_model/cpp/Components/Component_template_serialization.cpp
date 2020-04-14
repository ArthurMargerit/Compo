#include <iostream>
#include "Components/{{D_NAME.replace('::','/')}}/{{NAME}}.hpp"


{% include "helper/namespace_open.hpp" with context %}
namespace {{NAME}}{
  /////////////////////////////////////////////////////////////////////////////
  //                            LOAD/SAVE                                    //
  /////////////////////////////////////////////////////////////////////////////
void {{NAME}}::save(std::ostream& os) const {
    os << "{";
    os << "type:" << "{{NAME}}";

    {% if PARENT -%}
    os << ",parent:";
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::save(os);
    {%- endif-%}

    {% if PROVIDE -%}
    os << ",provide:{";
    {% for p in PROVIDE %}
    os << "{{p.NAME}}:";
    this->{{p.NAME}}.save(os);
    {% if not loop.last -%}
    os << ",";
    {%- endif-%}
    {% endfor %}
    os << "}";
    {%- endif-%}

    // {% if REQUIRE -%}
    // os << ",require:{";
    // {% for r in REQUIRE %}
    // os << "{{r.NAME}}:" << this->{{r.NAME}};
    // {% if not loop.last -%}
    // os << ",";
    // {%- endif-%}
    // {% endfor %}
    // os << "}";
    // {%- endif-%}

    {% if REQUIRE_LIST -%}
    os << ",require_list:{";
    {% for sc in REQUIRE_LIST %}
    os << "{{sc.NAME}}:[";
    for (auto& i_sc : this->{{sc.NAME}}) {
      os << i_sc;
      if(i_sc != this->{{sc.NAME}}.back()){ os << ","; }
    }
    os << "]";
    {% if not loop.last -%}
    os << ",";
    {%- endif-%}
    {% endfor %}
    os << "}";
    {%- endif-%}

    {% if DATA -%}
    os << ",data:{";
    {% for d in DATA -%}
    os << "{{d.NAME}}:" << this->get_{{d.NAME}}();
    {% if not loop.last -%}
    os << ",";
    {%- endif-%}
    {% endfor -%}
    os << "}";
    {%- endif -%}

    {% if EXTRA -%}
    os << ",extra:{";
    this->_get_extra(os);
    os << "}";
    {% endif -%}

    {% if COMPONENT_INSTANCE -%}
    os << ",components:{";
    {% for sc in COMPONENT_INSTANCE %}
    os << "{{sc.NAME}}:";
    this->{{sc.NAME}}.save(os);
    {% if not loop.last -%}
    os << ",";
    {%- endif-%}
    {% endfor %}
    os << "}";
    {%- endif-%}

    {% if CONNECTOR_INSTANCE -%}
    os << ",connectors:{";
    {% for sc in CONNECTOR_INSTANCE -%}
    os << "{{sc.NAME}}:";

    //this->get_{{sc.NAME}}().save(os);
    os << "TODO";
    {% if not loop.last -%}
    os << ",";
    {%- endif-%}
    {% endfor %}
    os << "}";
    {%- endif-%}

    os << "}";
  }

  {% if EXTRA -%}
  void {{NAME}}::_get_extra(std::ostream& os) const {
    os << "";
  }

  void {{NAME}}::_set_extra(std::istream& is) {
  }
  {% endif -%}

  void {{NAME}}::load(std::istream& is) {
    // TODO
  }

}
{% include "helper/namespace_close.hpp" with context %}
