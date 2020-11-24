#include "Components/CompoMe/Log/Filter.hpp"

namespace CompoMe {

namespace Log {

/////////////////////////////////////////////////////////////////////////////
//                                   PROVIDE                               //
/////////////////////////////////////////////////////////////////////////////

Filter_Log_I_input_log &Filter::get_input_log() { return this->input_log; }

Filter_Filter_Management_I_filter_Manager &Filter::get_filter_Manager() {
  return this->filter_Manager;
}

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// filter
CompoMe::Log::Kind_e Filter::get_filter() const { return this->filter; }

void Filter::set_filter(const CompoMe::Log::Kind_e &filter) {
  this->filter = filter;
}

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace Log

} // namespace CompoMe
