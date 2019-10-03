#pragma once
#include "Errors/Error.hpp"

#include <iostream>
#include <functional>
#include <map>
#include <utility>

// SINGLETON
class Error_fac
{
 public:
  using Build_fac_f = std::function<Error*(const std::string&, std::istream&)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<Error>(const std::string&, std::istream&)>;

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
      return f->second.first(p_type,p_stream);
    }

    std::cerr << "Error: of Error build" << std::endl;
    std::cerr << "Your Error \""
              << p_type
              << "\" is not include or not init as a child."
              << std::endl;

    return NULL;
  }

  virtual
  std::shared_ptr<Error> build_sp(const std::string& p_type, std::istream& p_stream) {

    if(p_type == "Error") {
      std::cerr << "Error is virtual" << std::endl;
      return NULL;
    }

    auto f = this->childs.find(p_type);

    if (f != this->childs.end()) {
      return f->second.second(p_type,p_stream);
    }

    std::cerr << "Error: of Error build" << std::endl;
    std::cerr << "Your Error \""
              << p_type
              << "\" is not include or not init as a child."
              << std::endl;

    return NULL;
  }

  virtual void subscribe(const std::string& ss, Build_fac_f v, Build_fac_f_sp v_sp) {
    std::cout << "subscribe of "
              << ss
              << " in Error \n";

    this->childs[ss] = std::make_pair(v, v_sp);
  }

private:
  Error_fac(){
    std::cout << "--ERROR FAC" << "\n";
    return;
  }

  virtual void init() {

  }

  virtual ~Error_fac(){}

  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp> > childs;
 };

