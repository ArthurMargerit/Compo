

#include "Components/C/C1.hpp"
#include "Components/C/C1_I1_p1.hpp"
#include <cstdlib>
#include <string>

namespace C {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &
C1_I1_p1::to_stream(std::ostream &os,
                    CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "C::C1_I1_p1";

  os << ",v:" << this->get_v();

  os << "}";
  return os;
}

std::istream &
C1_I1_p1::from_stream(std::istream &is,
                      CompoMe::Serialization_context_import &p_ctx) {
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
      if (t.first != "C::C1_I1_p1") {
        throw "Wrong Type: ";
      }
      break;
    }

    case str2int("v"):
      is >> this->v;
      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in provide C1_I1_p1");
      throw "wrong attribute: \"" + args + "\" not in provide C1_I1_p1";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace C
