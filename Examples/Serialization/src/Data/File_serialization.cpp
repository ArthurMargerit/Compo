#include "Data/File.hpp"
#include "Serialization_context.hpp"

// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::istream &File::from_stream(std::istream &is,
                                Serialization_context_import &p_ctx) {
  File l_reset;
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
      if (t.first != "File") {
        throw "Wrong Type: "; // + "File" + " != " + t.first ;
      }
      break;
    }

    case str2int("addr"): {
      void *addr;
      is >> addr;
      p_ctx.inscribe(addr, this);
      break;
    }

    case str2int("path"):

      is >> this->path;

      break;

    default:
      std::cerr << "wrong attribute: \"" << args << "\" not in File";
      throw "wrong attribute: \"" + args + "\" not in File";
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

std::ostream &File::to_stream(std::ostream &os,
                              Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "File";
  os << ",path:";

  os << this->path;

  os << "}";
  return os;
}

std::ostream &operator<<(std::ostream &os, const File &c) {
  Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, File &c) {
  Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}
