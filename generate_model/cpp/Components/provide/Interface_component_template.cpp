
#include "Components/{{COMPONENT.NAME}}/{{COMPONENT.NAME}}_{{INTERFACE.NAME}}_{{NAME}}.hpp"
#include "Components/{{COMPONENT.NAME}}/{{COMPONENT.NAME}}.hpp"

namespace {{COMPONENT.NAME}}
{

  {{INTERFACE.NAME}}_{{NAME}}::{{INTERFACE.NAME}}_{{NAME}}({{COMPONENT.NAME}}* comp):composant(comp){
    return;
  }

  //! Destructor
  {{INTERFACE.NAME}}_{{NAME}}::~{{INTERFACE.NAME}}_{{NAME}}() noexcept {
        return;
  }

  {%- for f in  INTERFACE.FUNCTION %}
  {{ f.RETURN.NAME }} {{INTERFACE.NAME}}_{{NAME}}::{{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    ){
    {% if "DEFAULT" in f.RETURN%}
    return {{f.RETURN.DEFAULT}};
    {% else %}
    return {{f.RETURN.NAME}}();
    {% endif %}
  }
  {%- endfor %}


}; // namespace {{COMPONENT.NAME}}

