%module {{NAME}};

/* {{NAME}}.i */
%include <std_string.i>
%rename(stream_me_in) operator >>;
%rename(stream_out) operator <<(std::ostream &,{{D_NAME}} const &);
%rename(stream_pointer_out) operator <<(std::ostream &,{{D_NAME}} const *);

%rename(__str__) to_string;

%module {{NAME}}
%{
#include "Structs/{{F_NAME}}.hpp"
%}

{% if PARENT %}
%include "Structs/{{PARENT.F_NAME}}.i"
{% else %}
%include "Structs/Struct.i"
{% endif %}
{% set include_key = []%}

// TYPES
{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
{%- if d.D_NAME not in include_key -%}
{% if d.NATIF != true %}
%include "Types/{{d.F_NAME}}.i"
{% set _ = include_key.append(d.D_NAME) -%}
{%if d.POINTER == true%}
%include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}.i"
%include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}_fac.i"
{% endif -%}
{% endif -%}
{% endif -%}
{% endfor -%}

// STRUCTS
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
{%- if d.D_NAME not in include_key -%}
%include "Structs/{{d.F_NAME}}.i"
{% set _ = include_key.append(d.D_NAME) -%}
{% endif %}
{% endfor%}


%include "Structs/{{F_NAME}}.hpp"
