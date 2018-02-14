#pragma once

{% for Type in Types %}
typedef {{Type.definition}} {{Type.name}} ;
{% endfor %}
