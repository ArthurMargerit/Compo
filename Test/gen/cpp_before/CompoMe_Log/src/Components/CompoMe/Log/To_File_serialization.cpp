#include "Components/CompoMe/Log/To_File.hpp"
#include "Serialization_context.hpp"

#include <cstdlib>
#include <string>

#include "CompoMe/Log.hpp"

namespace CompoMe {

namespace Log {

std::ostream &operator<<(std::ostream &os, const To_File &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, To_File &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &
To_File::to_stream_data(std::ostream &os,
                        CompoMe::Serialization_context_export &p_ctx) const {
  os << ",data:{";
  os << "path:";

  os << this->path;
  os << "}";

  return os;
}

std::ostream &
To_File::to_stream_sc(std::ostream &os,
                      CompoMe::Serialization_context_export &p_ctx) const {
  os << ",components:{";

  os << "}";
  return os;
}

std::ostream &
To_File::to_stream_provide(std::ostream &os,
                           CompoMe::Serialization_context_export &p_ctx) const {
  os << ",provide:{";

  os << "log:";
  this->log.to_stream(os, p_ctx);

  os << "}";
  return os;
}

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
std::ostream &
To_File::to_stream(std::ostream &os,
                   CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "CompoMe::Log::To_File";

  this->to_stream_data(os, p_ctx);
  this->to_stream_provide(os, p_ctx);
  os << '}';
  return os;
}

std::istream &
To_File::from_stream_provide(std::istream &is,
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
    case str2int("log"):
      this->get_log().from_stream(is, p_ctx);
      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in data To_File");
      throw "wrong attribute: \"" + args + "\" not in provide To_File";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
To_File::from_stream_data(std::istream &is,
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
    case str2int("path"):
      is >> this->path;
      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in data To_File");
      throw "wrong attribute: \"" + args + "\" not in data To_File";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
To_File::from_stream_sc(std::istream &is,
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
      C_ERROR("wrong attribute: \"", args, "\" not in data To_File");
      throw "wrong attribute: \"" + args + "\" not in sub components To_File";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
To_File::from_stream(std::istream &is,
                     CompoMe::Serialization_context_import &p_ctx) {
  To_File l_reset;
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
      if (t.first != "To_File") {
        throw "Wrong Type: "; // + "To_File" + " != " + t.first ;
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
      C_ERROR("wrong attribute: \"", args, "\" not in To_File");
      throw "wrong attribute: \"" + args + "\" not in To_File";
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
  //     std::cerr << "wrong attribute: \""<< args <<"\" not in To_File";
  //     throw "wrong attribute: \""+ args +"\" not in To_File";
  //     break;
  //   }

  //

  //   //
  //   // case str2int("path"):
  //   //
  //   //   is >> this->path;
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

} // namespace Log

} // namespace CompoMe
