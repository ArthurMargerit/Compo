{% if INTERFACE.PARENT %}
{%- with INTERFACE=INTERFACE.PARENT, FUNC_GENERATED=FUNC_GENERATED-%}
{%- include "helper/fake_func_mapping.hpp" with context -%}
{%- endwith -%}
{% endif %}

// INTERFACE Function {{INTERFACE.NAME}} //////////////////////////////////////
{%- for f in INTERFACE.FUNCTION %}
{%if f.NAME not in FUNC_GENERATED%}
{%set _ = FUNC_GENERATED.append(f.NAME)%}

virtual
  {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    );
{%endif%}
{%- endfor %}