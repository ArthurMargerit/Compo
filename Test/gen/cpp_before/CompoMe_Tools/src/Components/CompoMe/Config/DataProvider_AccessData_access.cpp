

#include "Components/CompoMe/Config/DataProvider_AccessData_access.hpp"
#include "Components/CompoMe/Config/DataProvider.hpp"
#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Config {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

DataProvider_AccessData_access::DataProvider_AccessData_access(
    DataProvider *comp)
    : composant(comp) {
  return;
}

//! Destructor
DataProvider_AccessData_access::~DataProvider_AccessData_access() noexcept {
  return;
}

DataProvider &DataProvider_AccessData_access::get_c() const {
  return *this->composant;
}

CompoMe::Config::Result_state
DataProvider_AccessData_access::add(CompoMe::String key,
                                    CompoMe::String value) {
  if(this->exist(key)) {
    return RESULT_STATE_INVALID_KEY;
  }

  auto& values = this->get_c().a_values();
  values[key] = value;

  return RESULT_STATE_VALID;
}
CompoMe::Config::Result_state
DataProvider_AccessData_access::set(CompoMe::String key,
                                    CompoMe::String value) {

  if(! this->exist(key)){
    return RESULT_STATE_INVALID_KEY;
  }

  auto& values = this->get_c().a_values();
  C_INFO(key, " = ", value , "previous =", values[key]);
  values[key]= value;
  return RESULT_STATE_VALID;
}

CompoMe::Config::Result_state
DataProvider_AccessData_access::del(CompoMe::String key) {

  if(! this->exist(key)){
    return RESULT_STATE_INVALID_KEY;
  }

  this->get_c().a_values().erase(key);
  return RESULT_STATE_VALID;
}

CompoMe::Config::Result_get
DataProvider_AccessData_access::get(CompoMe::String key) {

  CompoMe::Config::Result_get ret = CompoMe::Config::Result_get();

  if(! this->exist(key)){
    ret.set_state(RESULT_STATE_INVALID_KEY);
    return ret;
  }

  auto& val = this->get_c().a_values();

  auto r = val.find(key);
  if( r == val.end()) {
    ret.set_state(RESULT_STATE_INVALID_KEY);
    return ret;
  }

  ret.set_state(RESULT_STATE_VALID);
  ret.set_result((*r).second);
  return ret;
}

bool DataProvider_AccessData_access::exist(CompoMe::String key) {
  auto& val = this->get_c().a_values();
  return val.find(key) != val.end();
}

// AccessData
// ///////////////////////////////////////////////////////////////////

std::ostream &DataProvider_AccessData_access::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "CompoMe::Config::DataProvider_AccessData_access";

  os << "}";
  return os;
}

std::istream &DataProvider_AccessData_access::from_stream(
    std::istream &is, CompoMe::Serialization_context_import &p_ctx) {
  char l_c = is.get();
  if (l_c != '{') {
    std::cerr << "Wrong start: '" << l_c << "' != '{'";
    throw "Wrong start: '"
          "' != '{'";
  }

  do {
    std::string args;
    std::getline(is, args, ':');

    switch (str2int(args.c_str())) {
    case str2int("type"): {
      auto t = CompoMe::get_word(is, {',', '}'});
      if (t.first != "CompoMe::Config::DataProvider_AccessData_access") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide DataProvider_AccessData_access";
      throw "wrong attribute: \"" + args +
          "\" not in provide DataProvider_AccessData_access";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace Config

} // namespace CompoMe
