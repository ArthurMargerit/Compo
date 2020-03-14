#include "Data/Struct_fac.hpp"

#include <iostream>

Struct_fac::Struct_fac() {}

Struct_fac::~Struct_fac() {}

void Struct_fac::subscribe(const std::string &ss, Struct_fac::Build_fac_f v, Struct_fac::Build_fac_f_sp v_sp) {
  this->childs[ss] = std::make_pair(v,v_sp);
}

Struct *Struct_fac::build(const std::string &p_type, std::istream &p_stream, Serialization_context &p_ctx) {

  if (p_type == "Struct") {
    std::cerr << "Struct is virtual" << std::endl;
    return NULL;
  }

  auto f = this->childs.find(p_type);

  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream, p_ctx);
  }

  std::cerr << "Error: of Struct* build" << std::endl;
  std::cerr << "Your type \"" << p_type
            << "\" is not include or not init as a child." << std::endl;

  return NULL;
}

std::shared_ptr<Struct> Struct_fac::build_sp(const std::string &p_type, std::istream &p_stream) {

  if (p_type == "Struct") {
    std::cerr << "Struct is virtual" << std::endl;
    return NULL;
  }

  auto f = this->childs.find(p_type);

  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  std::cerr << "Error: of Struct* build" << std::endl;
  std::cerr << "Your type \"" << p_type
            << "\" is not include or not init as a child." << std::endl;

  return std::shared_ptr<Struct>();
}

// std::istream &operator>>(std::istream &is, std::shared_ptr<Struct> &c){
//   // // NULL
//   // if (is.peek() == '0') {
//   //   is.get();
//   //   c = std::shared_ptr<Struct>();
//   //   return is;
//   // }

//   // // NULL
//   // char cc = is.peek();
//   // if (cc == 'N') {
//   //   std::string need_null;
//   //   is >> need_null;
//   //   if (need_null == "NULL" || need_null == "Null" || need_null == "null") {
//   //     c =  std::shared_ptr<Struct>();
//   //     return is;
//   //   }

//   //   throw "Error in NULL word";
//   // }

//   // // not valid
//   // if (is.peek() != '*') {
//   //   throw ("Not compliant with std::shared_ptr<struct>");
//   // }
//   // // remove the *
//   // is.get();

//   // // build it
//   // std::string t = get_type(is);
//   // c = Struct_fac::get_inst().build_sp(t, is);
//   return is;
// }
