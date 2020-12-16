#include "Components/Sensor.hpp"
#include "Serialization_context.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Sensor &c) {
  CompoMe::Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream &operator>>(std::istream &is, Sensor &c) {
  CompoMe::Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

std::ostream &
Sensor::to_stream_data(std::ostream &os,
                       CompoMe::Serialization_context_export &p_ctx) const {
  os << ",data:{";
  os << "name:";

  os << this->name;
  os << ",";
  os << "type:";

  os << this->type;
  os << ",";
  os << "location:";

  os << this->location;
  os << "}";

  return os;
}

std::ostream &
Sensor::to_stream_sc(std::ostream &os,
                     CompoMe::Serialization_context_export &p_ctx) const {
  os << ",components:{";

  os << "}";
  return os;
}

std::ostream &
Sensor::to_stream_provide(std::ostream &os,
                          CompoMe::Serialization_context_export &p_ctx) const {
  os << ",provide:{";

  os << "information:";
  this->information.to_stream(os, p_ctx);
  os << ",";
  os << "capteur1:";
  this->capteur1.to_stream(os, p_ctx);

  os << "}";
  return os;
}

/////////////////////////////////////////////////////////////////////////////
//                            LOAD/SAVE                                    //
/////////////////////////////////////////////////////////////////////////////
std::ostream &
Sensor::to_stream(std::ostream &os,
                  CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "addr:" << (void *)this;
  p_ctx.declare(this);

  os << ",type:"
     << "Sensor";

  this->to_stream_data(os, p_ctx);
  this->to_stream_provide(os, p_ctx);
  os << '}';
  return os;
}

std::istream &
Sensor::from_stream_provide(std::istream &is,
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
    case str2int("information"):
      this->get_information().from_stream(is, p_ctx);
      break;

    case str2int("capteur1"):
      this->get_capteur1().from_stream(is, p_ctx);
      break;

    default:
      std::cerr << "wrong attribute: \"" << args << "\" not in data Sensor";
      throw "wrong attribute: \"" + args + "\" not in provide Sensor";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
Sensor::from_stream_data(std::istream &is,
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
    case str2int("name"):
      is >> this->name;
      break;

    case str2int("type"):
      is >> this->type;
      break;

    case str2int("location"):
      is >> this->location;
      break;

    default:
      std::cerr << "wrong attribute: \"" << args << "\" not in data Sensor";
      throw "wrong attribute: \"" + args + "\" not in data Sensor";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
Sensor::from_stream_sc(std::istream &is,
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
      std::cerr << "wrong attribute: \"" << args << "\" not in data Sensor";
      throw "wrong attribute: \"" + args + "\" not in sub components Sensor";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

std::istream &
Sensor::from_stream(std::istream &is,
                    CompoMe::Serialization_context_import &p_ctx) {
  Sensor l_reset;
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
      if (t.first != "Sensor") {
        throw "Wrong Type: "; // + "Sensor" + " != " + t.first ;
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
      std::cerr << "wrong attribute: \"" << args << "\" not in Sensor";
      throw "wrong attribute: \"" + args + "\" not in Sensor";
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
  //     std::cerr << "wrong attribute: \""<< args <<"\" not in Sensor";
  //     throw "wrong attribute: \""+ args +"\" not in Sensor";
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
  //   // case str2int("type"):
  //   //
  //   //   is >> this->type;
  //   //
  //   //   break;
  //   //
  //   // case str2int("location"):
  //   //
  //   //   is >> this->location;
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
