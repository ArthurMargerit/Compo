 {%- for f in  INTERFACE.FUNCTION %}
  {{ f.RETURN.NAME }} {{CLS_NAME}}::{{ f.NAME }}(
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

{% if INTERFACE.PARENT %}
{% with INTERFACE=INTERFACE.PARENT, CLS_NAME=CLS_NAME%}
{% include "Components/provide/Function_helper.cpp" with context %}
{% endwith %}
{% endif %}
