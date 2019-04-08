
#include "Interfaces/Hello_Interface/Hello_Interface.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Hello_Interface/Hello_Interface_caller.hpp"
#include "Interfaces/Hello_Interface/Hello_Interface_fake.hpp"

Hello_Interface::Hello_Interface() : c(nullptr) {}

Hello_Interface::~Hello_Interface() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Hello_Interface::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Fake *(Function_stream &, Return_stream &)>
build_fake(Hello_Interface *t) {
  std::function<Fake *(Function_stream &, Return_stream &)> f =
      Hello_Interface::MyFake::Build_func;
  return f;
}

// Fake* Hello_Interface::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }