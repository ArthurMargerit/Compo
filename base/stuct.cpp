
// struct declaration //////////////////////////////////////////////////////////

{% for Struct in Stucts %}
struct {{Struct.name}};
{% endfor %}

// struct definition //////////////////////////////////////////////////////////
{% for Struct in Stucts %}

struct {{Struct.name}}
{
{% for element in Struct.elements %}
{{elements.type}} {{elements.name}};
{% endfor %}
};

{% endfor %}
