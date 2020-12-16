#include "Components/CompoMe/Log/Match_fac.hpp"
#include "Components/CompoMe/Log/Match.hpp"

#include <cstdlib>
#include <string>
#include <utility>

#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Log {

Match_fac::Match_fac() { this->init(); }

Match_fac::~Match_fac() {}

CompoMe::Log::Match *
Match_fac::build(const std::string &p_type, std::istream &p_stream,
                 CompoMe::Serialization_context_import &p_ctx) {

  if (p_type == "CompoMe::Log::Match") {
    // void* l_addr = get_addr(is);
    // if(p_ctx.is_share_ptr(l_addr)) {
    //   std::shared_ptr<{NAME}}> b = std::make_shared<Match>();
    //   b->from_stream(p_stream, p_ctx);
    // } else {
    CompoMe::Log::Match *b = new CompoMe::Log::Match();
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

std::shared_ptr<CompoMe::Log::Match>
Match_fac::build_sp(const std::string &p_type, std::istream &p_stream) {

  if (p_type == "CompoMe::Log::Match") {
    auto b = std::make_shared<CompoMe::Log::Match>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  C_ERROR("Error: of std::shared_ptr<CompoMe::Log::Match> build ",
          "Your type \"", p_type, "\" is not include or not init as a child.");

  return std::shared_ptr<CompoMe::Log::Match>();
}

void Match_fac::init() {

  CompoMe::Serializable_fac::Build_fac_f f =
      [](const std::string &str, std::istream &p_s,
         CompoMe::Serialization_context_import &l_ctx) {
        return dynamic_cast<CompoMe::Serializable_Item *>(
            Match_fac::get_inst().build(str, p_s, l_ctx));
      };
  CompoMe::Serializable_fac::Build_fac_f_sp f_sp = [](const std::string &str,
                                                      std::istream &p_s) {
    return Match_fac::get_inst().build_sp(str, p_s);
  };

  CompoMe::Serializable_fac::get_inst().subscribe("CompoMe::Log::Match", f,
                                                  f_sp);
}

void Match_fac::subscribe(const std::string &ss, Build_fac_f v,
                          Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v, v_sp);

  CompoMe::Serializable_fac::get_inst().subscribe(ss, v, v_sp);
}

} // namespace Log

} // namespace CompoMe
