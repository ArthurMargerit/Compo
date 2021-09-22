#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

namespace CompoMe {

namespace Log {

class Log_buffer;

class Log_buffer_fac {
public:
  using Build_fac_f = std::function<CompoMe::Log::Log_buffer *(
      const std::string &, std::istream &,
      CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp =
      std::function<std::shared_ptr<CompoMe::Log::Log_buffer>(
          const std::string &, std::istream &)>;

  static Log_buffer_fac &get_inst() {
    static Log_buffer_fac inst;
    return inst;
  }

  CompoMe::Log::Log_buffer *build(const std::string &p_type, std::istream &p,
                                  CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<CompoMe::Log::Log_buffer> build_sp(const std::string &p_type,
                                                     std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  Log_buffer_fac();
  virtual ~Log_buffer_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};

} // namespace Log

} // namespace CompoMe
