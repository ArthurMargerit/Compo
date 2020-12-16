#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

namespace Car {

namespace Gates {

class controller;

class controller_fac {
public:
  using Build_fac_f = std::function<Car::Gates::controller *(
      const std::string &, std::istream &,
      CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<Car::Gates::controller>(
      const std::string &, std::istream &)>;

  static controller_fac &get_inst() {
    static controller_fac inst;
    return inst;
  }

  Car::Gates::controller *build(const std::string &p_type, std::istream &p,
                                CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<Car::Gates::controller> build_sp(const std::string &p_type,
                                                   std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  controller_fac();
  virtual ~controller_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};

} // namespace Gates

} // namespace Car
