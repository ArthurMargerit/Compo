#include "Data/Struct_fac.hpp"

#include <iostream>

Struct_fac::Struct_fac() {}

Struct_fac::~Struct_fac() {}

void Struct_fac::subscribe(const std::string &ss, Struct_fac::Build_fac_f v) {
  this->childs[ss] = v;
}

Struct *Struct_fac::build(const std::string &p_type, std::istream &p_stream) {

  if (p_type == "Struct") {
    std::cerr << "Struct is virtual" << std::endl;
    return NULL;
  }

  auto f = this->childs.find(p_type);

  if (f != this->childs.end()) {
    return f->second(p_type, p_stream);
  }

  std::cerr << "Error: of Struct* build" << std::endl;
  std::cerr << "Your type \"" << p_type
            << "\" is not include or not init as a child." << std::endl;

  return NULL;
}

// Struct* Struct_fac::build(const std::string& p_type, std::istream& p_stream)
// {

//    if(p_type == "Struct") {
//      std::cerr << "Struct is virtual" << std::endl;
//      return NULL;
//    }

//    auto f = this->childs.find(p_type);

//    if (f != this->childs.end()) {
//      return f->second(p_type,p_stream);
//    }

//    std::cerr << "Error: of Struct* build" << std::endl;
//    std::cerr << "Your type \""
//              << p_type
//              << "\" is not include or not init as a child."
//              << std::endl;

//    return NULL;
//  }
