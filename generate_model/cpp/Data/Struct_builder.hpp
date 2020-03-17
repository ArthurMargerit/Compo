#pragma once

#include "Data/{{NAMESPACE.replace('::','/')}}/Struct_{{NAME}}.hpp"
{% if PARENT %}
#include "Data/{{PARENT.NAMESPACE.replace('::','/')}}/Struct_{{PARENT.NAME}}_builder.hpp"
{% endif %}
#include <memory>

{%include "helper/namespace_open.hpp" with context %}

class {{NAME}}_builder {%if PARENT %}: private {{PARENT.D_NAME}}_builder{% endif %}{

 public:
  {{NAME}}_builder();
   virtual ~{{NAME}}_builder();

 // setter
   {%for i_d in Function.model_get.get_all_field(DATA,PARENT) %}

  {{NAME}}_builder& set_{{i_d.NAME}}(const {{i_d.TYPE.D_NAME}}& p_{{i_d.NAME}});
   {% endfor %}

 // build
   {{NAME}} build();
   {{NAME}}* build_p();
   std::shared_ptr<{{NAME}}> build_sp();


 protected:
   void asign({{NAME}}& p_name);

 private:
   {%for i_d in DATA %}
 {{i_d.TYPE.D_NAME}} {{i_d.NAME}} {% if "DEFAULT" in i_d %}
 = {{i_d.DEFAULT}}
 {%elif "DEFAULT" in i_d.TYPE %}
 = {{i_d.TYPE.DEFAULT}}
 {% endif %};
 {% endfor %}

};
{%include "helper/namespace_close.hpp" with context %}
