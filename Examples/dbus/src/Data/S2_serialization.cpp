#include "Data/S2.hpp"
#include "Serialization_context.hpp"

// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::istream &S2::from_stream(std::istream &is,
                              Serialization_context_import &p_ctx) {
  S2 l_reset;
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
      auto t = get_word(is, {',', '}'});
      if (t.first != "S2") {
        throw "Wrong Type: "; // + "S2" + " != " + t.first ;
      }
      break;
    }

    case str2int("addr"): {
      void *addr;
      is >> addr;
      p_ctx.inscribe(addr, this);
      break;
    }

    case str2int("i1"):

      is >> this->i1;

      break;

    case str2int("i2"):

      is >> this->i2;

      break;

    default:
      std::cerr << "wrong attribute: \"" << args << "\" not in S2";
      throw "wrong attribute: \"" + args + "\" not in S2";
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

std::ostream &S2::to_stream(std::ostream &os,
                            Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "S2";
  os << ",i1:";

  os << this->i1;
  os << ",i2:";

  os << this->i2;

  os << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, const S2 &c) {
  Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, S2 &c) {
  Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}
