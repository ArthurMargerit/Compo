#pragma once

{%if PARENT%}
#include "Links/{{PARENT.D_NAME.replace('::','/')}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Links/Link.hpp"
{%endif%}

class Function_stream;
class Return_stream;
class Interface;

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

#include <functional>

{%include "helper/namespace_open.hpp"%}
class {{NAME}}:
{%- if PARENT -%}   public {{PARENT.D_NAME}}
{%- else -%}        public Link
{%- if PORT.OUT -%},public Link_out{%- endif -%}
{%- if PORT.ARRAY_OUT -%},public Link_array_out{%- endif -%}
{%- if PORT.MAP_OUT -%},public Link_map_out{%- endif -%}
{%- if PORT.IN -%},public Link_in{%- endif -%}
{%- if PORT.ARRAY_IN -%},public Link_array_in{%- endif -%}
{%- if PORT.MAP_IN -%},public Link_map_in{%- endif -%}
{%endif-%}
{
public:

  {{NAME}}();
  virtual ~{{NAME}}();

  virtual void step();
  virtual void connect();
  virtual void disconnect();

// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
virtual
{{data.TYPE.D_NAME}} get_{{data.NAME}}() const ;
virtual
  void set_{{data.NAME}}(const {{data.TYPE.D_NAME}} {{data.NAME}});
{%- endfor %}

 private:
// DATA ////////////////////////////////////////////////////////////////////
 {% for data in DATA %}
 {{data.TYPE.D_NAME}} {{data.NAME}};
 {% endfor%}

};
{%include "helper/namespace_close.hpp"%}
