#pragma once

#include "Links/Link.hpp"
#include "Data/Types.hpp"
#include "Interfaces/Interface.hpp"
#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"
#include <functional>

class {{NAME}} : public Link{%-if S.OUT == True -%},public Link_from{%- endif -%}
{%-if S.IN  == True -%},public Link_to{%- endif -%}
{%-if S.DIRECT == True -%},public Link_direct{%- endif -%}
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

 std::function<Interface*(Function_stream& , Return_stream&)> build_f;

public:
// Get and set /////////////////////////////////////////////////////////////
{% for data in DATA %}
virtual
{{data["TYPE"]["NAME"]}} get_{{data["NAME"]}}() const ;
virtual
  void set_{{data["NAME"]}}(const {{data["TYPE"]["NAME"]}} {{data["NAME"]}});
{%- endfor %}

 void set_build_f(std::function<Interface*(Function_stream& , Return_stream&)>);

{%if S.IN  == True %}
virtual  void set_to(Interface* to);
{% endif %}
{%if S.OUT  == True %}
virtual  void set_from(Interface** from);
{% endif %}
{%if S.DIRECT  == True %}
virtual void set_from_to(Interface** from, Interface* to);
{% endif %}

};
