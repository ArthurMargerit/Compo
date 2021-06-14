#include "I1_i.hpp"
#include "Ports/CompoMe/Stream/in.hpp"
#include "Ports/CompoMe/Stream/map_in.hpp"
#include "Ports/CompoMe/Stream/map_out.hpp"
#include "Ports/CompoMe/Stream/out.hpp"

#include "Interfaces/Function_stream_send_func.hpp"
#include "Interfaces/Return_stream_recv_func.hpp"

#include "catch.hpp"

class LL : public CompoMe::Link {
private:
  std::string resp;
  I1_i i1;
  CompoMe::Stream::in port_in;

public:
  LL() {
    port_in.set_link(*this);
    port_in.connect_interface(i1);
  }
  virtual ~LL() {}

  void one_connect(CompoMe::Require_helper &re, CompoMe::String c) {

    static CompoMe::Function_stream_send_func f;
    static CompoMe::Return_stream_recv_func r;

    f.set_func_send([this](CompoMe::String &str) {
      auto r = this->port_in.call(str);
      this->resp = r.second;

      return true;
    });

    r.set_func_recv([this](CompoMe::String &str) {
      str.str = this->resp;
      return true;
    });

    re.fake_stream_it(f, r);
  }

  void one_disconnect(CompoMe::Require_helper &, CompoMe::String) {
  }

  void one_connect(CompoMe::Interface &, CompoMe::String) {
  }

  void one_disconnect(CompoMe::Interface &, CompoMe::String) {
  }
};

TEST_CASE("Core Port Stream in", "[Port]") {
  CompoMe::Stream::in port_in;
  I1_i i1;
  port_in.connect_interface(i1);
  port_in.disconnect_interface();
}

TEST_CASE("Core Port Stream out", "[Port]") {
  CompoMe::Stream::out port_out;
  CompoMe::Require_helper_t<I1> i1;
  port_out.connect_require(i1);
  port_out.disconnect_require();
}

TEST_CASE("Core Port Stream in co", "[Port]") {
  LL l;

  CompoMe::Stream::in port_in;
  port_in.set_link(l);

  I1_i i1;
  port_in.connect_interface(i1);
  REQUIRE(port_in.call("f1(1)") == std::make_pair(true, CompoMe::String("1")));
  REQUIRE(port_in.call("f2(1,2)") ==
          std::make_pair(true, CompoMe::String("3")));

  REQUIRE(port_in.call("set_a(10)") ==
          std::make_pair(true, CompoMe::String("")));
  REQUIRE(port_in.call("set_b(20)") ==
          std::make_pair(true, CompoMe::String("")));

  REQUIRE(i1.get_a() == 10);
  REQUIRE(i1.get_b() == 20);

  i1.set_a(30);
  i1.set_b(40);
  REQUIRE(i1.get_a() == 30);
  REQUIRE(i1.get_b() == 40);

  REQUIRE(port_in.call("set_a(50)") ==
          std::make_pair(true, CompoMe::String("")));
  REQUIRE(port_in.call("set_b(60)") ==
          std::make_pair(true, CompoMe::String("")));
  REQUIRE(i1.get_a() == 50);
  REQUIRE(i1.get_b() == 60);

  port_in.disconnect_interface();
}

TEST_CASE("Core Port Stream out co", "[Port]") {
  LL l;

  CompoMe::Stream::out port_out;
  port_out.set_link(l);

  CompoMe::Require_helper_t<I1> i1;
  port_out.connect_require(i1);

  REQUIRE(i1->f1(1) == 1);
  REQUIRE(i1->f2(1, 2) == 3);

  port_out.disconnect_require();
}
