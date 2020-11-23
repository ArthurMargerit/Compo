

#include "Components/C2.hpp"
#include "Components/C2_Math_async_return_back_call.hpp"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &C2_Math_async_return_back_call::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "C2_Math_async_return_back_call";

  os << "}";
  return os;
}

std::istream &C2_Math_async_return_back_call::from_stream(
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
      if (t.first != "C2_Math_async_return_back_call") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide C2_Math_async_return_back_call";
      throw "wrong attribute: \"" + args +
          "\" not in provide C2_Math_async_return_back_call";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}
