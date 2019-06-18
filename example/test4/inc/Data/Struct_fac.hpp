#pragma once
#include "Data/Struct.hpp"

#include <iostream>
#include <functional>
#include <map>

// SINGLETON
class Struct_fac
{
 public:
  using Build_fac_f = std::function<Struct*(const std::string&, std::istream&)>;

  static Struct_fac& get_inst() {
    static Struct_fac inst;
    return inst;
  }

  virtual
  Struct* build(const std::string& p_type, std::istream& p_stream) {

    if(p_type == "Struct") {
      std::cerr << "Struct is virtual" << std::endl;
      return NULL;
    }

    auto f = this->childs.find(p_type);

    if (f != this->childs.end()) {
      return f->second(p_type,p_stream);
    }

    std::cerr << "Error: of Struct* build" << std::endl;
    std::cerr << "Your type \""
              << p_type
              << "\" is not include or not init as a child."
              << std::endl;

    return NULL;
  }


  virtual void subscribe(const std::string& ss, Build_fac_f v) {
    std::cout << "subscribe of "
              << ss
              << " in Struct \n";

    this->childs[ss] = v;
  }

private:
  Struct_fac(){
    std::cout << "--STRUCT FAC" << "\n";
    return;
  }

  virtual void init() {

  }

  virtual ~Struct_fac(){}

  std::map<std::string, Build_fac_f> childs;
 };
