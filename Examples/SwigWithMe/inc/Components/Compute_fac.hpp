#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

class Compute;

class Compute_fac {
public:
  using Build_fac_f =
      std::function<Compute *(const std::string &, std::istream &,
                              CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<Compute>(
      const std::string &, std::istream &)>;

  static Compute_fac &get_inst() {
    static Compute_fac inst;
    return inst;
  }

  Compute *build(const std::string &p_type, std::istream &p,
                 CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<Compute> build_sp(const std::string &p_type, std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  Compute_fac();
  virtual ~Compute_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};
