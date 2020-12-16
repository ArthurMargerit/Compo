
#include "Components/CompoMe/Log/Filter.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

namespace CompoMe {

namespace Log {

Filter::Filter()
    : /* PROVIDE */ input_log(this), filter_Manager(this),
      /* REQUIRE */ pass_log(NULL), refused_log(NULL),
      /* DATA */ filter(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  C_INFO_TAG("CONST: Filter", "Component,Filter");
  return;
}

//! Destructor
Filter::~Filter() noexcept {
  C_INFO_TAG("DEST: Filter", "Component,Filter");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Filter::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: Filter", "Component,Filter");

  // configuration: sub_componentreturn;
}

void Filter::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: Filter", "Component,Filter");

  // connect: intern

  // connect: sub componentreturn;
}

void Filter::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: Filter", "Component,Filter");

  // start: sub componentreturn;
}

void Filter::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: Filter", "Component,Filter");

  // step: sub_componentreturn;
}

void Filter::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: Filter", "Component,Filter");
  return;
}

void Filter::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: Filter", "Component,Filter");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

} // namespace Log

} // namespace CompoMe
