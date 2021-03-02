#include "Structs/User.hpp"

#include "CompoMe/Log.hpp"
#include <cstdlib>
#include <string>

// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

void User::from_stream(std::istream &is,
                       CompoMe::Serialization_context_import &p_ctx) {
  User l_reset;
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
      if (t.first != "User") {
        throw "Wrong Type: "; // + "User" + " != " + t.first ;
      }
      break;
    }

    case str2int("addr"): {
      void *addr;
      is >> addr;
      p_ctx.inscribe(addr, this);
      break;
    }

    case str2int("id"):

      is >> this->id;

      break;

    case str2int("first_name"):

      is >> this->first_name;

      break;

    case str2int("last_name"):

      is >> this->last_name;

      break;

    case str2int("score"):

      is >> this->score;

      break;

    case str2int("profile_img"):

      this->profile_img.from_stream(is, p_ctx);

      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in User");
      throw "wrong attribute: \"" + args + "\" not in User";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  if (l_c != '}') {
    C_ERROR("Wrong end: '", l_c, "' != '}'");
    throw "Wrong end";
  }
}

void User::to_stream(std::ostream &os,
                     CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "User";
  os << ",id:";

  os << this->id;
  os << ",first_name:";

  os << this->first_name;
  os << ",last_name:";

  os << this->last_name;
  os << ",score:";

  os << this->score;
  os << ",profile_img:";

  this->profile_img.to_stream(os, p_ctx);

  os << "}";
}

std::ostream &operator<<(std::ostream &os, const User &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, User &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}
