 {%- for f in  INTERFACE.FUNCTION %}
  {{ f.RETURN.D_NAME }} {{CLS_NAME}}::{{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    ){

    {% if f.RETURN.D_NAME != "void" %}{{ f.RETURN.D_NAME }} ret ={%endif%}

    {% if LINK_TO%}
    // {{LINK_TO.NAME}}
    this->get_c()
      .get_sc_{{LINK_TO.INSTANCE.NAME}}()
      .get_{{LINK_TO.INTERFACE.NAME}}()
      .{{f.NAME}}({%- for a in f.SIGNATURE -%}{{a.NAME }}{%- if not loop.last%},{% endif %}{%- endfor-%});

    {% elif "DEFAULT" in f.RETURN %}
    {{f.RETURN.DEFAULT}};
    {% else %}
    {{f.RETURN.D_NAME}}();
    {% endif %}

    {% if f.RETURN.D_NAME != "void" %}
    return ret;
    {%else%}
    return;
    {%endif%}
  }
  {%- endfor %}

{% if INTERFACE.PARENT %}
{% with INTERFACE=INTERFACE.PARENT, CLS_NAME=CLS_NAME%}
{% include "Components/provide/Function_helper.cpp" with context %}
{% endwith %}
{% endif %}
