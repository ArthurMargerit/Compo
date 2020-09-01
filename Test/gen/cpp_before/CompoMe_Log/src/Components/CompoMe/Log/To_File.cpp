
#include <algorithm>
#include <iostream>

#include "Components/CompoMe/Log/To_File.hpp"

namespace CompoMe {

namespace Log {

To_File::To_File()
    : /* PROVIDE */ log(this), /* DATA */ path(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : To_File" << std::endl;
  return;
}

//! Destructor
To_File::~To_File() noexcept {
  std::cout << "--DEST  : To_File" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void To_File::configuration() {
  Component::configuration();
  std::cout << "--CONF  : To_File" << std::endl;

  // configuration: sub_componentreturn;
}

void To_File::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: To_File" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void To_File::start() {
  // start: parent
  Component::start();
  std::cout << "--START : To_File" << std::endl;

  // start: sub componentreturn;
}

void To_File::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : To_File" << std::endl;

  // step: sub_componentreturn;
}

void To_File::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : To_File" << std::endl;
  return;
}

void To_File::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: To_File" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

To_File_Log_I_log &To_File::get_log() { return this->log; }

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// path
CompoMe::String To_File::get_path() const { return this->path; }

void To_File::set_path(const CompoMe::String &path) { this->path = path; }

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace Log

} // namespace CompoMe
