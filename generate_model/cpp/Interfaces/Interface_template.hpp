#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

{%if PARENT -%}
#include "Interfaces/{{PARENT.F_NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Interfaces/Interface.hpp"
{%-endif%}

{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).values() %}
#include "Data/{{d.F_NAME}}.hpp"
{% endfor %}

#include <functional>

class Caller;
class {{NAME}}_caller;

class Fake;
class {{NAME}}_fake;

{%if OPTION and OPTION.DBUS_ADAPTER %}
class Dbus_adapter;
class {{D_NAME}}_Dbus_adapter;
{% endif %}

{% include "helper/namespace_open.hpp" with context %}

class {{NAME}} :public {%if PARENT %}{{PARENT.D_NAME}}{%else%}Interface{%endif%}
{
public:

  using MyFake = {{D_NAME}}_fake;

  using MyCaller = {{D_NAME}}_caller;

  {%if OPTION and OPTION.DBUS_ADAPTER %}
  using MyDbus_adapter = {{D_NAME}}_Dbus_adapter;
  {% endif %}
  virtual Caller* get_caller() override;

  {%if OPTION and OPTION.DBUS_ADAPTER %}
  Dbus_adapter* get_dbus_adapter() override;
  {% endif %}

  //! Default constructor
  {{NAME}}();

  //! Destructor
  virtual ~{{NAME}}() noexcept;

  // //! Copy assignment operator
  // {{NAME}}& operator=(const {{NAME}} &other){}

  // //! Move assignment operator
  // {{NAME}}& operator=({{NAME}} &&other) noexcept{}

  {%- for f in FUNCTION %}
  virtual {{ f.RETURN.D_NAME }} {{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )=0;
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for v in DATA %}
  virtual {{v.TYPE.D_NAME}} get_{{v.NAME}}() const = 0;
  virtual void set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}}) = 0;
  {%- endfor %}

private:
  Caller* c;
  {%if OPTION and OPTION.DBUS_ADAPTER %}
  Dbus_adapter* c_dbus;
  {% endif %}
};

// Build_fake_F get_build_fake({{D_NAME}}* t);
{% include "helper/namespace_close.hpp" with context %}
