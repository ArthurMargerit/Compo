
#include "Components/CompoMe/Log/Match.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

namespace CompoMe {

namespace Log {

Match::Match()
    : /* PROVIDE */ input_log(this), /* REQUIRE */ match_log(NULL),
      unmatch_log(NULL), /* DATA */ regex(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  C_INFO_TAG("CONST: Match", "Component,Match");
  return;
}

//! Destructor
Match::~Match() noexcept {
  C_INFO_TAG("DEST: Match", "Component,Match");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Match::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: Match", "Component,Match");

  // configuration: sub_componentreturn;
}

void Match::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: Match", "Component,Match");

  // connect: intern

  // connect: sub componentreturn;
}

void Match::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: Match", "Component,Match");

  // start: sub componentreturn;
}

void Match::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: Match", "Component,Match");

  // step: sub_componentreturn;
}

void Match::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: Match", "Component,Match");
  return;
}

void Match::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: Match", "Component,Match");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                 FUNCTIONS                               //
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// PROVIDE //////////////////////////////////////////////////////////////////

Match_Log_I_input_log &Match::get_input_log() { return this->input_log; }

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

/////////////////////////////////////////////////////////////////////////////
//                                   DATA                                  //
/////////////////////////////////////////////////////////////////////////////

// regex
CompoMe::String Match::get_regex() const { return this->regex; }

void Match::set_regex(const CompoMe::String &regex) { this->regex = regex; }

/////////////////////////////////////////////////////////////////////////////
//                            SUB COMPONENT                                //
/////////////////////////////////////////////////////////////////////////////

} // namespace Log

} // namespace CompoMe
