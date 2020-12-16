

#include "Components/Embded/IO/esp32/Control_output.hpp"
#include "Components/Embded/IO/esp32/Control_output_Pin_out_control.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &Control_output_Pin_out_control::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "Embded::IO::esp32::Control_output_Pin_out_control";

  os << ",state:" << this->get_state();

  os << "}";
  return os;
}

std::istream &Control_output_Pin_out_control::from_stream(
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
      if (t.first != "Embded::IO::esp32::Control_output_Pin_out_control") {
        throw "Wrong Type: ";
      }
      break;
    }

    case str2int("state"):
      is >> this->state;
      break;

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide Control_output_Pin_out_control";
      throw "wrong attribute: \"" + args +
          "\" not in provide Control_output_Pin_out_control";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace esp32

} // namespace IO

} // namespace Embded
