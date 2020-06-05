#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

class C1;

class C1_fac {
public:
  using Build_fac_f = std::function<C1 *(const std::string &, std::istream &,
                                         Serialization_context_import &)>;
  using Build_fac_f_sp =
      std::function<std::shared_ptr<C1>(const std::string &, std::istream &)>;

  static C1_fac &get_inst() {
    static C1_fac inst;
    return inst;
  }

  C1 *build(const std::string &p_type, std::istream &p,
            Serialization_context_import &p_ctx);
  std::shared_ptr<C1> build_sp(const std::string &p_type, std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  C1_fac();
  virtual ~C1_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};
