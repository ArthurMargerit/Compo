#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

#include "Interfaces/{{F_NAME}}/{{NAME}}.hpp"

{% if PARENT -%}
#include "Interfaces/{{PARENT.F_NAME}}/{{PARENT.NAME}}_fake_dbus.hpp"
{%- else -%}
#include "Interfaces/Fake_dbus.hpp"
{%- endif %}

// class Function_stream_send;
// class Return_stream_recv;

{% include "helper/namespace_open.hpp" with context%}
class {{NAME}}_fake_dbus :
     public {{D_NAME}},
     public {%if PARENT %}{{PARENT.D_NAME}}_fake_dbus{%else%}CompoMe::Fake_dbus{% endif %} {
public:
  // constructor
  {{NAME}}_fake_dbus(CompoMe::Function_dbus_send& out, CompoMe::Return_dbus_recv& in);

  //! Destructor
  virtual ~{{NAME}}_fake_dbus() noexcept;

  bool is_fake() override {return true;}

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////
  {%set FUNC_GENERATED = [] %}
  {%if PARENT%}
  {%- with START=NAME, INTERFACE=PARENT, FUNC_GENERATED=FUNC_GENERATED-%}
  {%- include "helper/fake_func_mapping.hpp" with context -%}
  {%- endwith -%}
  {%endif%}

  {%- for f in FUNCTION %}
  {%if f.NAME not in FUNC_GENERATED%}
  {%set _ = FUNC_GENERATED.append(f.NAME)%}
  virtual
  {{ f.RETURN.D_NAME }} {{ f.NAME }}(
    {%- for a in f.SIGNATURE -%}
    {{a.TYPE.D_NAME}} {{a.NAME }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    ) override;
  {%-endif%}
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {% set DATA_GENERATED = [] %}
  {%- if PARENT %}
  {%- with START=NAME, INTERFACE=PARENT, DATA_GENERATED=DATA_GENERATED-%}
  {%- include "helper/fake_getset_mapping.hpp" with context -%}
  {%- endwith -%}
  {%- endif %}

  {%- for v in DATA %}
  virtual
    {{v.TYPE.D_NAME}} get_{{v.NAME}}() const override;
  virtual
    void set_{{v.NAME}}(const {{v.TYPE.D_NAME}}& {{v.NAME}}) override;
  {% endfor%}
};
{% include "helper/namespace_close.hpp" with context%}
