
#include "Components/CompoMe/Component_Core.hpp"
#include "catch.hpp"

bool Component_State_check(CompoMe::Component_state state,
                           CompoMe::Component_state expected) {
  return (state & expected) == expected;
}

TEST_CASE("Component core", "[Core]") {
  CompoMe::Component_Core c;
  SECTION("over Component function") {
    // COMPONENT STATE INITIAL
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_STARTED) == false);
    REQUIRE(Component_State_check(
                c.get_state(), CompoMe::COMPONENT_STATE_CONFIGURED) == false);
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_CONNECTED) == false);
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_DEGRADED) == false);
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_DEAD) == false);
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_STRESSED) == false);
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_UNKNOWN) == false);
    // STATE
    REQUIRE(c.get_state() == 0);

    // CONFIGURATION //////////////////////////////////////////////////////////
    c.configuration();
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_CONFIGURED) == true);

    // CONNECTION   //////////////////////////////////////////////////////////
    c.connection();
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_CONNECTED) == true);

    // START //////////////////////////////////////////////////////////////////
    c.start();
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_STARTED) == true);
    c.step();

    // STOP ///////////////////////////////////////////////////////////////////
    c.stop();
    REQUIRE(Component_State_check(c.get_state(),
                                  CompoMe::COMPONENT_STATE_STARTED) == false);
  }

  SECTION("over CompoMe::Component_control interface") {}
}
