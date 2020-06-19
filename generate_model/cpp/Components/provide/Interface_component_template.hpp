#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"
#include "Interfaces/{{INTERFACE.F_NAME}}/{{INTERFACE.NAME}}.hpp"

#include "Serialization_context.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}

  class {{COMPONENT.NAME}};

class  {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}} : public ::{{INTERFACE.D_NAME}}
  {
  public:
    {{COMPONENT.NAME}}* composant;

    //! Default constructor
    {{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp);
    {%- for f in FUNCTION %}
    virtual {{ f.RETURN.NAME }} {{ f.NAME }}(
      {%- for a in f.SIGNATURE -%}
      {{a.TYPE.D_NAME}} {{a.NAME }}
      {%- if not loop.last%},{% endif %}
      {%- endfor-%}
      );
    {%- endfor %}

    //! Destructor
    virtual ~{{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}() noexcept;

    bool is_fake() override {return false;}

    ///////////////////////////////////////////////////////////////////////////
    //                                FUNCTION                               //
    ///////////////////////////////////////////////////////////////////////////
    {% with INTERFACE=INTERFACE, LINK_TO=LINK_TO %}
    {% include "Components/provide/Function_helper.hpp" with context %}
    {% endwith %}

    ///////////////////////////////////////////////////////////////////////////
    //                              GET/SET                                  //
    ///////////////////////////////////////////////////////////////////////////
    {% with NAME=INTERFACE.NAME, DATA=INTERFACE.DATA, PARENT=INTERFACE.PARENT%}
    {% include "Components/provide/Get_Set_helper.hpp" with context %}
    {% endwith %}

    ///////////////////////////////////////////////////////////////////////////
    //                            SAVE/LOAD                                  //
    ///////////////////////////////////////////////////////////////////////////
    // void save(std::ostream& os) const;
    // void load(std::istream& is);
    std::ostream& to_stream(std::ostream& , Serialization_context_export&) const;
    std::istream& from_stream(std::istream& , Serialization_context_import&);

  private:
    {{COMPONENT.NAME}}& get_c() const;

    {% if not LINK_TO %}
    ///////////////////////////////////////////////////////////////////////////
    //                                  DATA                                 //
    ///////////////////////////////////////////////////////////////////////////
    {% with NAME=INTERFACE.NAME, DATA=INTERFACE.DATA, PARENT=INTERFACE.PARENT%}
    {% include "Components/provide/Data_helper.hpp" with context %}
    {% endwith %}
    {% endif %}
  };

{% include "helper/namespace_close.hpp" with context %}
