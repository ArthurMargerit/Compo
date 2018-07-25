#include "{{COMPOSANT}}/{{NAME}}.hpp"
#include "{{COMPOSANT}}/{{COMPOSANT}}.hpp"

namespace {{COMPOSANT}}
{


  {{NAME}}::{{NAME}}({{COMPOSANT}}* comp):composant(comp)
                      {

                        return;
                      }

//! Destructor
{{NAME}}::~{{NAME}}() noexcept
{

  return;
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
