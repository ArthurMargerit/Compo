{%if NAMESPACE != ""%}
{%for i_ns in NAMESPACE.split("::")%}
} //{{i_ns}}
{%endfor%}
{%endif%}
