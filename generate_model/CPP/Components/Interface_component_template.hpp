#pragma once

#include "Data/Types.hpp"

#include "Interfaces/{{INTERFACE.NAME}}/{{INTERFACE.NAME}}.hpp"


namespace {{COMPONENT.NAME}} {

  class {{COMPONENT.NAME}};

  class  {{INTERFACE.NAME}} : public ::{{INTERFACE.NAME}}
  {
  public:

    {{COMPONENT.NAME}}* composant;

    //! Default constructor
    {{INTERFACE.NAME}}({{COMPONENT.NAME}}* comp);
    {%- for f in FUNCTION %}
    virtual {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
      {%- for a in f["SIGNATURE"] -%}
      {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
      {%- if not loop.last%},{% endif %}
      {%- endfor-%}
      );
    {%- endfor %}

    //! Destructor
    virtual ~{{INTERFACE.NAME}}() noexcept;

    {{INTERFACE.NAME}}() = delete;
    //! Copy constructor
    {{INTERFACE.NAME}}(const {{INTERFACE.NAME}} &other)=delete;
    //! Move constructor
    {{INTERFACE.NAME}}({{INTERFACE.NAME}} &&other) = delete;
    // //! Copy assignment operator
    // {{INTERFACE.NAME}}& operator=(const {{INTERFACE.NAME}} &other)=delete;
    // //! Move assignment operator
    // {{INTERFACE.NAME}}& operator=({{INTERFACE.NAME}} &&other) noexcept;

    {%- for f in INTERFACE.FUNCTION %}
    virtual {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
      {%- for a in f["SIGNATURE"] -%}
      {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
      {%- if not loop.last%},{% endif %}
      {%- endfor-%}
      );
    {%- endfor %}

  protected:
  private:
  };

};
