
#include <iostream>
#include <sstream>

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

#include "Interfaces/Caller_stream.hpp"
namespace CompoMe {

class Fs : public Function_stream_recv {
  std::stringstream s;

public:
  Fs() {}
  virtual ~Fs() {}

  void set_str(std::string p_str) { this->s.str(p_str); }
  void pull() {}

  void end() {}

  void reset() {
    this->s =   std::stringstream();
  }

  std::istream &get_si() { return s; }
};

class Rs : public Return_stream_send {
  std::stringstream s;

public:
  Rs() {}
  virtual ~Rs() {}

  std::string get_str() { return this->s.str(); }
  void start() { this->s.str(""); }
  void send() {}
  std::ostream &get_so() { return s; }
};

// Mise en place d'un terminal minimaliste ////////////////////////////////////
void term(Caller_stream *c) {
  Fs f;
  Rs r;

  while (true) {
    std::cout << "\n>>>";
    if (!std::cin.good() || std::cin.eof()) {
      break;
    }

    if (std::cin.peek() == '\n') {
      std::cin.get();
      continue;
    }

    std::string str;
    std::getline(std::cin, str);
    if (str == "exit") {
      break;
    }

    if (str == "?" || str == "help") {
      c->introspection(std::cout);
      continue;
    }

    f.reset();
    f.set_str(str);
    bool l_result = c->call(f, r);
    if (l_result) {
      std::cout << str << "->" << r.get_str() << "\n";
    } else {
      std::cout << "Call error: " << '"' << str << '"' << "\n";
    }
  }
}

} // namespace CompoMe
