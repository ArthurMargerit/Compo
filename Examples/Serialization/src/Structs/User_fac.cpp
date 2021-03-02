#include "Structs/User_fac.hpp"
#include "Structs/User.hpp"

#include <cstdlib>
#include <string>
#include <utility>

#include "CompoMe/Log.hpp"

User_fac::User_fac() { this->init(); }

User_fac::~User_fac() {}

User *User_fac::build(const std::string &p_type, std::istream &p_stream,
                      CompoMe::Serialization_context_import &p_ctx) {

  if (p_type == "User") {
    // void* l_addr = get_addr(is);
    // if(p_ctx.is_share_ptr(l_addr)) {
    //   std::shared_ptr<{NAME}}> b = std::make_shared<User>();
    //   b->from_stream(p_stream, p_ctx);
    // } else {
    User *b = new User();
    b->from_stream(p_stream, p_ctx);
    //    }
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream, p_ctx);
  }

  C_ERROR("Error: of Serializable* build ", "Your type \"", p_type,
          "\" is not include or not init as a child.");

  return NULL;
}

std::shared_ptr<User> User_fac::build_sp(const std::string &p_type,
                                         std::istream &p_stream) {

  if (p_type == "User") {
    auto b = std::make_shared<User>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  C_ERROR("Error: of std::shared_ptr<User> build ", "Your type \"", p_type,
          "\" is not include or not init as a child.");

  return std::shared_ptr<User>();
}

void User_fac::init() {

  CompoMe::Serializable_fac::Build_fac_f f =
      [](const std::string &str, std::istream &p_s,
         CompoMe::Serialization_context_import &l_ctx) {
        return dynamic_cast<CompoMe::Serializable_Item *>(
            User_fac::get_inst().build(str, p_s, l_ctx));
      };
  CompoMe::Serializable_fac::Build_fac_f_sp f_sp = [](const std::string &str,
                                                      std::istream &p_s) {
    return User_fac::get_inst().build_sp(str, p_s);
  };

  CompoMe::Serializable_fac::get_inst().subscribe("User", f, f_sp);
}

void User_fac::subscribe(const std::string &ss, Build_fac_f v,
                         Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v, v_sp);

  CompoMe::Serializable_fac::get_inst().subscribe(ss, v, v_sp);
}
