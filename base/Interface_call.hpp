#pragma once

#include "types.hpp"
#include "structs.hpp"


constexpr unsigned int str2int(const char* str, int h = 0)
{
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

template <typename Ti, typename To, typename C>
class {{NAME}}_caller
{
 private:
  Ti& in ;
  To& out;
  C& comp;

 public:

 {{NAME}}_caller(Ti& pin, To& pout, C& pcomp)
 :in(pin),
 out(pout),
 comp(pcomp)
 {
   
   return ;
 }

  bool call()
       {

         std::string name_function;

         in >> name_function;

         switch(str2int(name_function.c_str())){
           {% for func in FUNCTION%}
         case str2int("{{func.NAME}}"):
             out << this->{{func.NAME}}() << std::endl;
             return true;
             break;
           {% endfor %}
         };

         return false;
       }


  {% for func in FUNCTION %}
  void {{ func.NAME }}()
  {
    {% for arg in func.SIGNATURE %}
    {{arg.TYPE.NAME}} l_{{arg.NAME}};
    ti >> l_{{arg.NAME}};
    {% endfor %}

    return this->comp->{{ func.NAME }}({% for arg in func.SIGNATURE -%}
    l_{{arg.NAME}}
      {%- if not loop.last %}, {% endif %}
      {%- endfor %});
  }
  {% endfor %}
};

