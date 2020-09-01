#pragma once

#ifdef COMPOME_LOG
#include "Components/CompoMe/Log/To_Stream.hpp"
#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"
#include "Structs/CompoMe/Log/Log_Info.hpp"
#include <time.h>

static CompoMe::Log::To_Stream t;
static CompoMe::Log::Log_I *_log_output = &t.log;

#define C_GET_INFO(TAG)                                                        \
  CompoMe::Log::Log_Info _log_info;                                            \
  _log_info.set_File(__FILE__);                                                \
  _log_info.set_Function(__FUNCTION__);                                        \
  _log_info.set_Line(__LINE__);                                                \
  _log_info.set_Tag(TAG);                                                      \
  struct timespec _spec;                                                       \
  clock_gettime(CLOCK_REALTIME, &_spec);                                       \
  CompoMe::Log::time _time_l(_spec.tv_sec, _spec.tv_nsec / 1.0e3);             \
  _log_info.set_Emitted_on(_time_l);

#define C_DEBUG(MSG) C_DEBUG_TAG(MSG, "")
#define C_DEBUG_TAG(MSG, TAG)                                                  \
  do {                                                                         \
    C_GET_INFO(TAG);                                                           \
    _log_output->debug(MSG, _log_info);                                        \
  } while (false);

#define C_INFO(MSG) C_INFO_TAG(MSG, "")
#define C_INFO_TAG(MSG, TAG)                                                   \
  do {                                                                         \
    C_GET_INFO(TAG);                                                           \
    _log_output->info(MSG, _log_info);                                         \
  } while (false);

#define C_WARNING(MSG) C_WARNING_TAG(MSG, "")
#define C_WARNING_TAG(MSG, TAG)                                                \
  do {                                                                         \
    C_GET_INFO(TAG);                                                           \
    _log_output->warning(MSG, _log_info);                                      \
  } while (false);

#define C_ERROR(MSG) C_ERROR_TAG(MSG, "")
#define C_ERROR_TAG(MSG, TAG)                                                  \
  do {                                                                         \
    C_GET_INFO(TAG);                                                           \
    _log_output->error(MSG, _log_info);                                        \
  } while (false);

#else

#define C_DEBUG(MSG)                                                           \
  do {                                                                         \
  } while (false);
#define C_WARNING(MSG)                                                         \
  do {                                                                         \
  } while (false);
#define C_ERROR(MSG)                                                           \
  do {                                                                         \
  } while (false);
#define C_INFO(MSG)                                                            \
  do {                                                                         \
  } while (false);
#endif // COMPOME_LOG
