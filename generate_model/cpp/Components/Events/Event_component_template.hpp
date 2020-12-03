#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"
#include "Bus_Events/{{BUS_EVENT.F_NAME}}.hpp"

#include "Serialization_context.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}

class {{COMPONENT.NAME}};

class  {{COMPONENT.NAME}}_{{BUS_EVENT.NAME}}_{{NAME}} : public ::{{BUS_EVENT.D_NAME}} {
  public:
    {{COMPONENT.NAME}}* composant;

    //! Default constructor
    {{COMPONENT.NAME}}_{{BUS_EVENT.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp){}

    {% with EVENTS=BUS_EVENT.EVENTS, SUB_BUS=BUS_EVENT.SUB_BUS,impl_invt = []%}
    {% include "Components/Events/Event_component_event_m.hpp" with context%}
    {% endwith %}

    //! Destructor
    virtual ~{{COMPONENT.NAME}}_{{BUS_EVENT.NAME}}_{{NAME}}() noexcept{}

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

  };

{% include "helper/namespace_close.hpp" with context %}
