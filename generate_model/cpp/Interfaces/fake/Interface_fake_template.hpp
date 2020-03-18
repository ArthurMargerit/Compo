#pragma once

#include "Data/{{FILE.replace('.yaml','')}}.hpp"

#include "Interfaces/{{D_NAME.replace('::','/')}}/{{NAME}}.hpp"
{%if PARENT %}
#include "Interfaces/{{PARENT.D_NAME.replace('::','/')}}/{{PARENT.NAME}}_fake.hpp"
{%else%}
#include "Interfaces/Fake.hpp"
{% endif %}

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

{% include "helper/namespace_open.hpp" with context%}
class {{NAME}}_fake :public {{D_NAME}}, public {%if PARENT %}{{PARENT.D_NAME}}_fake{%else%}Fake{% endif %} {
public:
  // constructor
  {{NAME}}_fake(Function_stream& out, Return_stream& in);
  {{NAME}}_fake(){}

  //! Destructor
  virtual ~{{NAME}}_fake() noexcept;

  static
    Interface* Build_func(Function_stream& os, Return_stream& is) {
    return dynamic_cast<{{D_NAME}}*>(new {{D_NAME}}_fake(os,is));
  }

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
