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
  {{ f["RETURN"]["NAME"] }} {{ f["NAME"] }}{{f["SIGNATURE"]}};
{% endfor %}

protected:
private:
};
