#include <iostream>
#include "Serialization_context.hpp"
#include "Components/{{D_NAME.replace('::','/')}}/{{NAME}}.hpp"


{% include "helper/namespace_open.hpp" with context %}

namespace {{NAME}}{

  std::ostream& operator<<(std::ostream& os, const {{NAME}}& c) {
    Serialization_context_export p_ctx;
    c.to_stream(os, p_ctx);
    p_ctx.export_wanted(os);
    return os;
  }

  std::istream& operator>>(std::istream& is, {{NAME}}& c) {
    Serialization_context_import p_ctx;
    c.from_stream(is, p_ctx);
    p_ctx.import_wanted(is);
    return is;
  }

  std::ostream& operator<<(std::ostream& os, {{NAME}} const * c) {
    return os;
  }

  std::istream& operator>>(std::istream& is, {{NAME}}*& c) {
    // Serialization_context p_ctx;
    // c.from_stream(is, p_ctx);
    // p_ctx.import_wanted(is);
    return is;
  }

  std::istream& operator>>(std::istream& is, std::shared_ptr<{{NAME}}> &c) {
    return is;
  }

  std::ostream& operator<<(std::ostream& os, const std::shared_ptr<{{NAME}}> &c){
    return os;
  }


  /////////////////////////////////////////////////////////////////////////////
  //                            LOAD/SAVE                                    //
  /////////////////////////////////////////////////////////////////////////////
  std::ostream& {{NAME}}::to_stream(std::ostream& os, Serialization_context_export& p_ctx) const {
    os << "{";
    os << "type:" << "{{NAME}}";

    {% if PARENT -%}
    os << ",parent:";
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::to_stream(os, p_ctx);
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

    // {% if REQUIRE_LIST -%}
    // os << ",require_list:{";
    // {% for sc in REQUIRE_LIST %}
    // os << "{{sc.NAME}}:[";
    // for (auto& i_sc : this->{{sc.NAME}}) {
    //   os << i_sc;
    //   if(i_sc != this->{{sc.NAME}}.back()){ os << ","; }
    // }
    // os << "]";
    // {% if not loop.last -%}
    // os << ",";
    // {%- endif-%}
    // {% endfor %}
    // os << "}";
    // {%- endif-%}

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
    this->extra_export(os, p_ctx);
    os << "}";
    {% endif -%}

    {% if COMPONENT_INSTANCE -%}
    os << ",components:{";
    {% for sc in COMPONENT_INSTANCE %}
    os << "{{sc.NAME}}:";
    this->{{sc.NAME}}.to_stream(os, p_ctx);
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
    return os;
  }

  {% if EXTRA -%}
  void {{NAME}}::extra_export(std::ostream& os, Serialization_context_export& p_ctx) const {
    os << "";
  }

  void {{NAME}}::extra_import(std::istream& is, Serialization_context_import& p_ctx) {

  }
  {% endif -%}

  std::istream& {{NAME}}::from_stream(std::istream& is, Serialization_context_import& p_ctx) {
    // TODO
    return is;
  }
}

{% include "helper/namespace_close.hpp" with context %}
