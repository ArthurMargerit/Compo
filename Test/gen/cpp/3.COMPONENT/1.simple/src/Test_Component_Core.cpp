
#include "Components/CompoMe/Component_Core.hpp"
#include "Errors/CompoMe/Component_Core_ns/Wrong_state_transition.hpp"
#include "catch.hpp"

TEST_CASE("Component core state transition", "[Core]") {
  CompoMe::Component_Core c;
  SECTION("over Component function") {
    // COMPONENT STATE INITIAL
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::STARTED) ==
          false);
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::CONFIGURED) ==
          false);
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::CONNECTED) ==
          false);
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::DEGRADED) ==
          false);
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::DEAD) == false);
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::STRESSED) ==
          false);
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::UNKNOWN) ==
          false);
    // STATE
    //    CHECK(c.get_state() == 0);

    // CONFIGURATION //////////////////////////////////////////////////////////
    c.get_handle().init();
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::INITIALIZED) ==
          true);
    c.get_handle().configure();
    INFO("state: " << c.get_state());
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::CONFIGURED) ==
          true);

    // CONNECTION   //////////////////////////////////////////////////////////
    c.get_handle().connect();
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::CONNECTED) ==
          true);

    // START //////////////////////////////////////////////////////////////////
    c.get_handle().start();
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::STARTED) ==
          true);
    c.get_handle().step();

    // STOP ///////////////////////////////////////////////////////////////////
    c.get_handle().stop();
    CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::STARTED) ==
          false);
  }
}

TEST_CASE("Component core wrong state transition", "[Core][State]") {
  // COMPONENT STATE INITIAL
  CompoMe::Component_Core c;
  CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::INITIALIZED) ==
        false);
  CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::STARTED) == false);
  CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::CONFIGURED) ==
        false);
  CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::CONNECTED) ==
        false);
  CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::DEGRADED) ==
        false);
  CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::DEAD) == false);
  CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::STRESSED) ==
        false);
  CHECK(CompoMe::is(c.get_state(), CompoMe::Component_state::UNKNOWN) == false);

  CHECK_THROWS_AS(c.get_handle().configure(),
                  CompoMe::Component_Core_ns::Wrong_state_transition);
  CHECK_THROWS_AS(c.get_handle().connect(),
                  CompoMe::Component_Core_ns::Wrong_state_transition);
  CHECK_THROWS_AS(c.get_handle().start(),
                  CompoMe::Component_Core_ns::Wrong_state_transition);
  CHECK_THROWS_AS(c.get_handle().stop(),
                  CompoMe::Component_Core_ns::Wrong_state_transition);
  CHECK_THROWS_AS(c.get_handle().stop(),
                  CompoMe::Component_Core_ns::Wrong_state_transition);
  CHECK_THROWS_AS(c.get_handle().step(),
                  CompoMe::Component_Core_ns::Wrong_state_transition);
}

SCENARIO("Component life", "[Component][Core][configuration][connection]") {
  GIVEN("A Component is create") {
    CompoMe::Component_Core c;
    REQUIRE(CompoMe::is(c.get_state(), CompoMe::Component_state::INITIALIZED) ==
            false);

    WHEN("The Component is initialized") {
      c.get_handle().init();
      THEN("The state is INIT") {
        REQUIRE(CompoMe::is(c.get_state(),
                            CompoMe::Component_state::INITIALIZED) == true);
      }
      AND_WHEN("The Component is configured") {
        c.get_handle().configure();
        THEN("The state is CONFIGURE") {
          REQUIRE(CompoMe::is(c.get_state(),
                              CompoMe::Component_state::CONFIGURED) == true);
        }
      }
      AND_WHEN("The Component is connectd") {
        c.get_handle().connect();
        THEN("The state is CONNECT") {
          REQUIRE(CompoMe::is(c.get_state(),
                              CompoMe::Component_state::CONNECTED) == true);
        }
      }
    }
  }
}
