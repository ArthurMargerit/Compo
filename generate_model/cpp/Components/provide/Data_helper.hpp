// DATA for {{NAME}}
{%- for v in DATA %}
{{v.TYPE.D_NAME}} {{v.NAME}};
{%- endfor %}

{% if PARENT %}
{% with NAME=PARENT.NAME, DATA=PARENT.DATA, PARENT=PARENT.PARENT%}
{% include "Components/provide/Data_helper.hpp" with context %}
{% endwith %}
{% endif %}
