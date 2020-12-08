{%- if not FIRST_PARENT %}
{%- set FIRST_PARENT = THIS.PARENT%}
{%- endif %}

{%- if not CLS_NAME %}
{%- set CLS_NAME = THIS.NAME%}
{%- endif %}
// from {{THIS.NAME}}
{%- for f in THIS.FUNCTION %}
{{ f.RETURN.D_NAME }} {{CLS_NAME}}::{{f.NAME}}(
  {%- for a in f.SIGNATURE -%}
  {{a.TYPE.D_NAME}} {{a.NAME }}
  {%- if not loop.last%},{% endif %}
  {%- endfor -%}
  ) {

{%if PARENT and Function.model_test.have_function(PARENT, f.NAME) %}
  {%- if f.RETURN.D_NAME  != "void" %}
  {{ f.RETURN.D_NAME }} l_ret =
  {%- endif -%}
  {{FIRST_PARENT.NAME}}::{{f.NAME}}(
    {%- for a in f.SIGNATURE -%}
    {{a.NAME}}
    {%- if not loop.last%},{% endif -%}
    {%- endfor -%}
    );
{%endif%}

{%- if "DEFAULT" in f.RETURN%}
return {{f.RETURN.DEFAULT}};
{%- else -%}
return {{f.RETURN.D_NAME}}();
{%- endif %}
}
{% endfor %}

{% if THIS.PARENT %}
{%- with THIS=THIS.PARENT -%}
{%- include "Structs/Struct_function.cpp" with context -%}
{%- endwith -%}
{% endif %}
