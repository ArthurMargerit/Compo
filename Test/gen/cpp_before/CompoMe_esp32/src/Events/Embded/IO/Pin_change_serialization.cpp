#include "Events/Embded/IO/Pin_change.hpp"
#include "Serialization_context.hpp"
#include <iostream>

namespace Embded {

namespace IO {

// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::istream &
Pin_change::from_stream(std::istream &is,
                        CompoMe::Serialization_context_import &p_ctx) {
  Pin_change l_reset;
  *this = l_reset;

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
      if (t.first != "Pin_change") {
        throw "Wrong Type: "; // + "Pin_change" + " != " + t.first ;
      }
      break;
    }

    case str2int("addr"): {
      void *addr;
      is >> addr;
      p_ctx.inscribe(addr, this);
      break;
    }

    case str2int("pin_id"):

      is >> this->pin_id;

      break;

    case str2int("pin_value"):

      is >> this->pin_value;

      break;

    default:
      std::cerr << "wrong attribute: \"" << args << "\" not in Pin_change";
      throw "wrong attribute: \"" + args + "\" not in Pin_change";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  if (l_c != '}') {
    std::cerr << "Wrong end: '" << l_c << "' != '}'" << std::endl;
    throw "Wrong end";
  }

  return is;
}

std::ostream &
Pin_change::to_stream(std::ostream &os,
                      CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "Pin_change";
  os << ",pin_id:";

  os << this->pin_id;
  os << ",pin_value:";

  os << this->pin_value;

  os << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, const Pin_change &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, Pin_change &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

} // namespace IO

} // namespace Embded
