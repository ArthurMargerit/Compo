#pragma once

#include "Interfaces/{{NAME}}/{{NAME}}.hpp"

#include <vector>

class {{NAME}};
class {{NAME}}_Dispatcher {

 private:
   std::vector<{{NAME}}*> a_list_interface;

 public:
 void add_interface({{NAME}}*);
 void remove_interface({{NAME}}*);

 /////////////////////////////////////////////////////////////////////////////
 //                               FUNCTION                                  //
 /////////////////////////////////////////////////////////////////////////////
 {%- for f in FUNCTION %}
 virtual {% if f["RETURN"]["NAME"] != "void" -%}
 std::vector<{{f["RETURN"]["NAME"]}}>
 {%- else -%}
 void
 {%- endif %} {{ f["NAME"] }}(
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
 virtual {% if v["TYPE"]["NAME"] != "void" -%}
 std::vector<{{v["TYPE"]["NAME"]}}>
 {%- else -%}
 void
 {%- endif -%} get_{{v["NAME"]}}() const;
 virtual void set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}});
 {%- endfor %}
};
