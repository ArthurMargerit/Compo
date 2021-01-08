#include "CompoMe/Log.hpp"
#include "Components/CompoMe/Component_Core.hpp"
#include "Serialization_context.hpp"
#include <cstdlib>
#include <string>

namespace CompoMe {

std::ostream &operator<<(std::ostream &os, const Component_Core &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, Component_Core &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &Component_Core::to_stream_data(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << ",data:{";
  os << "name:";

  os << this->name;
  os << ",";
  os << "state:";

  os << this->state;
  os << "}";

  return os;
}

std::ostream &Component_Core::to_stream_sc(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << ",components:{";

  os << "}";
  return os;
}

std::ostream &Component_Core::to_stream_provide(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << ",provide:{";

  os << "handle:";
  this->handle.to_stream(os, p_ctx);

  os << "}";
  return os;
}

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
std::ostream &
Component_Core::to_stream(std::ostream &os,
                          CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "CompoMe::Component_Core";

  this->to_stream_data(os, p_ctx);
  this->to_stream_provide(os, p_ctx);
  os << '}';
  return os;
}

std::istream &Component_Core::from_stream_provide(
    std::istream &is, CompoMe::Serialization_context_import &p_ctx) {
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
    case str2int("handle"):
      this->get_handle().from_stream(is, p_ctx);
      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in data Component_Core");
      throw "wrong attribute: \"" + args + "\" not in provide Component_Core";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
Component_Core::from_stream_data(std::istream &is,
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
    case str2int("name"):
      is >> this->name;
      break;

    case str2int("state"):
      is >> this->state;
      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in data Component_Core");
      throw "wrong attribute: \"" + args + "\" not in data Component_Core";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
Component_Core::from_stream_sc(std::istream &is,
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

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in data Component_Core");
      throw "wrong attribute: \"" + args +
          "\" not in sub components Component_Core";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
Component_Core::from_stream(std::istream &is,
                            CompoMe::Serialization_context_import &p_ctx) {
  Component_Core l_reset;
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
      // TYPE ///////////////////////////////////////////////////////////////
    case str2int("type"): {

      auto t = CompoMe::get_word(is, {',', '}'});
      if (t.first != "Component_Core") {
        throw "Wrong Type: "; // + "Component_Core" + " != " + t.first ;
      }
      break;
    }

      // ADDR ///////////////////////////////////////////////////////////////
    case str2int("addr"): {
      void *addr;
      is >> addr;
      p_ctx.inscribe(addr, this);
      break;
    }

      // PARRENT ////////////////////////////////////////////////////////////

      // DATA ///////////////////////////////////////////////////////////////

    case str2int("data"): {
      this->from_stream_data(is, p_ctx);
      break;
    }

      // COMPONENT //////////////////////////////////////////////////////////

      // PROVIDE ////////////////////////////////////////////////////////////

    case str2int("provide"): {
      this->from_stream_provide(is, p_ctx);
      break;
    }

    default: {
      C_ERROR("wrong attribute: \"", args, "\" not in Component_Core");
      throw "wrong attribute: \"" + args + "\" not in Component_Core";
      break;
    }
    }

    l_c = is.get();
  } while (l_c == ',');

  if (l_c != '}') {
    C_ERROR("Wrong end: '", l_c, "' != '}'");
    throw "Wrong end";
  }

  //   default:
  //     std::cerr << "wrong attribute: \""<< args <<"\" not in Component_Core";
  //     throw "wrong attribute: \""+ args +"\" not in Component_Core";
  //     break;
  //   }

  //

  //   //
  //   // case str2int("name"):
  //   //
  //   //   is >> this->name;
  //   //
  //   //   break;
  //   //
  //   // case str2int("state"):
  //   //
  //   //   is >> this->state;
  //   //
  //   //   break;
  //   //

  //   l_c = is.get();
  // }while(l_c == ',');

  // if(l_c != '}') {
  //   std::cerr << "Wrong end: '"<< l_c <<"' != '}'" << std::endl;
  //   throw "Wrong end";
  // }

  return is;
}

} // namespace CompoMe
