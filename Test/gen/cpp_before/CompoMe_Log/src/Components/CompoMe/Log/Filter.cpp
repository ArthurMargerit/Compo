
#include <algorithm>
#include <iostream>

#include "Components/CompoMe/Log/Filter.hpp"

namespace CompoMe {

namespace Log {

Filter::Filter()
    : /* PROVIDE */ input_log(this), filter_Manager(this),
      /* REQUIRE */ pass_log(NULL), refused_log(NULL),
      /* DATA */ filter(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : Filter" << std::endl;
  return;
}

//! Destructor
Filter::~Filter() noexcept {
  std::cout << "--DEST  : Filter" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Filter::configuration() {
  Component::configuration();
  std::cout << "--CONF  : Filter" << std::endl;

  // configuration: sub_componentreturn;
}

void Filter::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: Filter" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void Filter::start() {
  // start: parent
  Component::start();
  std::cout << "--START : Filter" << std::endl;

  // start: sub componentreturn;
}

void Filter::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : Filter" << std::endl;

  // step: sub_componentreturn;
}

void Filter::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : Filter" << std::endl;
  return;
}

void Filter::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: Filter" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

Filter_Log_I_input_log &Filter::get_input_log() { return this->input_log; }

Filter_Filter_Management_I_filter_Manager &Filter::get_filter_Manager() {
  return this->filter_Manager;
}

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

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
