#pragma once

#include "types.hpp"
#include "structs.hpp"

class  {{NAME}}
{
public:
  //! Default constructor
  {{NAME}}();

  //! Copy constructor
  {{NAME}}(const {{NAME}} &other);

  //! Move constructor
  {{NAME}}({{NAME}} &&other) noexcept;

  //! Destructor
  virtual ~{{NAME}}() noexcept;

  //! Copy assignment operator
  {{NAME}}& operator=(const {{NAME}} &other);

  //! Move assignment operator
  {{NAME}}& operator=({{NAME}} &&other) noexcept;

{% for f in FUNCTION %}
  {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}(
    {%- for a in f["SIGNATURE"] -%}
    {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
    {%- if not loop.last%},{% endif %}
    {%- endfor-%}
   );
  {%- endfor %}

protected:
private:
};
