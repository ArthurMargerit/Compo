#pragma once

#include "types.hpp"
#include "structs.hpp"

#include "global/{{NAME}}.hpp"


namespace {{COMPOSANT}} {

  class {{COMPOSANT}};

  class  {{NAME}} : public ::{{NAME}}
  {
  public:

    {{COMPOSANT}}* composant;

    //! Default constructor
    {{NAME}}({{COMPOSANT}}* comp);
    {%- for f in FUNCTION %}
    virtual {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
      {%- for a in f["SIGNATURE"] -%}
      {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
      {%- if not loop.last%},{% endif %}
      {%- endfor-%}
      );
    {%- endfor %}

    //! Destructor
    virtual ~{{NAME}}() noexcept;

    {{NAME}}() = delete;
    //! Copy constructor
    {{NAME}}(const {{NAME}} &other)=delete;
    //! Move constructor
    {{NAME}}({{NAME}} &&other) = delete;
    //! Copy assignment operator
    {{NAME}}& operator=(const {{NAME}} &other)=delete;
    //! Move assignment operator
    {{NAME}}& operator=({{NAME}} &&other) noexcept;

  protected:
  private:
  };

};
