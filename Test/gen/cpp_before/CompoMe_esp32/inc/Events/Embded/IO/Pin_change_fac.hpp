#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

namespace Embded {

namespace IO {

class Pin_change;

class Pin_change_fac {
public:
  using Build_fac_f = std::function<Embded::IO::Pin_change *(
      const std::string &, std::istream &,
      CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<Embded::IO::Pin_change>(
      const std::string &, std::istream &)>;

  static Pin_change_fac &get_inst() {
    static Pin_change_fac inst;
    return inst;
  }

  Embded::IO::Pin_change *build(const std::string &p_type, std::istream &p,
                                CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<Embded::IO::Pin_change> build_sp(const std::string &p_type,
                                                   std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  Pin_change_fac();
  virtual ~Pin_change_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};

} // namespace IO

} // namespace Embded
