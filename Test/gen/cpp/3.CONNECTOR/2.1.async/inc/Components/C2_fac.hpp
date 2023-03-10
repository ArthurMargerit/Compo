#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

class C2;

class C2_fac {
public:
  using Build_fac_f =
      std::function<C2 *(const std::string &, std::istream &,
                         CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp =
      std::function<std::shared_ptr<C2>(const std::string &, std::istream &)>;

  static C2_fac &get_inst() {
    static C2_fac inst;
    return inst;
  }

  C2 *build(const std::string &p_type, std::istream &p,
            CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<C2> build_sp(const std::string &p_type, std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  C2_fac();
  virtual ~C2_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};
