
#include "Components/CompoMe/Log/To_File.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

namespace CompoMe {

namespace Log {

To_File::To_File()
    : /* PROVIDE */ log(this), /* DATA */ path(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  C_INFO_TAG("CONST: To_File", "Component,To_File");
  return;
}

//! Destructor
To_File::~To_File() noexcept {
  C_INFO_TAG("DEST: To_File", "Component,To_File");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void To_File::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: To_File", "Component,To_File");

  // configuration: sub_componentreturn;
}

void To_File::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: To_File", "Component,To_File");

  // connect: intern

  // connect: sub componentreturn;
}

void To_File::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: To_File", "Component,To_File");
  this->output.open(this->get_path());

  // start: sub componentreturn;
}

void To_File::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: To_File", "Component,To_File");

  // step: sub_componentreturn;
}

void To_File::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: To_File", "Component,To_File");
  this->output.close();
  return;
}

void To_File::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: To_File", "Component,To_File");
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
