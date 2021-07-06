/* /\* {{NAME}}.i *\/ */

%module {{NAME}};
%include <std_string.i>

{%if PARENT%}
%include "Interfaces/{{PARENT.F_NAME}}.i"
{%else%}
%include "Interfaces/Interface.i"
{%endif%}


%module {{NAME}}
%{
#include "Interfaces/{{F_NAME}}/{{NAME}}.hpp"
{%if OPTIONS.CALLER_STREAM -%}
#include "Interfaces/{{F_NAME}}/{{NAME}}_caller_stream.hpp"
{% endif -%}
{%if OPTIONS.FAKE_STREAM -%}
#include "Interfaces/{{F_NAME}}/{{NAME}}_fake_stream.hpp"
{% endif -%}
%}

{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
%include "Structs/{{d.F_NAME}}.i"
{% endfor %}

{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
{%if not d.NATIF %}
%include "Types/{{d.F_NAME}}.i"
{%endif%}
{% endfor %}

%include "Interfaces/{{F_NAME}}/{{NAME}}.hpp"
{%if OPTIONS.FAKE_STREAM %}
%include "Interfaces/{{F_NAME}}/{{NAME}}_fake_stream.hpp"
{% endif %}
{%if OPTIONS.CALLER_STREAM %}
%include "Interfaces/{{F_NAME}}/{{NAME}}_caller_stream.hpp"
{% endif %}
%include "Components/Require_helper.i"
// %template(require_{{NAME}}) CompoMe::Require_helper_t<{{D_NAME}}>;
