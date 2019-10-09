
#include "Errors/Error_fac.hpp"
#include <iostream>

Error_fac::Error_fac(){}
Error_fac::~Error_fac(){}

void Error_fac::subscribe(const std::string& ss, Build_fac_f v, Build_fac_f_sp v_sp) {
  this->childs[ss] = std::make_pair(v, v_sp);
}


Error* Error_fac::build(const std::string& p_type, std::istream& p_stream) {

  if(p_type == "Error") {
    std::cerr << "Error is virtual" << std::endl;
    return NULL;
  }

  auto f = this->childs.find(p_type);

  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream);
  }

  std::cerr << "Error: of Error build" << std::endl;
  std::cerr << "Your Error \""
            << p_type
            << "\" is not include or not init as a child."
            << std::endl;

  return NULL;
}

std::shared_ptr<Error> Error_fac::build_sp(const std::string& p_type, std::istream& p_stream) {

  if(p_type == "Error") {
    std::cerr << "Error is virtual" << std::endl;
    return NULL;
  }

  auto f = this->childs.find(p_type);

  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  std::cerr << "Error: of Error build" << std::endl;
  std::cerr << "Your Error \""
            << p_type
            << "\" is not include or not init as a child."
            << std::endl;

  return NULL;
}
