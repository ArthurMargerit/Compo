
#include "Components/CompoMe/Config/DataProvider.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

namespace CompoMe {

namespace Config {

DataProvider::DataProvider() : /* PROVIDE */ access(this) {
  C_INFO_TAG("CONST: DataProvider", "Component,DataProvider");
  return;
}

//! Destructor
DataProvider::~DataProvider() noexcept {
  C_INFO_TAG("DEST: DataProvider", "Component,DataProvider");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void DataProvider::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: DataProvider", "Component,DataProvider");

  // configuration: sub_componentreturn;
}

void DataProvider::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: DataProvider", "Component,DataProvider");

  // connect: intern

  // connect: sub componentreturn;
}

void DataProvider::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: DataProvider", "Component,DataProvider");

  // start: sub componentreturn;
}

void DataProvider::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: DataProvider", "Component,DataProvider");

  // step: sub_componentreturn;
}

void DataProvider::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: DataProvider", "Component,DataProvider");
  return;
}

void DataProvider::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: DataProvider", "Component,DataProvider");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

} // namespace Config

} // namespace CompoMe
