#include "Structs/S/S2.hpp"

#include "CompoMe/Log.hpp"
#include <cstdlib>
#include <string>

namespace S {

// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::istream &S2::from_stream(std::istream &is,
                              CompoMe::Serialization_context_import &p_ctx) {
  S2 l_reset;
  *this = l_reset;

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

    case str2int("s"):

      this->s.from_stream(is, p_ctx);

      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in S2");
      throw "wrong attribute: \"" + args + "\" not in S2";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  if (l_c != '}') {
    C_ERROR("Wrong end: '", l_c, "' != '}'");
    throw "Wrong end";
  }

  return is;
}

std::ostream &
S2::to_stream(std::ostream &os,
              CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "S2";
  os << ",s:";

  this->s.to_stream(os, p_ctx);

  os << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, const S2 &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, S2 &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

} // namespace S
