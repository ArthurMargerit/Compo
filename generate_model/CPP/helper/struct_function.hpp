
{%- for f in FUNCTION %}
virtual {{ f["RETURN"]["NAME"] }} {{f["NAME"]}}(
  {%- for a in f["SIGNATURE"] -%}
  {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
  {%- if not loop.last%},{% endif %}
  {%- endfor -%}
  );
{%- endfor %}

{% if PARENT %}
{%- with NAME=NAME, FUNCTION=PARENT.FUNCTION, PARENT=PARENT.PARENT -%}
{%- include "helper/struct_function.hpp" with context -%}
{%- endwith -%}
{% endif %}
