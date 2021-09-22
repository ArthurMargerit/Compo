#include "Components/CompoMe/Log/Log_buffer_fac.hpp"
#include "Components/CompoMe/Log/Log_buffer.hpp"

#include <cstdlib>
#include <string>
#include <utility>

#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Log {

Log_buffer_fac::Log_buffer_fac() { this->init(); }

Log_buffer_fac::~Log_buffer_fac() {}

CompoMe::Log::Log_buffer *
Log_buffer_fac::build(const std::string &p_type, std::istream &p_stream,
                      CompoMe::Serialization_context_import &p_ctx) {

  if (p_type == "CompoMe::Log::Log_buffer") {
    // void* l_addr = get_addr(is);
    // if(p_ctx.is_share_ptr(l_addr)) {
    //   std::shared_ptr<{NAME}}> b = std::make_shared<Log_buffer>();
    //   b->from_stream(p_stream, p_ctx);
    // } else {
    CompoMe::Log::Log_buffer *b = new CompoMe::Log::Log_buffer();
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

std::shared_ptr<CompoMe::Log::Log_buffer>
Log_buffer_fac::build_sp(const std::string &p_type, std::istream &p_stream) {

  if (p_type == "CompoMe::Log::Log_buffer") {
    auto b = std::make_shared<CompoMe::Log::Log_buffer>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  C_ERROR("Error: of std::shared_ptr<CompoMe::Log::Log_buffer> build ",
          "Your type \"", p_type, "\" is not include or not init as a child.");

  return std::shared_ptr<CompoMe::Log::Log_buffer>();
}

void Log_buffer_fac::init() {

  CompoMe::Serializable_fac::Build_fac_f f =
      [](const std::string &str, std::istream &p_s,
         CompoMe::Serialization_context_import &l_ctx) {
        return dynamic_cast<CompoMe::Serializable_Item *>(
            Log_buffer_fac::get_inst().build(str, p_s, l_ctx));
      };
  CompoMe::Serializable_fac::Build_fac_f_sp f_sp = [](const std::string &str,
                                                      std::istream &p_s) {
    return Log_buffer_fac::get_inst().build_sp(str, p_s);
  };

  CompoMe::Serializable_fac::get_inst().subscribe("CompoMe::Log::Log_buffer", f,
                                                  f_sp);
}

void Log_buffer_fac::subscribe(const std::string &ss, Build_fac_f v,
                               Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v, v_sp);

  CompoMe::Serializable_fac::get_inst().subscribe(ss, v, v_sp);
}

} // namespace Log

} // namespace CompoMe
