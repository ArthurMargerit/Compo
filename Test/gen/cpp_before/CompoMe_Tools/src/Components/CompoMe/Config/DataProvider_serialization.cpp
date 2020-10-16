#include "Components/CompoMe/Config/DataProvider.hpp"
#include "Serialization_context.hpp"
#include <iostream>

namespace CompoMe {

namespace Config {

std::ostream &operator<<(std::ostream &os, const DataProvider &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, DataProvider &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &DataProvider::to_stream_data(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << ",data:{";
  os << "}";

  return os;
}

std::ostream &
DataProvider::to_stream_sc(std::ostream &os,
                           CompoMe::Serialization_context_export &p_ctx) const {
  os << ",components:{";

  os << "}";
  return os;
}

std::ostream &DataProvider::to_stream_provide(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << ",provide:{";

  os << "access:";
  this->access.to_stream(os, p_ctx);

  os << "}";
  return os;
}

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
std::ostream &
DataProvider::to_stream(std::ostream &os,
                        CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "CompoMe::Config::DataProvider";

  this->to_stream_provide(os, p_ctx);
  os << '}';
  return os;
}

std::istream &DataProvider::from_stream_provide(
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
    case str2int("access"):
      this->get_access().from_stream(is, p_ctx);
      break;

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in data DataProvider";
      throw "wrong attribute: \"" + args + "\" not in provide DataProvider";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
DataProvider::from_stream_data(std::istream &is,
                               CompoMe::Serialization_context_import &p_ctx) {
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

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in data DataProvider";
      throw "wrong attribute: \"" + args + "\" not in data DataProvider";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
DataProvider::from_stream_sc(std::istream &is,
                             CompoMe::Serialization_context_import &p_ctx) {
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

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in data DataProvider";
      throw "wrong attribute: \"" + args +
          "\" not in sub components DataProvider";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
DataProvider::from_stream(std::istream &is,
                          CompoMe::Serialization_context_import &p_ctx) {
  DataProvider l_reset;
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
      // TYPE ///////////////////////////////////////////////////////////////
    case str2int("type"): {

      auto t = CompoMe::get_word(is, {',', '}'});
      if (t.first != "DataProvider") {
        throw "Wrong Type: "; // + "DataProvider" + " != " + t.first ;
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

      // COMPONENT //////////////////////////////////////////////////////////

      // PROVIDE ////////////////////////////////////////////////////////////

    case str2int("provide"): {
      this->from_stream_provide(is, p_ctx);
      break;
    }

    default: {
      std::cerr << "wrong attribute: \"" << args << "\" not in DataProvider";
      throw "wrong attribute: \"" + args + "\" not in DataProvider";
      break;
    }
    }

    l_c = is.get();
  } while (l_c == ',');

  if (l_c != '}') {
    std::cerr << "Wrong end: '" << l_c << "' != '}'" << std::endl;
    throw "Wrong end";
  }

  //   default:
  //     std::cerr << "wrong attribute: \""<< args <<"\" not in DataProvider";
  //     throw "wrong attribute: \""+ args +"\" not in DataProvider";
  //     break;
  //   }

  //

  //   //

  //   l_c = is.get();
  // }while(l_c == ',');

  // if(l_c != '}') {
  //   std::cerr << "Wrong end: '"<< l_c <<"' != '}'" << std::endl;
  //   throw "Wrong end";
  // }

  return is;
}

} // namespace Config

} // namespace CompoMe
