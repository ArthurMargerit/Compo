#include "Interfaces/Return_stream_send.hpp"

#include "Data/code.hpp"
#include "catch.hpp"
#include <iostream>

class rss : public CompoMe::Return_stream_send {
public:
  rss() {}
  virtual ~rss() {}
  virtual void start() {}
  virtual void send() {}
  virtual std::ostream &get_so() { return std::cout; }
};

TEST_CASE("Interface gen_multi", "[Interface][gen_multi]") {

  Vec<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  std::cout << "- " << a << "\n";
  rss rs;
  rs << a;
}
