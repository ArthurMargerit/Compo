#pragma once

#include "Data/{{options.project.name}}.hpp"

{%if PARENT -%}
#include "Interfaces/{{PARENT.NAME}}/{{PARENT.NAME}}.hpp"
{%else%}
#include "Interfaces/Interface.hpp"
{%-endif%}

#include <functional>

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

{% for d in Function.model_get.get_struct_use_by(MAIN, FUNCTION, DATA).keys() %}
#include "Data/Struct_{{d}}.hpp"
{% endfor %}

class Caller;
class {{NAME}}_caller;

class Fake;
class {{NAME}}_fake;


class {{NAME}} : public {%if PARENT %}{{PARENT.NAME}}{%else%}Interface{%endif%}
{
public:

  using MyCaller = {{NAME}}_caller;
  using MyFake = {{NAME}}_fake;

  Caller* c;

  virtual Caller* get_caller();
  //  static Fake* get_fake(std::ostream& , std::istream& );

  //! Default constructor
  {{NAME}}();

  //! Destructor
  virtual ~{{NAME}}() noexcept;

  // //! Copy assignment operator
  // {{NAME}}& operator=(const {{NAME}} &other){}


  // //! Move assignment operator
  // {{NAME}}& operator=({{NAME}} &&other) noexcept{}

  {%- for f in FUNCTION %}
  virtual {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )=0;
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for v in DATA %}
  virtual
  {{v["TYPE"]["NAME"]}} get_{{v["NAME"]}}() const {
    return {{v["NAME"]}};
  }

  virtual
  void set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}}) {
    this->{{v["NAME"]}} = {{v["NAME"]}};
  }
  {%- endfor %}

protected:

private:
  {%- for v in DATA %}
  {{v["TYPE"]["NAME"]}} {{v["NAME"]}};
  {%- endfor %}
};

std::function< Fake*(Function_stream&, Return_stream&) > build_fake({{NAME}}* t);

