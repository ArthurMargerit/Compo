/* /\* {{NAME}}.i *\/ */

%module {{NAME}};
%include <std_string.i>

{%if PARENT%}
#include "Links/{{PARENT.D_NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
%include "Links/Link.i"
{%endif%}

{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
%include "Structs/{{d.F_NAME}}.i"
{% endfor %}

{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
{%if not d.NATIF %}
%include "Types/{{d.F_NAME}}.i"
{%endif%}
{% endfor %}

%module {{NAME}}
%{
#include "Links/{{D_NAME}}/{{NAME}}.hpp"
%}

%include "Links/{{D_NAME}}/{{NAME}}.hpp"
%include "CompoMe.i"
