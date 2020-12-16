

#include "Components/CompoMe/Log/Filter.hpp"
#include "Components/CompoMe/Log/Filter_Filter_Management_I_filter_Manager.hpp"
#include <cstdlib>
#include <string>

namespace CompoMe {

namespace Log {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &Filter_Filter_Management_I_filter_Manager::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "CompoMe::Log::Filter_Filter_Management_I_filter_Manager";

  os << "}";
  return os;
}

std::istream &Filter_Filter_Management_I_filter_Manager::from_stream(
    std::istream &is, CompoMe::Serialization_context_import &p_ctx) {
  char l_c = is.get();
  if (l_c != '{') {
    C_ERROR("Wrong start: '", l_c, "' != '{'");
    throw "Wrong start: '"
          "' != '{'";
  }

  do {
    std::string args;
    std::getline(is, args, ':');

    switch (str2int(args.c_str())) {
    case str2int("type"): {
      auto t = CompoMe::get_word(is, {',', '}'});
      if (t.first !=
          "CompoMe::Log::Filter_Filter_Management_I_filter_Manager") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      C_ERROR("wrong attribute: \"", args,
              "\" not in provide Filter_Filter_Management_I_filter_Manager");
      throw "wrong attribute: \"" + args +
          "\" not in provide Filter_Filter_Management_I_filter_Manager";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace Log

} // namespace CompoMe
