#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

{%if PARENT%}
#include "Links/{{PARENT.F_NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Links/Link.hpp"
{% if PORT.DBUS_IN or PORT.DBUS_OUT -%}
#include "Links/Link_dbus.hpp"
{%- endif -%}
{%endif%}

// TYPES
{% for d in Function.model_get.get_type_use_by(MAIN, FUNCTION, DATA).values() %}
{% if d.NATIF != true %}
#include "Types/{{d.F_NAME}}.hpp"
{%if d.POINTER == true%}
#include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}.hpp"
#include "Structs/{{d.NAMESPACE.replace('::','/')}}/{{d.POINTER_OF}}_fac.hpp"
{% endif -%}
{% endif -%}
{% endfor -%}

// STRUCT
{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
#include "Structs/{{d.F_NAME}}.hpp"
{% endfor %}

// PORT
{% for d in Function.model_get.get_port_use_by(MAIN, PORT).values() %}
#include "Ports/{{d.F_NAME}}.hpp"
{% endfor %}

{%include "helper/namespace_open.hpp"%}
class {{NAME}}:
{%- if PARENT -%} public {{PARENT.D_NAME}}{%- else -%} public CompoMe::Link {%endif-%}
{
public:

  {{NAME}}();
  virtual ~{{NAME}}();

  void step() override;
  void main_connect() override;
  void main_disconnect() override;

  // one connect
  void one_connect(CompoMe::Require_helper &, CompoMe::String c)override;
  void one_connect(CompoMe::Interface &, CompoMe::String) override;

  // one disconnect
  void one_disconnect(CompoMe::Require_helper &, CompoMe::String) override;
  void one_disconnect(CompoMe::Interface &, CompoMe::String) override;

// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
{{data.TYPE.D_NAME}} get_{{data.NAME}}() const ;
void set_{{data.NAME}}(const {{data.TYPE.D_NAME}} {{data.NAME}});
{{data.TYPE.D_NAME}} & a_{{data.NAME}}();
{%- endfor %}

// Get Port /////////////////////////////////////////////////////////////
{% for p in PORT %}
 {{p.TYPE.D_NAME}}& get_{{p.NAME}}();
{%- endfor %}

 public:
// Function ///////////////////////////////////////////////////////////////////
{% for f in FUNCTION %}
 virtual {{f.RETURN.D_NAME}} {{f.NAME}}(
   {%- for p in f.SIGNATURE -%}
   {{p.TYPE.D_NAME}} {{p.NAME}} {% if not loop.last%},{% endif %}
   {%- endfor -%});
{% endfor%}

private:
// DATA ////////////////////////////////////////////////////////////////////
 {% for data in DATA -%}
 {{data.TYPE.D_NAME}} {{data.NAME}};
 {% endfor%}

// PORT ////////////////////////////////////////////////////////////////////
 {% for p in PORT -%}
 {{p.TYPE.D_NAME}} {{p.NAME}};
 {% endfor%}
};
{%include "helper/namespace_close.hpp"%}
