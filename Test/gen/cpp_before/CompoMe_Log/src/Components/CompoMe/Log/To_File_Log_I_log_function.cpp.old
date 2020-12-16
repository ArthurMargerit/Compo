#include "Components/CompoMe/Log/To_File.hpp"
#include "Components/CompoMe/Log/To_File_Log_I_log.hpp"

namespace CompoMe {

namespace Log {

void To_File_Log_I_log::error(CompoMe::String mess, CompoMe::Log::Log_Info i) {

  this->get_c().get_output()
      << i.a_Emitted_on().a_sec() << ":" << i.a_Emitted_on().a_usec()
      << " ERROR " << mess << i.a_Tag().str << " " << i.a_File().str << ":"
      << i.a_Line() << std::endl;

  return;
}
void To_File_Log_I_log::warning(CompoMe::String mess,
                                CompoMe::Log::Log_Info i) {
  this->get_c().get_output()
      << i.a_Emitted_on().a_sec() << ":" << i.a_Emitted_on().a_usec()
      << " WARNING " << mess << i.a_Tag().str << " " << i.a_File().str << ":"
      << i.a_Line() << std::endl;

  return;
}
void To_File_Log_I_log::debug(CompoMe::String mess, CompoMe::Log::Log_Info i) {
  this->get_c().get_output()
      << i.a_Emitted_on().a_sec() << ":" << i.a_Emitted_on().a_usec()
      << " DEBUG " << mess << i.a_Tag().str << " " << i.a_File().str << ":"
      << i.a_Line() << std::endl;

  return;
}
void To_File_Log_I_log::info(CompoMe::String mess, CompoMe::Log::Log_Info i) {
  this->get_c().get_output()
      << i.a_Emitted_on().a_sec() << ":" << i.a_Emitted_on().a_usec()
      << " INFO " << mess << i.a_Tag().str << " " << i.a_File().str << ":"
      << i.a_Line() << std::endl;

  return;
}
void To_File_Log_I_log::log(CompoMe::Log::Kind_e k, CompoMe::String mess,
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
