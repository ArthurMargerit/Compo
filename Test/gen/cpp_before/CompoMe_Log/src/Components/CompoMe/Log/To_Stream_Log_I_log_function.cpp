#include "Components/CompoMe/Log/To_Stream.hpp"
#include "Components/CompoMe/Log/To_Stream_Log_I_log.hpp"

namespace CompoMe {

namespace Log {

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BROWN "\033[0;33m"
#define CYAN "\033[0;36m"
#define NC "\033[0m"

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

} // namespace Log

} // namespace CompoMe
