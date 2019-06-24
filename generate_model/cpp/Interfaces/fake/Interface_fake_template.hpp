#pragma once

#include "Data/{{options.project.name}}.hpp"

#include "Interfaces/{{NAME}}/{{NAME}}.hpp"
{%if PARENT %}
#include "Interfaces/{{PARENT.NAME}}/{{PARENT.NAME}}_fake.hpp"
{%else%}
#include "Interfaces/Fake.hpp"
{% endif %}

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class {{NAME}}_fake :public {{NAME}}, protected {%if PARENT %}{{PARENT.NAME}}_fake{%else%}Fake{% endif %}
{
public:
  // constructor
  {{NAME}}_fake(Function_stream& out, Return_stream& in);

  //! Destructor
  virtual ~{{NAME}}_fake() noexcept;

  static
    Interface* Build_func(Function_stream& os, Return_stream& is) {
    return ({{NAME}}*) new {{NAME}}_fake(os,is);
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
  {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    );
  {%-endif%}
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%set DATA_GENERATED = [] %}
  {%if PARENT%}
  {%- with START=NAME, INTERFACE=PARENT, DATA_GENERATED=DATA_GENERATED-%}
  {%- include "helper/fake_getset_mapping.hpp" with context -%}
  {%- endwith -%}
  {%endif%}

  {%- for v in DATA %}
  virtual
  {{v["TYPE"]["NAME"]}} get_{{v["NAME"]}}() const;
  virtual
    void set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}});
  {% endfor%}

protected:

private:
};


