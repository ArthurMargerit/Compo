#include "{{COMPOSANT}}/{{NAME}}.hpp"


namespace {{COMPOSANT}}
{

  //! Default constructor
  {{NAME}}::{{NAME}}()
                      {

                        return;
                      }

  {{NAME}}::{{NAME}}({{COMPOSANT}}* comp):composant(comp)
{

  return;
}

//! Copy constructor
{{NAME}}::{{NAME}}(const {{NAME}} &other)
{

  return;
}

//! Move constructor
{{NAME}}::{{NAME}}({{NAME}} &&other) noexcept
{

  return;
}


//! Destructor
{{NAME}}::~{{NAME}}() noexcept
{

  return;
}


//! Copy assignment operator
{{NAME}}& {{NAME}}::operator=(const {{NAME}} &other)
{

}

//! Move assignment operator
{{NAME}}& {{NAME}}::operator=({{NAME}} &&other) noexcept
{

}


{%- for f in FUNCTION %}
{{ f["RETURN"]["NAME"] }} {{NAME}}::{{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )
{

}

{% endfor %}

}; // namespace {{COMPOSANT}}
