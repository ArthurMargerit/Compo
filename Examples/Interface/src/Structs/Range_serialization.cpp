#include "Structs/Range.hpp"

#include "Serialization_context.hpp"

// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::istream &Range::from_stream(std::istream &is,
                                 CompoMe::Serialization_context_import &p_ctx) {
  Range l_reset;
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
      if (t.first != "Range") {
        throw "Wrong Type: "; // + "Range" + " != " + t.first ;
      }
      break;
    }

    case str2int("addr"): {
      void *addr;
      is >> addr;
      p_ctx.inscribe(addr, this);
      break;
    }

    case str2int("min"):

      is >> this->min;

      break;

    case str2int("max"):

      is >> this->max;

      break;

    default:
      std::cerr << "wrong attribute: \"" << args << "\" not in Range";
      throw "wrong attribute: \"" + args + "\" not in Range";
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
Range::to_stream(std::ostream &os,
                 CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "Range";
  os << ",min:";

  os << this->min;
  os << ",max:";

  os << this->max;

  os << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, const Range &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, Range &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}
