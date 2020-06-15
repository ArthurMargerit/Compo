#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

class User;

class User_fac {
public:
  using Build_fac_f = std::function<User *(const std::string &, std::istream &,
                                           Serialization_context_import &)>;
  using Build_fac_f_sp =
      std::function<std::shared_ptr<User>(const std::string &, std::istream &)>;

  static User_fac &get_inst() {
    static User_fac inst;
    return inst;
  }

  User *build(const std::string &p_type, std::istream &p,
              Serialization_context_import &p_ctx);
  std::shared_ptr<User> build_sp(const std::string &p_type, std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  User_fac();
  virtual ~User_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};
