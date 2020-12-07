#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"
#include "Bus/{{BUS.F_NAME}}.hpp"

#include "Serialization_context.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}

class {{COMPONENT.NAME}};

class  {{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}} : public ::{{BUS.D_NAME}} {
  public:
    //! Default constructor
  {{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp);
    //! Destructor
  virtual ~{{COMPONENT.NAME}}_{{BUS.NAME}}_{{NAME}}() noexcept;

    {% with EVENTS=BUS.EVENTS, SUB_BUS=BUS.SUB_BUS,impl_invt = []%}
    {% include "Components/Events/Event_component_event_m.hpp" with context%}
    {% endwith %}


    // bool is_fake() override {return false;}
    // ///////////////////////////////////////////////////////////////////////////
    // //                            SAVE/LOAD                                  //
    // ///////////////////////////////////////////////////////////////////////////
    // // void save(std::ostream& os) const;
    // // void load(std::istream& is);
    // std::ostream& to_stream(std::ostream& , CompoMe::Serialization_context_export&) const;
    // std::istream& from_stream(std::istream& , CompoMe::Serialization_context_import&);

  private:
    {{COMPONENT.NAME}}& get_c() const;
    {{COMPONENT.NAME}}* a_c;
  };

{% include "helper/namespace_close.hpp" with context %}
