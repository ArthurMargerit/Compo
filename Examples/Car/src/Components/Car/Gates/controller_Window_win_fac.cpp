

#include "Components/Car/Gates/controller.hpp"
#include "Components/Car/Gates/controller_Window_win.hpp"

namespace Car {

namespace Gates {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &controller_Window_win::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "Car::Gates::controller_Window_win";

  os << ",percent:" << this->get_percent();

  os << "}";
  return os;
}

std::istream &controller_Window_win::from_stream(
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
      if (t.first != "Car::Gates::controller_Window_win") {
        throw "Wrong Type: ";
      }
      break;
    }

    case str2int("percent"):
      is >> this->percent;
      break;

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide controller_Window_win";
      throw "wrong attribute: \"" + args +
          "\" not in provide controller_Window_win";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace Gates

} // namespace Car
