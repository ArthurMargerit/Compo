{% if "PARENT" in i and i.PARENT != None %}
{% with i=i.PARENT %}
{% include "Connectors/Logger_Interface_get_set.hpp" %}
{% endwith %}
{% endif %}
// i.NAME
{%for d in i.DATA %}
    {{d.TYPE.D_NAME}} get_{{d.NAME}}() const override;
    void set_{{d.NAME}}(const {{d.TYPE.D_NAME}}& {{d.NAME}}) override;
{%endfor%}
