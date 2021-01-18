#include "catch.hpp"
#include "Components/CompoMe/Config/DataProvider.hpp"

TEST_CASE("CompoMe config componentx", "[Config]" ) {
  CompoMe::Config::DataProvider d;

  auto& a = d.get_access();
  REQUIRE(a.add("key1","A") == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.add("key2","B") == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.add("key3","C") == CompoMe::Config::Result_state::VALID);

  REQUIRE(a.exist("key1") == true);
  REQUIRE(a.exist("key2") == true);
  REQUIRE(a.exist("key3") == true);

  REQUIRE(a.get("key1").a_state() == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.get("key2").a_state() == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.get("key3").a_state() == CompoMe::Config::Result_state::VALID);

  REQUIRE(a.get("key1").a_result() == "A");
  REQUIRE(a.get("key2").a_result() == "B");
  REQUIRE(a.get("key3").a_result() == "C");

  REQUIRE(a.set("key1", "A1") == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.set("key2", "B1") == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.set("key3", "C1") == CompoMe::Config::Result_state::VALID);

  REQUIRE(a.get("key1").a_state() == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.get("key2").a_state() == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.get("key3").a_state() == CompoMe::Config::Result_state::VALID);

  REQUIRE(a.get("key1").a_result() == "A1");
  REQUIRE(a.get("key2").a_result() == "B1");
  REQUIRE(a.get("key3").a_result() == "C1");

  REQUIRE(a.del("key1")== CompoMe::Config::Result_state::VALID);
  REQUIRE(a.del("key2")== CompoMe::Config::Result_state::VALID);
  REQUIRE(a.del("key3")== CompoMe::Config::Result_state::VALID);

  REQUIRE(a.exist("key1") == false);
  REQUIRE(a.exist("key2") == false);
  REQUIRE(a.exist("key3") == false);
}


TEST_CASE("config data exist/add/del", "[Config]" ) {
  CompoMe::Config::DataProvider d;
  auto& a = d.get_access();

  REQUIRE(a.exist("key") == false);
  REQUIRE(a.add("key","1") == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.exist("key") == true);
  REQUIRE(a.del("key") == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.exist("key") == false);
}


TEST_CASE("config data double add", "[Config]" ) {
  CompoMe::Config::DataProvider d;
  auto& a = d.get_access();
  REQUIRE(a.add("key","1") == CompoMe::Config::Result_state::VALID);
  REQUIRE(a.add("key","2") == CompoMe::Config::Result_state::INVALID_KEY);
}

TEST_CASE("config unex key", "[Config]" ) {
  CompoMe::Config::DataProvider d;
  auto& a = d.get_access();
  REQUIRE(a.del("key") == CompoMe::Config::Result_state::INVALID_KEY);
  REQUIRE(a.set("key","1") == CompoMe::Config::Result_state::INVALID_KEY);
  REQUIRE(a.get("key").a_state() == CompoMe::Config::Result_state::INVALID_KEY);
}
