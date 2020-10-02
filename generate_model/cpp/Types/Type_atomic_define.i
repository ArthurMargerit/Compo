%module {{NAME}}
%{
#include "Types/{{NAME}}.hpp"
%}


{% if INCLUDE %}
{% if INCLUDE.__class__.__name__ == "str" %}
%include {{INCLUDE.replace(".hpp",".i")}}
{%elif INCLUDE.__class__.__name__ == "list" %}
{%for l_include in INCLUDE %}
%include {{l_include.replace(".hpp",".i")}}
{%endfor%}
{%else%}
%include {{INCLUDE.replace(".hpp",".i")}}
{%endif%}
{%endif%}

%include "Types/{{NAME}}.hpp"
