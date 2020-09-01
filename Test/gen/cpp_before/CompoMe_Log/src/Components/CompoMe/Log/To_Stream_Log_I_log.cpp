

#include "Components/CompoMe/Log/To_Stream_Log_I_log.hpp"
#include "Components/CompoMe/Log/To_Stream.hpp"

namespace CompoMe {

namespace Log {

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BROWN "\033[0;33m"
#define CYAN "\033[0;36m"
#define NC "\033[0m"

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

To_Stream_Log_I_log::To_Stream_Log_I_log(To_Stream *comp) : composant(comp) {
  return;
}

//! Destructor
To_Stream_Log_I_log::~To_Stream_Log_I_log() noexcept { return; }

To_Stream &To_Stream_Log_I_log::get_c() const { return *this->composant; }

void To_Stream_Log_I_log::error(CompoMe::String mess,
                                CompoMe::Log::Log_Info i) {
  std::cout << i.a_Emitted_on().a_sec() << ":" << i.a_Emitted_on().a_usec()
            << " " << RED ">Error | " NC << i.a_Tag().str << " | " << mess.str
            << " | " << i.a_File().str << ":" << i.a_Line() << std::endl;
  return;
}
void To_Stream_Log_I_log::warning(CompoMe::String mess,
                                  CompoMe::Log::Log_Info i) {
  std::cout << i.a_Emitted_on().a_sec() << ":" << i.a_Emitted_on().a_usec()
            << " " << BROWN ">Warn  | " NC << i.a_Tag().str << " | "
            << mess.str << " | " << i.a_File().str << ":" << i.a_Line()
            << std::endl;
  return;
}
void To_Stream_Log_I_log::debug(CompoMe::String mess,
                                CompoMe::Log::Log_Info i) {
  std::cout << i.a_Emitted_on().a_sec() << ":" << i.a_Emitted_on().a_usec()
            << " " << CYAN ">Debug | " NC << i.a_Tag().str << " | " << mess.str
            << " | " << i.a_File().str << ":" << i.a_Line() << std::endl;
  return;
}
void To_Stream_Log_I_log::info(CompoMe::String mess, CompoMe::Log::Log_Info i) {
  std::cout << i.a_Emitted_on().a_sec() << ":" << i.a_Emitted_on().a_usec()
            << " " << GREEN ">Info  | " NC << i.a_Tag().str << " | " << mess.str
            << " | " << i.a_File().str << ":" << i.a_Line() << std::endl;
  return;
}
void To_Stream_Log_I_log::log(CompoMe::Log::Kind_e k, CompoMe::String mess,
                              CompoMe::Log::Log_Info i) {

  switch (k) {
  case CompoMe::Log::Kind_e::KIND_E_ERROR: {
    this->error(mess, i);
    break;
  }
  case CompoMe::Log::Kind_e::KIND_E_WARNING: {
    this->warning(mess, i);
    break;
  }
  case CompoMe::Log::Kind_e::KIND_E_DEBUG: {
    this->debug(mess, i);
    break;
  }
  case CompoMe::Log::Kind_e::KIND_E_INFO: {
    this->info(mess, i);
    break;
  }
  }

  return;
}

// Log_I ///////////////////////////////////////////////////////////////////

std::ostream &To_Stream_Log_I_log::to_stream(
    std::ostream &os, CompoMe::Serialization_context_export &p_ctx) const {
  os << "{";
  os << "type:"
     << "CompoMe::Log::To_Stream_Log_I_log";

  os << "}";
  return os;
}

std::istream &
To_Stream_Log_I_log::from_stream(std::istream &is,
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
    case str2int("type"): {
      auto t = CompoMe::get_word(is, {',', '}'});
      if (t.first != "CompoMe::Log::To_Stream_Log_I_log") {
        throw "Wrong Type: ";
      }
      break;
    }

    default:
      std::cerr << "wrong attribute: \"" << args
                << "\" not in provide To_Stream_Log_I_log";
      throw "wrong attribute: \"" + args +
          "\" not in provide To_Stream_Log_I_log";
      break;
    }

    l_c = is.get();
  } while (l_c == ',');

  return is;
}

} // namespace Log

} // namespace CompoMe
