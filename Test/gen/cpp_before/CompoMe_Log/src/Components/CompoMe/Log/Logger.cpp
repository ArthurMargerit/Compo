
#include <algorithm>
#include <iostream>

#include "Components/CompoMe/Log/Logger.hpp"

namespace CompoMe {

namespace Log {

Logger::Logger()
    : /* REQUIRE */ log_out(NULL), /* DATA */ ignore(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : Logger" << std::endl;
  return;
}

//! Destructor
Logger::~Logger() noexcept {
  std::cout << "--DEST  : Logger" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Logger::configuration() {
  Component::configuration();
  std::cout << "--CONF  : Logger" << std::endl;

  // configuration: sub_componentreturn;
}

void Logger::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: Logger" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void Logger::start() {
  // start: parent
  Component::start();
  std::cout << "--START : Logger" << std::endl;

  // start: sub componentreturn;
}

void Logger::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : Logger" << std::endl;

  // step: sub_componentreturn;
}

void Logger::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : Logger" << std::endl;
  return;
}

void Logger::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: Logger" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// ignore
CompoMe::Log::Kind_e Logger::get_ignore() const { return this->ignore; }

void Logger::set_ignore(const CompoMe::Log::Kind_e &ignore) {
  this->ignore = ignore;
}

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace Log

} // namespace CompoMe
