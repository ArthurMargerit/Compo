#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

class HelloWord;

class HelloWord_fac {
public:
  using Build_fac_f =
      std::function<HelloWord *(const std::string &, std::istream &,
                                CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<HelloWord>(
      const std::string &, std::istream &)>;

  static HelloWord_fac &get_inst() {
    static HelloWord_fac inst;
    return inst;
  }

  HelloWord *build(const std::string &p_type, std::istream &p,
                   CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<HelloWord> build_sp(const std::string &p_type,
                                      std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  HelloWord_fac();
  virtual ~HelloWord_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};
