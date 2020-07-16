#pragma once

{%if PARENT%}
#include "Links/{{PARENT.F_NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Links/Link.hpp"
{% if PORT.DBUS_IN or PORT.DBUS_OUT -%}
#include "Links/Link_dbus.hpp"
{%- endif -%}
{%endif%}

namespace CompoMe {
  class Function_stream;
  class Return_stream;
  class Interface;
}

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

#include <functional>

{%include "helper/namespace_open.hpp"%}
class {{NAME}}:
{%- if PARENT -%}   public {{PARENT.D_NAME}}
{%- else -%}        public CompoMe::Link
{%- if PORT.OUT -%},public CompoMe::Link_out{%- endif -%}
{%- if PORT.ARRAY_OUT -%},public CompoMe::Link_array_out{%- endif -%}
{%- if PORT.MAP_OUT -%},public CompoMe::Link_map_out{%- endif -%}
{%- if PORT.IN -%},public CompoMe::Link_in{%- endif -%}
{%- if PORT.DBUS_IN -%},public CompoMe::Link_dbus_in{%- endif -%}
{%- if PORT.DBUS_OUT -%},public CompoMe::Link_dbus_out{%- endif -%}
{%- if PORT.ARRAY_IN -%},public CompoMe::Link_array_in{%- endif -%}
{%- if PORT.MAP_IN -%},public CompoMe::Link_map_in{%- endif -%}
{%endif-%}
{
public:

  {{NAME}}();
  virtual ~{{NAME}}();

  void step() override;
  void connect() override;
  void disconnect() override;

// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
virtual
{{data.TYPE.D_NAME}} get_{{data.NAME}}() const ;
virtual
  void set_{{data.NAME}}(const {{data.TYPE.D_NAME}} {{data.NAME}});
{%- endfor %}

{%- if PORT.MAP_IN or PORT.MAP_OUT or PORT.ARRAY_IN or PORT.ARRAY_OUT or PORT.DBUS_OUT or PORT.DBUS_IN  -%}
protected:
 void connect(CompoMe::Require_helper &p_i) override;
 void disconnect(CompoMe::Require_helper &p_i) override;
{%- endif -%}

private:
// DATA ////////////////////////////////////////////////////////////////////
 {% for data in DATA %}
 {{data.TYPE.D_NAME}} {{data.NAME}};
 {% endfor%}

};
{%include "helper/namespace_close.hpp"%}
