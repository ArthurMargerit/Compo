#include "Components/CompoMe/Log/Log_buffer.hpp"

namespace CompoMe {

namespace Log {

/////////////////////////////////////////////////////////////////////////////
//                                   PROVIDE                               //
/////////////////////////////////////////////////////////////////////////////

Log_buffer_Log_I_log &Log_buffer::get_log() { return this->log; }

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// to_file
bool Log_buffer::get_to_file() const { return this->to_file; }

void Log_buffer::set_to_file(const bool &to_file) { this->to_file = to_file; }

// file_path
CompoMe::String Log_buffer::get_file_path() const { return this->file_path; }

void Log_buffer::set_file_path(const CompoMe::String &file_path) {
  this->file_path = file_path;
}

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace Log

} // namespace CompoMe
