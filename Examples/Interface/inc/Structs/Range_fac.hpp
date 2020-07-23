#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

class Range;

class Range_fac {
public:
  using Build_fac_f =
      std::function<Range *(const std::string &, std::istream &,
                            CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<Range>(
      const std::string &, std::istream &)>;

  static Range_fac &get_inst() {
    static Range_fac inst;
    return inst;
  }

  Range *build(const std::string &p_type, std::istream &p,
               CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<Range> build_sp(const std::string &p_type, std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  Range_fac();
  virtual ~Range_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};
