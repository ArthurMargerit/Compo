#include "Links/{{F_NAME}}/{{NAME}}.hpp"

{%include "helper/namespace_open.hpp"%}
{% for f in FUNCTION %}
{{f.RETURN.D_NAME}} {{NAME}}::{{f.NAME}}(
  {%- for p in f.SIGNATURE -%}
  {{p.TYPE.D_NAME}} {{p.NAME}} {% if not loop.last%},{% endif %}
  {%- endfor -%}) {
  {%- if f.RETURN.D_NAME == "void" %}
  return;
  {%- else %}
  {{f.RETURN.D_NAME}} {{NAME}};
  return {{NAME}};
  {%- endif %}
                                        }
{% endfor%}
{%include "helper/namespace_close.hpp"%}
