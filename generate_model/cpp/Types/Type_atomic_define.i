%module {{NAME}};

%rename(stream_out) operator <<(std::ostream &,{{D_NAME}} const &);
%rename(stream_in) operator >>(std::istream &,{{D_NAME}} &);

%ignore operator <<(DBusMessageIter &,{{D_NAME}} const &);
%ignore operator >>(DBusMessageIter &,{{D_NAME}} &);

%module {{NAME}}
%{
#include "Types/{{F_NAME}}.hpp"
%}

{% if SWIG_INCLUDE %}
%include "{{SWIG_INCLUDE}}"
{% endif %}

{% if INCLUDE %}
{% if INCLUDE.__class__.__name__ == "str" and not "<" in INCLUDE %}
%include {{INCLUDE.replace(".hpp",".i")}}
{%elif INCLUDE.__class__.__name__ == "list" %}
{%for l_include in INCLUDE %}
{% if not "<" in l_include %}
%include {{l_include.replace(".hpp",".i")}}
{%endif%}
{%endfor%}
{%else%}
{% if not "<" in INCLUDE %}
%include {{INCLUDE.replace(".hpp",".i")}}
{% endif %}
{%endif%}
{%endif%}


%include "Types/{{F_NAME}}.hpp"
