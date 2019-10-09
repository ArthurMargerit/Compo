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
    {{NAME}}* b = new {{NAME}}();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream);
  }

  std::cerr << "Error: of Struct* build "
            << "Your type \""
            << p_type
            << "\" is not include or not init as a child."
            << std::endl;

  return NULL;
}

std::shared_ptr<{{NAME}}> {{NAME}}_fac::build_sp(const std::string& p_type, std::istream& p_stream) {

  if (p_type == "{{NAME}}") {
    auto b =std::make_shared<{{NAME}}>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  std::cerr << "Error: of std::shared_ptr<{{NAME}}> build "
            << "Your type \""
            << p_type
            << "\" is not include or not init as a child."
            << std::endl;

  return std::shared_ptr<{{NAME}}>();
}


void {{NAME}}_fac::init() {

    {%if PARENT %}
    {{PARENT.NAME}}_fac::Build_fac_f f = [](const std::string& str,std::istream& p_s)
                                         {return ({{PARENT.NAME}}*) {{NAME}}_fac::get_inst().build(str,p_s);};

    {{PARENT.NAME}}_fac::Build_fac_f_sp f_sp = [](const std::string& str,std::istream& p_s)
                                               {return {{NAME}}_fac::get_inst().build_sp(str,p_s);};

    {{PARENT.NAME}}_fac::get_inst().subscribe("{{NAME}}", f, f_sp);
    {%else%}
    Struct_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s)
                                {return (Struct*) {{NAME}}_fac::get_inst().build(str,p_s); };
    Struct_fac::Build_fac_f_sp  f_sp= [](const std::string& str,std::istream& p_s)
                                {return {{NAME}}_fac::get_inst().build_sp(str,p_s); };

    Struct_fac::get_inst().subscribe("{{NAME}}", f, f_sp);
    {%endif%}
  }


void {{NAME}}_fac::subscribe(const std::string& ss, Build_fac_f v,Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v,v_sp);

  {%if PARENT %}
  {{PARENT.NAME}}_fac::get_inst().subscribe(ss, v, v_sp);
  {%else%}
  Struct_fac::get_inst().subscribe(ss, v, v_sp);
  {%endif%}
 }


std::ostream& operator<<(std::ostream& os, const {{NAME}}* c) {
  if(c == NULL) {
    os << 0;
  } else {
    os << (Struct*) c;
  }

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


std::ostream& operator<<(std::ostream& os, const std::shared_ptr<{{NAME}}> c){
  if(c == nullptr) {
    os << 0;
    return os;
  }

  os << c;
  return os;
}

std::istream& operator>>(std::istream& is, std::shared_ptr<{{NAME}}>& c){

  if(is.peek() == '0') {
    is.get();

    c = std::shared_ptr<{{NAME}}>();
    return is;
  }

  if(is.peek() == 'N' || is.peek() == 'n') {
    std::string need_null;
    is >> need_null;
    if(need_null == "NULL" || need_null == "null" || need_null == "Null") {
      c = std::shared_ptr<{{NAME}}>();
      return is;
    }

    throw "bad null pointer";
  }

  if(is.peek() != '*') {
    throw "is not a pointer";
  }

  is.get();
  std::string t = get_type(is);
  c = {{NAME}}_fac::get_inst().build_sp(t,is);

  return is;
}
