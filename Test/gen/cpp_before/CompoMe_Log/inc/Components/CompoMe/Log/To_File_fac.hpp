#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

namespace CompoMe {

namespace Log {

class To_File;

class To_File_fac {
public:
  using Build_fac_f = std::function<CompoMe::Log::To_File *(
      const std::string &, std::istream &,
      CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp = std::function<std::shared_ptr<CompoMe::Log::To_File>(
      const std::string &, std::istream &)>;

  static To_File_fac &get_inst() {
    static To_File_fac inst;
    return inst;
  }

  CompoMe::Log::To_File *build(const std::string &p_type, std::istream &p,
                               CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<CompoMe::Log::To_File> build_sp(const std::string &p_type,
                                                  std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  To_File_fac();
  virtual ~To_File_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};

} // namespace Log

} // namespace CompoMe
