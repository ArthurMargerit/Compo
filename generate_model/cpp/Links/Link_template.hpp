#pragma once
{%if PARENT%}
#include "Links/{{PARENT.NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Links/Link.hpp"
{%endif%}

class Function_stream;
class Return_stream;
class Interface;

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

#include <functional>

class {{NAME}}:
{%- if PARENT -%}   public {{PARENT.NAME}}
{%- else -%}        public Link
{%- if PORT.OUT -%},public Link_out{%- endif -%}
{%- if PORT.IN  -%},public Link_in{%- endif -%}
{%endif-%}
{

public:

  {{NAME}}();
  virtual ~{{NAME}}();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

// DATA ////////////////////////////////////////////////////////////////////
{% for data in DATA %}
 {{data.TYPE.NAME}} {{data.NAME}};
{% endfor%}

 Build_fake_F build_f;

public:
// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
virtual
{{data["TYPE"]["NAME"]}} get_{{data["NAME"]}}() const ;
virtual
  void set_{{data["NAME"]}}(const {{data["TYPE"]["NAME"]}} {{data["NAME"]}});
{%- endfor %}

};
