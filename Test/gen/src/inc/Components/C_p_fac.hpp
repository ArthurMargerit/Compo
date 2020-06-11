#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

class C_p;

class C_p_fac {
public:
  using Build_fac_f = std::function<C_p *(const std::string &, std::istream &,
                                          Serialization_context_import &)>;
  using Build_fac_f_sp =
      std::function<std::shared_ptr<C_p>(const std::string &, std::istream &)>;

  static C_p_fac &get_inst() {
    static C_p_fac inst;
    return inst;
  }

  C_p *build(const std::string &p_type, std::istream &p,
             Serialization_context_import &p_ctx);
  std::shared_ptr<C_p> build_sp(const std::string &p_type, std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  C_p_fac();
  virtual ~C_p_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};
