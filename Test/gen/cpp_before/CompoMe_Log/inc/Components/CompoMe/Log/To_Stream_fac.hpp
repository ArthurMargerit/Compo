#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

namespace CompoMe {

namespace Log {

class To_Stream;

class To_Stream_fac {
public:
  using Build_fac_f = std::function<CompoMe::Log::To_Stream *(
      const std::string &, std::istream &,
      CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<CompoMe::Log::To_Stream>(
      const std::string &, std::istream &)>;

  static To_Stream_fac &get_inst() {
    static To_Stream_fac inst;
    return inst;
  }

  CompoMe::Log::To_Stream *build(const std::string &p_type, std::istream &p,
                                 CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<CompoMe::Log::To_Stream> build_sp(const std::string &p_type,
                                                    std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  To_Stream_fac();
  virtual ~To_Stream_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};

} // namespace Log

} // namespace CompoMe
