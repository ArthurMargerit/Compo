 {%- for f in  INTERFACE.FUNCTION %}
  {{ f.RETURN.NAME }} {{CLS_NAME}}::{{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    ){

    {% if LINK_TO%}
    // {{LINK_TO.NAME}}
    {{ f.RETURN.NAME }} ret = this->get_c()
                          .get_sc_{{LINK_TO.INSTANCE.NAME}}()
                          .get_{{LINK_TO.INTERFACE.NAME}}()
                          .{{f.NAME}}({%- for a in f.SIGNATURE -%}{{a.NAME }}{%- if not loop.last%},{% endif %}{%- endfor-%});
    {% elif "DEFAULT" in f.RETURN %}
    {{ f.RETURN.NAME }} ret = {{f.RETURN.DEFAULT}};
    {% else %}
    {{ f.RETURN.NAME }} ret = {{f.RETURN.NAME}}();
    {% endif %}

    return ret;
  }
  {%- endfor %}

{% if INTERFACE.PARENT %}
{% with INTERFACE=INTERFACE.PARENT, CLS_NAME=CLS_NAME%}
{% include "Components/provide/Function_helper.cpp" with context %}
{% endwith %}
{% endif %}
