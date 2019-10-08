#pragma once
#include "Data/Struct.hpp"

#include <functional>
#include <istream>
#include <map>

// SINGLETON
class Struct_fac {
public:
  using Build_fac_f =
      std::function<Struct *(const std::string &, std::istream &)>;

  static Struct_fac &get_inst() {
    static Struct_fac inst;
    return inst;
  }

  virtual Struct *build(const std::string &p_type, std::istream &p_stream);

  virtual void subscribe(const std::string &ss, Build_fac_f v);

private:
  Struct_fac();
  virtual ~Struct_fac();

  std::map<std::string, Build_fac_f> childs;
};
