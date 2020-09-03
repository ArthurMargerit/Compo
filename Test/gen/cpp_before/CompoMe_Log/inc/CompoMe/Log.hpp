#pragma once

#ifdef COMPOME_LOG
#include "Components/CompoMe/Log/To_Stream.hpp"
#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"
#include "Structs/CompoMe/Log/Log_Info.hpp"
#include <time.h>

extern CompoMe::Require_helper_t<CompoMe::Log::Log_I> _log_output;

//extern CompoMe::Log::Log_I *_log_output;

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

#define C_DEBUG(MSG) C_TO_DEBUG_TAG(_log_output, MSG, "None")
#define C_TO_DEBUG(TO, MSG) C_TO_DEBUG_TAG(TO, MSG, "None")
#define C_DEBUG_TAG(MSG, TAG) C_TO_DEBUG_TAG(_log_output, MSG, TAG)
#define C_TO_DEBUG_TAG(TO, MSG, TAG)                                           \
  do {                                                                         \
    C_GET_INFO(TAG);                                                           \
    TO->debug(MSG, _log_info);                                                 \
  } while (false);

#define C_INFO(MSG) C_TO_INFO_TAG(_log_output, MSG, "None")
#define C_TO_INFO(TO, MSG) C_TO_INFO_TAG(TO, MSG, "None")
#define C_INFO_TAG(MSG, TAG) C_TO_INFO_TAG(_log_output, MSG, TAG)
#define C_TO_INFO_TAG(TO, MSG, TAG)                                            \
  do {                                                                         \
    C_GET_INFO(TAG);                                                           \
    _log_output->info(MSG, _log_info);                                         \
  } while (false);

#define C_WARNING(MSG) C_TO_WARNING_TAG(_log_output, MSG, "None")
#define C_TO_WARNING(TO, MSG) C_TO_WARNING_TAG(TO, MSG, "None")
#define C_WARNING_TAG(MSG, TAG) C_TO_WARNING_TAG(_log_output, MSG, TAG)
#define C_TO_WARNING_TAG(TO, MSG, TAG)                                   \
  do {                                                                         \
    C_GET_INFO(TAG);                                                           \
    _log_output->warning(MSG, _log_info);                                      \
  } while (false);

#define C_ERROR(MSG) C_TO_ERROR_TAG(_log_output, MSG, "None")
#define C_TO_ERROR(TO, MSG) C_TO_ERROR_TAG(TO, MSG, "None")
#define C_ERROR_TAG(MSG, TAG) C_TO_ERROR_TAG(_log_output, MSG, TAG)
#define C_TO_ERROR_TAG(TO, MSG, TAG)                                     \
  do {                                                                         \
    C_GET_INFO(TAG);                                                           \
    _log_output->error(MSG, _log_info);                                        \
  } while (false);

#else

#define C_ERROR(MSG)                                                           \
  do {                                                                         \
  } while (false);
#define C_TO_ERROR(TO, MSG)                                                    \
  do {                                                                         \
  } while (false);
#define C_ERROR_TAG(MSG, TAG)                                                  \
  do {                                                                         \
  } while (false);
#define C_WARNING(MSG)                                                         \
  do {                                                                         \
  } while (false);
#define C_TO_WARNING(TO, MSG)                                                  \
  do {                                                                         \
  } while (false);
#define C_WARNING_TAG(MSG, TAG)                                                \
  do {                                                                         \
  } while (false);
#define C_DEBUG(MSG)                                                           \
  do {                                                                         \
  } while (false);
#define C_TO_DEBUG(TO, MSG)                                                    \
  do {                                                                         \
  } while (false);
#define C_DEBUG_TAG(MSG, TAG)                                                  \
  do {                                                                         \
  } while (false);
#define C_INFO(MSG)                                                            \
  do {                                                                         \
  } while (false);
#define C_TO_INFO(TO, MSG)                                                     \
  do {                                                                         \
  } while (false);
#define C_INFO_TAG(MSG, TAG)                                                   \
  do {                                                                         \
  } while (false);

#define C_TO_DEBUG_TAG(TO, MSG, TAG)                                           \
  do {                                                                         \
  } while (false);
#define C_TO_WARNING_TAG(TO, MSG, TAG)                                         \
  do {                                                                         \
  } while (false);
#define C_TO_ERROR_TAG(TO, MSG, TAG)                                           \
  do {                                                                         \
  } while (false);
#define C_TO_INFO_TAG(TO, MSG, TAG)                                            \
  do {                                                                         \
  } while (false);
#endif // COMPOME_LOG
