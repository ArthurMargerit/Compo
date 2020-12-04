#include "Data/code.hpp"
#include "catch.hpp"
#include <sstream>

#include "Errors/E1.hpp"
#include "Errors/E2.hpp"
#include "Errors/E3.hpp"

#include "Interfaces/IA/IA_fake_stream.hpp"
#include "Interfaces/IB/IB_fake_stream.hpp"
#include "Test.hpp"

TEST_CASE("Interfaces Fake Error function",
          "[Interface][Fake][Function][Error]") {
  init_code();
  std::stringstream so;
  std::stringstream si;

  Function_string_stream_send fs(so);
  Return_string_stream_recv rs(si);
  IB *b = new IB_fake_stream(fs, rs);

  SECTION("no return") {
    // if no return ///////////////////////////////////////////////////////////
    si << "!*(0x1){addr:0x1,type:E1}";
    REQUIRE_THROWS_AS(b->f0(), E1);

    si << "!*(0x1){addr:0x1,type:E2}";
    REQUIRE_THROWS_AS(b->f0(), E2);

    si << "!*(0x1){addr:0x1,type:E3}";
    REQUIRE_THROWS_AS(b->f0(), E3);
  }

  SECTION("return") {
    // if return //////////////////////////////////////////////////////////////
    si << "!*(0x1){addr:0x1,type:E1}";
    REQUIRE_THROWS_AS(b->f1(), E1);

    si << "!*(0x1){addr:0x1,type:E2}";
    REQUIRE_THROWS_AS(b->f1(), E2);

    si << "!*(0x1){addr:0x1,type:E3}";
    REQUIRE_THROWS_AS(b->f1(), E3);
  }
  delete (b);
}
