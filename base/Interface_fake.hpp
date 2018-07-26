#pragma once

#include "types.hpp"
#include "structs.hpp"

class {{NAME}}_fake :: public {{NAME}}
{
public:
  //! Default constructor
  {{NAME}}_fake(){}

  //! Copy constructor
  {{NAME}}(const {{NAME}} &other)= delete; 

  //! Move constructor
  {{NAME}}({{NAME}} &&other) =delete;

  //! Destructor
  virtual ~{{NAME}}() noexcept{}

  //! Copy assignment operator
  {{NAME}}& operator=(const {{NAME}} &other){}

  //! Move assignment operator
  {{NAME}}& operator=({{NAME}} &&other) noexcept{}

  {%- for f in FUNCTION %}
  virtual
  {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
    )
    {
      std::cout << "{{NAME}}({% for a in f["SIGNATURE"] %}{{a["NAME"] }}{%- if not loop.last%},{% endif %}{%endfor%})" << std::endl;
    }
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for v in DATA %}
  {{v["TYPE"]["NAME"]}} get_{{v["NAME"]}}() const {
    return {{v["NAME"]}};
  }

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

