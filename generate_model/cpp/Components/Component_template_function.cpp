#include "Components/{{F_NAME}}.hpp"

{% include "helper/namespace_open.hpp" with context %}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

{% for f in FUNCTION %}
{{f.RETURN.D_NAME}} {{NAME}}::{{f.NAME}}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME}}
    {%- if not loop.last%},{% endif -%}
    {%- endfor-%}
    ) {
    {%- if "DEFAULT" in f.RETURN%}
    return {{f.RETURN.DEFAULT}};
    {%- else %}
    return {{f.RETURN.D_NAME}}();
    {%- endif %}
}

{% endfor %}

{% include "helper/namespace_close.hpp" with context %}
