#pragma once

#include <ostream>

#include "types.hpp"

{% for key,value in STRUCTS.items() %}
struct {{value["NAME"]}} {

  /////////////////////////////////////////////////////////////////////////////
  //                                ATTRIBURE                                //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in value["DATA"] %}
  {{value_data["TYPE"]["NAME"]}} {{value_data["NAME"]}};
  {%- endfor %}

  /////////////////////////////////////////////////////////////////////////////
  //                               CONSTRUCTEUR                              //
  /////////////////////////////////////////////////////////////////////////////
  {{value["NAME"]}}();

  {{value["NAME"]}}({%- for value_data in value["DATA"] -%}
    {{value_data["TYPE"]["NAME"]}} p_{{value_data["NAME"]}}
    {%- if not loop.last -%}
,
    {%- endif -%}
    {%- endfor %});

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
  {%- for value_data in value["DATA"] %}
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
std::ostream& operator<<(std::ostream& os, const {{value["NAME"]}}& c);
std::istream& operator>>(std::istream& os,{{value["NAME"]}}& c);

{% endfor %}

