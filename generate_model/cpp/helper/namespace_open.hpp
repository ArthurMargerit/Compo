{%if NAMESPACE != ""%}
{%for i_ns in NAMESPACE.split("::")%}
namespace {{i_ns}}{
{%endfor%}
{% endif %}
