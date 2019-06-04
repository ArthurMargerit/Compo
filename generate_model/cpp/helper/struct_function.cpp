
{%- for f in FUNCTION %}
{{ f.RETURN.NAME }} {{NAME}}::{{f.NAME}}(
  {%- for a in f["SIGNATURE"] -%}
  {{a.TYPE.NAME}} {{a.NAME }}
  {%- if not loop.last%},{% endif %}
  {%- endfor -%}
  ) {

  {%if PARENT and Function.model_test.have_function(PARENT, f.NAME) %}
  {%- if f.RETURN.NAME  != "void" %}
  {{ f.RETURN.NAME }} l_ret =
  {%- endif -%}
  {{FIRST_PARENT.NAME}}::{{f["NAME"]}}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["NAME"] }}
    {%- if not loop.last%},{% endif -%}
    {%- endfor -%}
    );
    {%endif%}
{%- if "DEFAULT" in f.RETURN%}
return {{f.RETURN.DEFAULT}};
{%- else -%}
return {{f.RETURN.NAME}}();
{%- endif %}
}

{% endfor %}

{% if PARENT %}
{%- with NAME=NAME, FUNCTION=PARENT.FUNCTION, PARENT=PARENT.PARENT, FIRST_PARENT=FIRST_PARENT -%}
{%- include "helper/struct_function.cpp" with context -%}
{%- endwith -%}
{% endif %}
