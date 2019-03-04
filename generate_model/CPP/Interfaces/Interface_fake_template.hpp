#pragma once

#include "Data/Types.hpp"
#include "Interfaces/{{NAME}}/{{NAME}}.hpp"
#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class {{NAME}}_fake : public {{NAME}}, public Fake
{
public:
  //! Default constructor
  {{NAME}}_fake(Function_stream& out, Return_stream& in);

  static
    Fake* Build_func(Function_stream& os, Return_stream& is)
  {
    return new {{NAME}}_fake(os,is);
  }

  //! Destructor
  virtual ~{{NAME}}_fake() noexcept;

  {%- for f in FUNCTION %}
  virtual
  {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    );
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for v in DATA %}
  virtual
  {{v["TYPE"]["NAME"]}} get_{{v["NAME"]}}() const;
  virtual
    void set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}});
  {%- endfor %}


protected:

private:
  Function_stream& o;
  Return_stream& i;

  {%- for v in DATA %}
  {{v["TYPE"]["NAME"]}} {{v["NAME"]}};
  {%- endfor %}
};


