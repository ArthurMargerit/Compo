#include "Data/Struct_fac_{{NAME}}.hpp"

#include <iostream>


#include "Data/Struct_{{NAME}}.hpp"
{%if PARENT %}
#include "Data/Struct_fac_{{PARENT.NAME}}.hpp"
{%else%}
#include "Data/Struct_fac.hpp"
{%endif%}

{{NAME}}_fac::{{NAME}}_fac() {
  std::cout << "--{{NAME}}_fac build" << "\n";
  this->init();
                      }

{{NAME}}_fac::~{{NAME}}_fac(){

                       }


{{NAME}}* {{NAME}}_fac::build(const std::string& p_type, std::istream& p_stream) {

  if (p_type == "{{NAME}}") {
    std::cout << "build of {{NAME}}*" << "\n";
    {{NAME}}* b = new {{NAME}}();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second(p_type, p_stream);
  }

  std::cerr << "Error: of Struct* build" << std::endl;
  std::cerr << "Your type \""
            << p_type
            << "\" is not include or not init as a child."
            << std::endl;

  return NULL;
}


void {{NAME}}_fac::init() {

    {%if PARENT %}
    {{PARENT.NAME}}_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s)
                                         {return ({{PARENT.NAME}}*) {{NAME}}_fac::get_inst().build(str,p_s); };
    {{PARENT.NAME}}_fac::get_inst().subscribe("{{NAME}}", f);
    {%else%}
    Struct_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s)
                                {return (Struct*) {{NAME}}_fac::get_inst().build(str,p_s); };

    Struct_fac::get_inst().subscribe("{{NAME}}", f);

    {%endif%}
  }


 void {{NAME}}_fac::subscribe(const std::string& ss, Build_fac_f v) {

   this->childs[ss] = v;

   std::cout << "subscribe of "
             << ss
             << " in {{NAME}}.\n";

   {%if PARENT %}
   {{PARENT.NAME}}_fac::get_inst().subscribe(ss, v);
   {%else%}
   Struct_fac::get_inst().subscribe(ss, v);
   {%endif%}
 }


std::ostream& operator<<(std::ostream& os, const {{NAME}}* c) {
  os << (Struct*) c;
  return os;
}

std::istream& operator>>(std::istream& is, {{NAME}}*& c) {
  if(c != NULL) {
    delete c;
  }

  if(is.peek() == '0') {
    c = NULL;
    return is;
  }

  if(is.peek() == 'N' || is.peek() == 'n') {
    std::string need_null;
    is >> need_null;
    if(need_null == "NULL" || need_null == "null" || need_null == "Null") {
      c = NULL;
      return is;
    }

    throw "bad null pointer";
  }

  if(is.peek() != '*') {
    throw "is not a pointer";
  }

  is.get();
  std::string t = get_type(is);
  c = {{NAME}}_fac::get_inst().build(t,is);

  return is;
}
