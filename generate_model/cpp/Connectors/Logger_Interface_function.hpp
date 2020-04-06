{%if "PARENT" in i and i.PARENT != None %}
{% with i = i.PARENT %}
{% include "Connectors/Logger_Interface_function.hpp" %}
{% endwith %}
{%endif%}

{%for f in i.FUNCTION %}
    {{f.RETURN.NAME}} {{f.NAME}}(
      {%- for p in f.SIGNATURE -%}
      {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%}
      ) override;
{%endfor%}
