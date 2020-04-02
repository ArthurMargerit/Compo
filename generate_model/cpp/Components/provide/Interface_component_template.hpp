#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"
#include "Interfaces/{{INTERFACE.D_NAME.replace('::','/')}}/{{INTERFACE.NAME}}.hpp"

{% set NAMESPACE=COMPONENT.NAMESPACE %}
{% include "helper/namespace_open.hpp" with context %}

namespace {{COMPONENT.NAME}} {

  class {{COMPONENT.NAME}};

  class  {{INTERFACE.NAME}}_{{NAME}} : public ::{{INTERFACE.D_NAME}}
  {
  public:

    {{COMPONENT.NAME}}* composant;

    //! Default constructor
    {{INTERFACE.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp);
    {%- for f in FUNCTION %}
    virtual {{ f.RETURN.NAME }} {{ f.NAME }}(
      {%- for a in f.SIGNATURE -%}
      {{a.TYPE.D_NAME}} {{a.NAME }}
      {%- if not loop.last%},{% endif %}
      {%- endfor-%}
      );
    {%- endfor %}

    //! Destructor
    virtual ~{{INTERFACE.NAME}}_{{NAME}}() noexcept;


    {{INTERFACE.NAME}}_{{NAME}}() = delete;
    //! Copy constructor
    {{INTERFACE.NAME}}_{{NAME}}(const {{INTERFACE.NAME}}_{{NAME}} &other)=delete;
    //! Move constructor
    {{INTERFACE.NAME}}_{{NAME}}({{INTERFACE.NAME}}_{{NAME}} &&other) = delete;
    // //! Copy assignment operator
    // {{INTERFACE.NAME}}& operator=(const {{INTERFACE.NAME}} &other)=delete;
    // //! Move assignment operator
    // {{INTERFACE.NAME}}& operator=({{INTERFACE.NAME}} &&other) noexcept;

    virtual bool is_fake(){return false;}

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
    void save(std::ostream& os) const;
    void load(std::istream& is);

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
}

{% include "helper/namespace_close.hpp" with context %}
