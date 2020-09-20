#include "Interfaces/CompoMe/Log/Log_I/Log_I.hpp"
#include "Components/CompoMe/Log/To_Stream.hpp"

CompoMe::Log::To_Stream t;
CompoMe::Require_helper_t<CompoMe::Log::Log_I> _log_output = &t.log;
