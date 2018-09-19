#pragma once


#include <iostream>
#include "global/{{NAME}}.hpp"

constexpr unsigned int str2int(const char* str, int h = 0)
{
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

template <typename Ti, typename To>
class {{NAME}}_caller
{
 private:
  Ti& in ;
  To& out;
  {{NAME}}& comp;

 public:

  {{NAME}}_caller(Ti& pin, To& pout, {{NAME}}& pcomp)
 :in(pin),
 out(pout),
 comp(pcomp)
 {

   return ;
 }

  bool call()
       {

         std::string name_function;

         std::getline(in, name_function, '(');
         std::cout << "function:<"<< name_function <<">"  << "\n";

         switch(str2int(name_function.c_str())){
           {% for func in FUNCTION%}
         case str2int("{{func.NAME}}"):
           this->{{func.NAME}}();
           return true;
           break;
           {% endfor %}
           {% for d in DATA%}
         case str2int("get_{{d.NAME}}"):
           this->get_{{d.NAME}}();
           return true;
           break;
         case str2int("set_{{d.NAME}}"):
           this->set_{{d.NAME}}();
           return true;
           break;
           {% endfor %}
         };

         std::getline(in, name_function);

         return false;
       }


  {% for func in FUNCTION %}
  void {{ func.NAME }}()
  {
    {% for arg in func.SIGNATURE %}
    {{arg.TYPE.NAME}} l_{{arg.NAME}};
    in >> l_{{arg.NAME}};
    {%- if not loop.last %}in.get();{% endif %}
    

    {% endfor %}

    std::string l;
    std::getline(in, l);

    out << this->comp.{{ func.NAME }}({% for arg in func.SIGNATURE -%}
    l_{{arg.NAME}}
      {%- if not loop.last %}, {% endif %}
      {%- endfor %}) << std::endl;

    return;
  }
  {% endfor %}

  {% for d in DATA %}
  void get_{{ d.NAME }}()
  {
    std::string l;
    std::getline(in, l);
    out << this->comp.get_{{d.NAME}}() << std::endl;

    return;
  }

  void set_{{ d.NAME }}()
  {
    {{d.TYPE.NAME}} set_val;
    in >> set_val;
    this->comp.set_{{d.NAME}}(set_val);

    std::string l;
    std::getline(in, l);

    out << std::endl;
    return;
  }
  {% endfor %}


};

