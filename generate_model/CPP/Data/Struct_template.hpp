#pragma once

#include <ostream>

#include "Data/Types.hpp"

struct {{NAME}} {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  {{value_data["TYPE"]["NAME"]}} {{value_data["NAME"]}};
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  {{NAME}}();

  {{NAME}}({%- for value_data in DATA -%}
    {{value_data["TYPE"]["NAME"]}} p_{{value_data["NAME"]}}
    {%- if not loop.last -%}
,
    {%- endif -%}
    {%- endfor %});

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in DATA %}
  // {{value_data["NAME"]}}
  {{value_data["TYPE"]["NAME"]}} get_{{value_data["NAME"]}}() const {
    return this->{{value_data["NAME"]}};
  }

  void set_{{value_data["NAME"]}}(const {{value_data["TYPE"]["NAME"]}} value) {
    this->{{value_data["NAME"]}} = value;
  }
  {%- endfor %}
};

///////////////////////////////////////////////////////////////////////////////
//                               << STREAM >>                                //
///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const {{NAME}}& c);
std::istream& operator>>(std::istream& os,{{NAME}}& c);

