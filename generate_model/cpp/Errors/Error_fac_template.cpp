// #include "Errors/{{F_NAME}}_fac.hpp"

// #include <iostream>
// #include "Serialization_context.hpp"

// #include "Errors/{{F_NAME}}.hpp"
// {%if PARENT %}
// #include "Errors/{{PARENT.F_NAME}}_fac.hpp"
// {%else%}
// #include "Errors/Error_fac.hpp"
// {%endif%}

// {%include "helper/namespace_open.hpp" with context%}

// {{NAME}}_fac::{{NAME}}_fac() {
//   this->init();
//  }

// {{NAME}}_fac::~{{NAME}}_fac(){}

// {{D_NAME}}* {{NAME}}_fac::build(const std::string& p_type, std::istream& p_stream) {

//   if (p_type == "{{D_NAME}}") {
//     {{D_NAME}}* b = new {{D_NAME}}();
//     p_stream >> *b;
//     return b;
//   }

//   // child build
//   auto f = this->childs.find(p_type);
//   if (f != this->childs.end()) {
//     return f->second.first(p_type, p_stream);
//   }

//   std::cerr << "Error: of Error build"
//             << "Your type \""
//             << p_type
//             << "\" is not include or not init as a child."
//             << std::endl;

//   return NULL;
// }

// std::shared_ptr<{{D_NAME}}> {{NAME}}_fac::build_sp(const std::string& p_type, std::istream& p_stream) {

//   if (p_type == "{{D_NAME}}") {
//     std::shared_ptr<{{D_NAME}}> b = std::make_shared<{{D_NAME}}>();
//     p_stream >> *b;
//     return b;
//   }

//   // child build
//   auto f = this->childs.find(p_type);
//   if (f != this->childs.end()) {
//     return f->second.second(p_type, p_stream);
//   }

//   std::cerr << "Error: of Error build" << std::endl;
//   std::cerr << "Your type \""
//             << p_type
//             << "\" is not include or not init as a child."
//             << std::endl;

//   return NULL;
// }

// void {{NAME}}_fac::init() {

//     {%if PARENT %}
//     {{PARENT.D_NAME}}_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s)
//                                          {return dynamic_cast<{{PARENT.D_NAME}}*>({{D_NAME}}_fac::get_inst().build(str,p_s)); };
//     {{PARENT.D_NAME}}_fac::Build_fac_f_sp  f_sp= [](const std::string& str,std::istream& p_s)
//                                      {return {{D_NAME}}_fac::get_inst().build_sp(str,p_s); };

//     {{PARENT.D_NAME}}_fac::get_inst().subscribe("{{D_NAME}}", f, f_sp);
//     {%else%}
//     Error_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s)
//                                {return dynamic_cast<Error*>({{NAME}}_fac::get_inst().build(str,p_s)); };
//     Error_fac::Build_fac_f_sp  f_sp= [](const std::string& str,std::istream& p_s)
//                                   {return {{D_NAME}}_fac::get_inst().build_sp(str,p_s); };

//     Error_fac::get_inst().subscribe("{{D_NAME}}", f, f_sp);

//     {%endif%}
//   }


// void {{NAME}}_fac::subscribe(const std::string& ss, Build_fac_f v, Build_fac_f_sp v_sp) {

//   this->childs[ss] = std::make_pair(v, v_sp);

//    {%if PARENT %}
//    {{PARENT.D_NAME}}_fac::get_inst().subscribe(ss, v, v_sp);
//    {%else%}
//    Error_fac::get_inst().subscribe(ss, v, v_sp);
//    {%endif%}
//  }


// std::ostream& operator<<(std::ostream& os, const {{D_NAME}}* c) {
//   if(c == NULL) {
//     os << 0;
//   } else {
//     os << dynamic_cast<const Error*>(c);
//   }

//   return os;
// }

// std::istream& operator>>(std::istream& is, {{D_NAME}}*& c) {
//   if(c != NULL) {
//     delete c;
//   }

//   if(is.peek() == '0') {
//     c = NULL;
//     return is;
//   }

//   if(is.peek() == 'N' || is.peek() == 'n') {
//     std::string need_null;
//     is >> need_null;
//     if(need_null == "NULL" || need_null == "null" || need_null == "Null") {
//       c = NULL;
//       return is;
//     }

//     throw "bad null pointer";
//   }

//   if(is.peek() != '*') {
//     throw "is not a pointer";
//   }

//   is.get();
//   std::string t = get_type(is);
//   c = {{D_NAME}}_fac::get_inst().build(t,is);

//   return is;
// }


// std::ostream& operator<<(std::ostream& os, const std::shared_ptr<{{D_NAME}}>& c) {
//   if(c == nullptr) {
//     os << 0;
//     return os;
//   }

//   os << c;
//   return os;
// }


// std::istream& operator>>(std::istream& is, std::shared_ptr<{{D_NAME}}>& c) {

//   if(is.peek() == '0') {
//     is.get();

//     c = std::shared_ptr<{{D_NAME}}>();
//     return is;
//   }

//   if(is.peek() == 'N' || is.peek() == 'n') {
//     std::string need_null;
//     is >> need_null;
//     if(need_null == "NULL" || need_null == "null" || need_null == "Null") {
//       c = std::shared_ptr<{{D_NAME}}>();
//       return is;
//     }

//     throw "bad null pointer";
//   }

//   if(is.peek() != '*') {
//     throw "is not a pointer";
//   }

//   is.get();
//   std::string t = get_type(is);
//     c = {{D_NAME}}_fac::get_inst().build_sp(t,is);

//   return is;
// }
// {%include "helper/namespace_close.hpp" with context%} 
