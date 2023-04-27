{% if INTERFACE.PARENT %}
{%- with START=START,INTERFACE=INTERFACE.PARENT, FUNC_GENERATED=FUNC_GENERATED-%}
{%- include "helper/fake_func_mapping.cpp" with context -%}
{%- endwith -%}
{% endif %}

// INTERFACE Function {{INTERFACE.NAME}} //////////////////////////////////////
{%- for f in INTERFACE.FUNCTION %}
{%if f.NAME not in FUNC_GENERATED%}
{%set _ = FUNC_GENERATED.append(f.NAME)%}

  {{ f.RETURN.D_NAME }} {{START}}_fake_stream::{{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    ) {
    {%if f.RETURN.D_NAME != "void"%}return {% endif-%}
    {{INTERFACE.D_NAME}}_fake_stream::{{f.NAME}}({%- for a in f.SIGNATURE -%}
    {{a.NAME}}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%});
}
{%endif%}
{%- endfor %}
