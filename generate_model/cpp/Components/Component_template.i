/* /\* {{NAME}}.i *\/ */

%module {{NAME}}_swig;
%include <std_string.i>

namespace {{NAME}} {
   %rename(steam_me_in) operator >>(std::istream &,{{NAME}} &);
   %rename(stream_me_in_p) operator >>(std::istream &,{{NAME}}*&);
   %rename(stream_me_out) operator <<(std::ostream &,{{NAME}} const &);
   %rename(stream_me_out_p) operator <<(std::ostream &,{{NAME}} const *);
}

{%if PARENT%}
%include "Components/{{NAME}}/{{NAME}}_swig.i"
{%else%}
%include "Components/Component.i"
{%endif%}

%module {{NAME}}_swig
%{
/* #include "Components/Component.hpp" */
/* #include "Interfaces/Interface.hpp" */
/* #include "Interfaces/Fake.hpp" */
/* #include "Interfaces/Caller.hpp" */
  {% for a in PROVIDE %}
#include "Interfaces/{{a.INTERFACE.NAME}}/{{a.INTERFACE.NAME}}.hpp"
  {%endfor%}
  {% for a in REQUIRE %}
#include "Interfaces/{{a.INTERFACE.NAME}}/{{a.INTERFACE.NAME}}.hpp"
  {%endfor%}

  {% for a in PROVIDE %}
  #include "Components/{{NAME}}/{{NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
  {%endfor%}

  #include "Components/{{NAME}}/{{NAME}}.hpp"
%}

%include "Interfaces/Interface.hpp"

{% for a in PROVIDE %}
%include "Interfaces/{{a.INTERFACE.NAME}}/{{a.INTERFACE.NAME}}.hpp"
{%endfor%}

{% for a in PROVIDE %}
%include "Components/{{NAME}}/{{NAME}}_{{a.INTERFACE.NAME}}_{{a.NAME}}.hpp"
{%endfor%}

%include "Components/{{NAME}}/{{NAME}}.hpp"
