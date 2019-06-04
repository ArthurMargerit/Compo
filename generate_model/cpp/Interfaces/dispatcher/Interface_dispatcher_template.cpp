#include "Interfaces/{{NAME}}/{{NAME}}_dispatcher.hpp"

void {{NAME}}_Dispatcher::add_interface({{NAME}}* p_i) {
  this->a_list_interface.push_back(p_i);
}

void {{NAME}}_Dispatcher::remove_interface({{NAME}}*) {

}

 {%- for f in FUNCTION %}
 {% if f["RETURN"]["NAME"] != "void" -%}
 std::vector<{{f["RETURN"]["NAME"]}}> {{NAME}}_Dispatcher::{{ f["NAME"] }}(
   {%- for a in f["SIGNATURE"] -%}
   {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
   {%- if not loop.last%},{% endif %}
   {%- endfor-%}
   ) {

   std::vector<{{f["RETURN"]["NAME"]}}> l_vec;

   for(auto& l_elem : this->a_list_interface) {
     l_vec.push_back(l_elem->{{f["NAME"]}}(
       {%- for a in f["SIGNATURE"] -%}
       {{a["NAME"] }}{%- if not loop.last%},{% endif %}
       {%- endfor-%}));
   }

   return l_vec;
  }

 {%- else -%}
 void
 {{NAME}}_Dispatcher::{{ f["NAME"] }}(
   {%- for a in f["SIGNATURE"] -%}
  {{a["TYPE"]["NAME"]}} {{a["NAME"] }}
   {%- if not loop.last%},{% endif %}
   {%- endfor-%}
   ){

   for(auto& l_elem : this->a_list_interface) {
     l_elem->{{a["NAME"]}}(
       {%- for a in f["SIGNATURE"] -%}
       {{a["NAME"] }}{%- if not loop.last%},{% endif %}
       {%- endfor-%}
);
   }

   return;
 }
 {%- endif %}
 {%- endfor %}

 /////////////////////////////////////////////////////////////////////////////
 //                               GET and SET                               //
 /////////////////////////////////////////////////////////////////////////////
 {%- for v in DATA %}
  std::vector<{{v["TYPE"]["NAME"]}}> {{NAME}}_Dispatcher::get_{{v["NAME"]}}() const {
   std::vector<{{v["TYPE"]["NAME"]}}> l_vec;

   for(auto& l_elem : this->a_list_interface) {
     l_vec.push_back(l_elem->get_{{v["NAME"]}}());
   }

   return l_vec;
}

 void {{NAME}}_Dispatcher::set_{{v["NAME"]}}(const {{v["TYPE"]["NAME"]}} {{v["NAME"]}}) {
  for(auto& l_elem : this->a_list_interface) {
    l_elem->set_{{v["NAME"]}}({{v["NAME"]}});
   }
 }
 {%- endfor %}

