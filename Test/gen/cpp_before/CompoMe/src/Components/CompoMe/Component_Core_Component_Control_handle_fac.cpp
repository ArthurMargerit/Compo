

#include "Components/CompoMe/Component_Core.hpp"
#include "Components/CompoMe/Component_Core_Component_Control_handle.hpp"
#include <cstdlib>
#include <string>

namespace CompoMe {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &Component_Core_Component_Control_handle::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "CompoMe::Component_Core_Component_Control_handle";

  os << "}";
  return os;
}

std::istream &Component_Core_Component_Control_handle::from_stream(
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
      if (t.first != "CompoMe::Component_Core_Component_Control_handle") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      C_ERROR("wrong attribute: \"", args,
              "\" not in provide Component_Core_Component_Control_handle");
      throw "wrong attribute: \"" + args +
          "\" not in provide Component_Core_Component_Control_handle";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace CompoMe
