{%- for f in THIS.FUNCTION %}
virtual {{ f.RETURN.D_NAME }} {{f.NAME}}(
  {%- for a in f.SIGNATURE -%}
  {{a.TYPE.D_NAME}} {{a.NAME }}
  {%- if not loop.last%},{% endif %}
  {%- endfor -%}
  );
{%- endfor %}

{% if THIS.PARENT %}
{%- with THIS=THIS.PARENT -%}
{%- include "Data/struct_function.hpp" with context -%}
{%- endwith -%}
{% endif %}
