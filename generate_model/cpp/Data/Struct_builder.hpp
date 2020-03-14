#pragma once

#include "Data/Struct_{{NAME}}.hpp"
{% if PARENT %}
#include "Data/Struct_{{PARENT.NAME}}_builder.hpp"
{% endif %}
#include <memory>

class {{NAME}}_builder {%if PARENT %}: private {{PARENT.NAME}}_builder{% endif %}{

 public:
  {{NAME}}_builder();
   virtual ~{{NAME}}_builder();

 // setter
   {%for i_d in Function.model_get.get_all_field(DATA,PARENT) %}

  {{NAME}}_builder& set_{{i_d.NAME}}(const {{i_d.TYPE.NAME}}& p_{{i_d.NAME}});
   {% endfor %}

 // build
   {{NAME}} build();
   {{NAME}}* build_p();
   std::shared_ptr<{{NAME}}> build_sp();


 protected:
   void asign({{NAME}}& p_name);

 private:
   {%for i_d in DATA %}
 {{i_d.TYPE.NAME}} {{i_d.NAME}} {% if "DEFAULT" in i_d %}
 = {{i_d.DEFAULT}}
 {%elif "DEFAULT" in i_d.TYPE %}
 = {{i_d.TYPE.DEFAULT}}
 {% endif %};
 {% endfor %}

};
