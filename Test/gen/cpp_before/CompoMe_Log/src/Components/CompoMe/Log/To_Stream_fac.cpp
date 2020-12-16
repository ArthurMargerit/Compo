#include "Components/CompoMe/Log/To_Stream_fac.hpp"
#include "Components/CompoMe/Log/To_Stream.hpp"

#include <cstdlib>
#include <string>
#include <utility>

#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Log {

To_Stream_fac::To_Stream_fac() { this->init(); }

To_Stream_fac::~To_Stream_fac() {}

CompoMe::Log::To_Stream *
To_Stream_fac::build(const std::string &p_type, std::istream &p_stream,
                     CompoMe::Serialization_context_import &p_ctx) {

  if (p_type == "CompoMe::Log::To_Stream") {
    // void* l_addr = get_addr(is);
    // if(p_ctx.is_share_ptr(l_addr)) {
    //   std::shared_ptr<{NAME}}> b = std::make_shared<To_Stream>();
    //   b->from_stream(p_stream, p_ctx);
    // } else {
    CompoMe::Log::To_Stream *b = new CompoMe::Log::To_Stream();
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

std::shared_ptr<CompoMe::Log::To_Stream>
To_Stream_fac::build_sp(const std::string &p_type, std::istream &p_stream) {

  if (p_type == "CompoMe::Log::To_Stream") {
    auto b = std::make_shared<CompoMe::Log::To_Stream>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  C_ERROR("Error: of std::shared_ptr<CompoMe::Log::To_Stream> build ",
          "Your type \"", p_type, "\" is not include or not init as a child.");

  return std::shared_ptr<CompoMe::Log::To_Stream>();
}

void To_Stream_fac::init() {

  CompoMe::Serializable_fac::Build_fac_f f =
      [](const std::string &str, std::istream &p_s,
         CompoMe::Serialization_context_import &l_ctx) {
        return dynamic_cast<CompoMe::Serializable_Item *>(
            To_Stream_fac::get_inst().build(str, p_s, l_ctx));
      };
  CompoMe::Serializable_fac::Build_fac_f_sp f_sp = [](const std::string &str,
                                                      std::istream &p_s) {
    return To_Stream_fac::get_inst().build_sp(str, p_s);
  };

  CompoMe::Serializable_fac::get_inst().subscribe("CompoMe::Log::To_Stream", f,
                                                  f_sp);
}

void To_Stream_fac::subscribe(const std::string &ss, Build_fac_f v,
                              Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v, v_sp);

  CompoMe::Serializable_fac::get_inst().subscribe(ss, v, v_sp);
}

} // namespace Log

} // namespace CompoMe
