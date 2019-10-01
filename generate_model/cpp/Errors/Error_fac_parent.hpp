#pragma once
#include "Errors/Error.hpp"

#include <iostream>
#include <functional>
#include <map>

// SINGLETON
class Error_fac
{
 public:
  using Build_fac_f = std::function<Error*(const std::string&, std::istream&)>;

  static Error_fac& get_inst() {
    static Error_fac inst;
    return inst;
  }

  virtual
  Error* build(const std::string& p_type, std::istream& p_stream) {

    if(p_type == "Error") {
      std::cerr << "Error is virtual" << std::endl;
      return NULL;
    }

    auto f = this->childs.find(p_type);

    if (f != this->childs.end()) {
      return f->second(p_type,p_stream);
    }

    std::cerr << "Error: of Error build" << std::endl;
    std::cerr << "Your Error \""
              << p_type
              << "\" is not include or not init as a child."
              << std::endl;

    return NULL;
  }


  virtual void subscribe(const std::string& ss, Build_fac_f v) {
    std::cout << "subscribe of "
              << ss
              << " in Error \n";

    this->childs[ss] = v;
  }

private:
  Error_fac(){
    std::cout << "--ERROR FAC" << "\n";
    return;
  }

  virtual void init() {

  }

  virtual ~Error_fac(){}

  std::map<std::string, Build_fac_f> childs;
 };

