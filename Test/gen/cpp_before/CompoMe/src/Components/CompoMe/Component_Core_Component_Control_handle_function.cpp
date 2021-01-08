#include "Components/CompoMe/Component_Core.hpp"
#include "Components/CompoMe/Component_Core_Component_Control_handle.hpp"

#include "CompoMe/Log.hpp"

namespace CompoMe {
void Component_Core_Component_Control_handle::step() {
  auto v_state = this->get_c().get_state();

  if (v_state & COMPONENT_STATE_STARTED == COMPONENT_STATE_STARTED) {
    C_ERROR("Wrong state translation",
            "to do a step you need to start component first");
    return;
  }

  // do component step
  this->get_c().step();
  return;
}

void Component_Core_Component_Control_handle::start() {
  auto v_state = this->get_c().get_state();

  if (v_state & COMPONENT_STATE_CONFIGURED == COMPONENT_STATE_CONFIGURED) {
    C_ERROR("Wrong state translation",
            "to do a start you need to configure component first");
    return;
  }

  if (v_state & COMPONENT_STATE_CONNECTED == COMPONENT_STATE_CONNECTED) {
    C_ERROR("Wrong state translation",
            "to do a start you need to connect component first");
    return;
  }

  // do component start
  this->get_c().start();
  return;
}

void Component_Core_Component_Control_handle::stop() {
  auto v_state = this->get_c().get_state();

  if (v_state & COMPONENT_STATE_STARTED == COMPONENT_STATE_STARTED) {
    C_ERROR("Wrong state translation",
            "to do a stop you need to start component first");
    return;
  }

  this->get_c().stop();
  return;
}

void Component_Core_Component_Control_handle::init() {
  //  this->get_c().init();
  return;
}

void Component_Core_Component_Control_handle::uninit() {
  // this->get_c().uninit();
  return;
}

void Component_Core_Component_Control_handle::connect() {
  auto v_state = this->get_c().get_state();
  if (v_state & COMPONENT_STATE_INITIALIZED == COMPONENT_STATE_INITIALIZED) {
    C_ERROR("Wrong state translation",
            "to do a configured you need to initialized component first");
    return;
  }

  this->get_c().connection();
  return;
}

void Component_Core_Component_Control_handle::configure() {
  auto v_state = this->get_c().get_state();
  if (v_state & COMPONENT_STATE_INITIALIZED == COMPONENT_STATE_INITIALIZED) {
    C_ERROR("Wrong state translation",
            "to do a configured you need to initialized component first");
    return;
  }

  this->get_c().configuration();
  return;
}

CompoMe::String Component_Core_Component_Control_handle::name() {
  return this->get_c().get_name();
}

CompoMe::Component_state Component_Core_Component_Control_handle::state() {
  return this->get_c().get_state();
}

CompoMe::String Component_Core_Component_Control_handle::status() {
  CompoMe::String ret = CompoMe::String("Test");
  return ret;
}

} // namespace CompoMe
