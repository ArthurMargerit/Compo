#pragma once

#include "Serialization_context.hpp"
#include <functional>
#include <istream>
#include <map>
#include <memory>

namespace CompoMe {

namespace Config {

class DataProvider;

class DataProvider_fac {
public:
  using Build_fac_f = std::function<CompoMe::Config::DataProvider *(
      const std::string &, std::istream &,
      CompoMe::Serialization_context_import &)>;
  using Build_fac_f_sp =
      std::function<std::shared_ptr<CompoMe::Config::DataProvider>(
          const std::string &, std::istream &)>;

  static DataProvider_fac &get_inst() {
    static DataProvider_fac inst;
    return inst;
  }

  CompoMe::Config::DataProvider *
  build(const std::string &p_type, std::istream &p,
        CompoMe::Serialization_context_import &p_ctx);
  std::shared_ptr<CompoMe::Config::DataProvider>
  build_sp(const std::string &p_type, std::istream &p);

  void init();

  void subscribe(const std::string &ss, Build_fac_f v, Build_fac_f_sp v_sp);

private:
  DataProvider_fac();
  virtual ~DataProvider_fac();
  std::map<std::string, std::pair<Build_fac_f, Build_fac_f_sp>> childs;
};

} // namespace Config

} // namespace CompoMe
