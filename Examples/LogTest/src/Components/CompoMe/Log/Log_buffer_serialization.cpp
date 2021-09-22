#include "CompoMe/Log.hpp"
#include "Components/CompoMe/Log/Log_buffer.hpp"
#include "Serialization_context.hpp"
#include <cstdlib>
#include <string>

namespace CompoMe {

namespace Log {

std::ostream &operator<<(std::ostream &os, const CompoMe::Log::Log_buffer &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, CompoMe::Log::Log_buffer &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &
Log_buffer::to_stream_data(std::ostream &os,
                           CompoMe::Serialization_context_export &p_ctx) const {
  os << ",data:{";
  os << "to_file:";

  os << this->to_file;
  os << ",";
  os << "file_path:";

  os << this->file_path;
  os << "}";

  return os;
}

std::ostream &
Log_buffer::to_stream_sc(std::ostream &os,
                         CompoMe::Serialization_context_export &p_ctx) const {
  os << ",components:{";

  os << "}";
  return os;
}

std::ostream &Log_buffer::to_stream_provide(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << ",provide:{";

  os << "log:";
  this->log.to_stream(os, p_ctx);

  os << "}";
  return os;
}

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
void Log_buffer::to_stream(std::ostream &os,
                           CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "CompoMe::Log::Log_buffer";

  this->to_stream_data(os, p_ctx);
  this->to_stream_provide(os, p_ctx);
  os << '}';
  //    return os;
}

std::istream &
Log_buffer::from_stream_provide(std::istream &is,
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
      C_ERROR("wrong attribute: \"", args, "\" not in data Log_buffer");
      throw "wrong attribute: \"" + args + "\" not in provide Log_buffer";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
Log_buffer::from_stream_data(std::istream &is,
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
    case str2int("to_file"):
      is >> this->to_file;
      break;

    case str2int("file_path"):
      is >> this->file_path;
      break;

    default:
      C_ERROR("wrong attribute: \"", args, "\" not in data Log_buffer");
      throw "wrong attribute: \"" + args + "\" not in data Log_buffer";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
Log_buffer::from_stream_sc(std::istream &is,
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
      C_ERROR("wrong attribute: \"", args, "\" not in data Log_buffer");
      throw "wrong attribute: \"" + args +
          "\" not in sub components Log_buffer";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

void Log_buffer::from_stream(std::istream &is,
                             CompoMe::Serialization_context_import &p_ctx) {
  Log_buffer l_reset;
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
      if (t.first != "Log_buffer") {
        C_ERROR("Wrong Type: " + "Log_buffer" + " != " + t.first);
        throw "Wrong Type"; // + "Log_buffer" + " != " + t.first ;
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
      C_ERROR("wrong attribute: \"", args, "\" not in Log_buffer");
      throw "wrong attribute: \"" + args + "\" not in Log_buffer";
      break;
    }
    }

    l_c = is.get();
  } while (l_c == ',');

  if (l_c != '}') {
    C_ERROR("Wrong end: '", l_c, "' != '}'");
    throw "Wrong end";
  }
}

} // namespace Log

} // namespace CompoMe
