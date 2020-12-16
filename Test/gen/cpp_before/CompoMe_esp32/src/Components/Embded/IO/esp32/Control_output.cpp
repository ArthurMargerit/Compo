
#include "Components/Embded/IO/esp32/Control_output.hpp"
#include "CompoMe/Log.hpp"
#include <algorithm>

#include "driver/gpio.h"
#include "sdkconfig.h"

namespace Embded {

namespace IO {

namespace esp32 {
namespace  {
  gpio_num_t pin_id2gpio_num_t(ui8 pin) {
    if(pin >= GPIO_NUM_MAX ) {
      C_ERROR("PIN in not Correct: ", pin);
      return GPIO_NUM_NC;
    }

    return (gpio_num_t) pin;
  }
}

Control_output::Control_output()
    : CompoMe::Component() /* PROVIDE */, control(this) /* DATA */,
      pool_down(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      pool_up(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      pin_id(
          /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/) {
  C_INFO_TAG("CONST: Control_output", "Component,Control_output");
  return;
}

//! Destructor
Control_output::~Control_output() noexcept {
  C_INFO_TAG("DEST: Control_output", "Component,Control_output");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                           COMPONENT_FUNCTIONS                           //
/////////////////////////////////////////////////////////////////////////////

void Control_output::configuration() {
  Component::configuration();
  C_INFO_TAG("CONF: Control_output", "Component,Control_output");

  // configuration: sub_componentreturn;
}

void Control_output::connection() {
  // connect: parent
  Component::connection();
  C_INFO_TAG("CONNECT: Control_output", "Component,Control_output");

  // connect: intern

  // connect: sub componentreturn;
}

void Control_output::start() {
  // start: parent
  Component::start();
  C_INFO_TAG("START: Control_output", "Component,Control_output");

  gpio_reset_pin(pin_id2gpio_num_t(this->get_pin_id()));
  gpio_set_direction(pin_id2gpio_num_t(this->get_pin_id()), GPIO_MODE_OUTPUT);

  if(this->get_pool_down()) {
      gpio_pulldown_en(pin_id2gpio_num_t(this->get_pin_id()));
  } else{
      gpio_pulldown_dis(pin_id2gpio_num_t(this->get_pin_id()));
  }

  if(this->get_pool_up()) {
      gpio_pullup_en(pin_id2gpio_num_t(this->get_pin_id()));
  } else {
      gpio_pullup_dis(pin_id2gpio_num_t(this->get_pin_id()));
  }
}

void Control_output::set(uint32_t val) {
  gpio_set_level(pin_id2gpio_num_t(this->get_pin_id()), val);
  this->control.set_state((val == 1)?PIN_STATE_UP:PIN_STATE_DOWN);
}

void Control_output::step() {
  // step: parent
  Component::step();
  C_INFO_TAG("STEP: Control_output", "Component,Control_output");

  // step: receiver process// step: sub_componentreturn;
}

void Control_output::stop() {
  // stop: parent
  Component::stop();
  // stop: sub_component
  C_INFO_TAG("STOP: Control_output", "Component,Control_output");
  gpio_reset_pin(pin_id2gpio_num_t(this->get_pin_id()));
  return;
}

void Control_output::status() {
  // status: parent
  Component::status();
  // status: sub_component
  C_INFO_TAG("STATUS: Control_output", "Component,Control_output");
  return;
}

/////////////////////////////////////////////////////////////////////////////
//                                INTERFACES                               //
/////////////////////////////////////////////////////////////////////////////

// // REQUIRE_LIST /////////////////////////////////////////////////////////////
//

} // namespace esp32

} // namespace IO

} // namespace Embded
