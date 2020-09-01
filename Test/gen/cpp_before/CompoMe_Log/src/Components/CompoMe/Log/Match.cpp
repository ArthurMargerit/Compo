
#include <algorithm>
#include <iostream>

#include "Components/CompoMe/Log/Match.hpp"

namespace CompoMe {

namespace Log {

Match::Match()
    : /* PROVIDE */ input_log(this), /* REQUIRE */ match_log(NULL),
      unmatch_log(NULL), /* DATA */ regex(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  std::cout << "--CONST : Match" << std::endl;
  return;
}

//! Destructor
Match::~Match() noexcept {
  std::cout << "--DEST  : Match" << std::endl;
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Match::configuration() {
  Component::configuration();
  std::cout << "--CONF  : Match" << std::endl;

  // configuration: sub_componentreturn;
}

void Match::connection() {
  // connect: parent
  Component::connection();
  std::cout << "--CONECT: Match" << std::endl;

  // connect: intern

  // connect: sub componentreturn;
}

void Match::start() {
  // start: parent
  Component::start();
  std::cout << "--START : Match" << std::endl;

  // start: sub componentreturn;
}

void Match::step() {
  // step: parent
  Component::step();
  std::cout << "--STEP  : Match" << std::endl;

  // step: sub_componentreturn;
}

void Match::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  std::cout << "--STOP  : Match" << std::endl;
  return;
}

void Match::status() {
  // status: parent
  Component::status();
  // status: sub_component
  std::cout << "--STATUS: Match" << std::endl;
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
