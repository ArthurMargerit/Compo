#include "Components/CompoMe/Config/DataProvider_fac.hpp"
#include "Components/CompoMe/Config/DataProvider.hpp"

#include <iostream>

namespace CompoMe {

namespace Config {

DataProvider_fac::DataProvider_fac() { this->init(); }

DataProvider_fac::~DataProvider_fac() {}

CompoMe::Config::DataProvider *
DataProvider_fac::build(const std::string &p_type, std::istream &p_stream,
                        CompoMe::Serialization_context_import &p_ctx) {

  if (p_type == "CompoMe::Config::DataProvider") {
    // void* l_addr = get_addr(is);
    // if(p_ctx.is_share_ptr(l_addr)) {
    //   std::shared_ptr<{NAME}}> b = std::make_shared<DataProvider>();
    //   b->from_stream(p_stream, p_ctx);
    // } else {
    CompoMe::Config::DataProvider *b = new CompoMe::Config::DataProvider();
    b->from_stream(p_stream, p_ctx);
    //    }
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream, p_ctx);
  }

  std::cerr << "Error: of Serializable* build "
            << "Your type \"" << p_type
            << "\" is not include or not init as a child." << std::endl;

  return NULL;
}

std::shared_ptr<CompoMe::Config::DataProvider>
DataProvider_fac::build_sp(const std::string &p_type, std::istream &p_stream) {

  if (p_type == "CompoMe::Config::DataProvider") {
    auto b = std::make_shared<CompoMe::Config::DataProvider>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  std::cerr << "Error: of std::shared_ptr<CompoMe::Config::DataProvider> build "
            << "Your type \"" << p_type
            << "\" is not include or not init as a child." << std::endl;

  return std::shared_ptr<CompoMe::Config::DataProvider>();
}

void DataProvider_fac::init() {

  CompoMe::Serializable_fac::Build_fac_f f =
      [](const std::string &str, std::istream &p_s,
         CompoMe::Serialization_context_import &l_ctx) {
        return dynamic_cast<CompoMe::Serializable_Item *>(
            DataProvider_fac::get_inst().build(str, p_s, l_ctx));
      };
  CompoMe::Serializable_fac::Build_fac_f_sp f_sp = [](const std::string &str,
                                                      std::istream &p_s) {
    return DataProvider_fac::get_inst().build_sp(str, p_s);
  };

  CompoMe::Serializable_fac::get_inst().subscribe(
      "CompoMe::Config::DataProvider", f, f_sp);
}

void DataProvider_fac::subscribe(const std::string &ss, Build_fac_f v,
                                 Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v, v_sp);

  CompoMe::Serializable_fac::get_inst().subscribe(ss, v, v_sp);
}

} // namespace Config

} // namespace CompoMe
