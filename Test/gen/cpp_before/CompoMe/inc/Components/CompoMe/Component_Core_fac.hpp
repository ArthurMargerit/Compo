#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

namespace CompoMe {

class Component_Core;

class Component_Core_fac {
public:
  using Build_fac_f = std::function<CompoMe::Component_Core *(
      const std::string &, std::istream &,
      CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<CompoMe::Component_Core>(
      const std::string &, std::istream &)>;

  static Component_Core_fac &get_inst() {
    static Component_Core_fac inst;
    return inst;
  }

  CompoMe::Component_Core *build(const std::string &p_type, std::istream &p,
                                 CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<CompoMe::Component_Core> build_sp(const std::string &p_type,
                                                    std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  Component_Core_fac();
  virtual ~Component_Core_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};

} // namespace CompoMe
