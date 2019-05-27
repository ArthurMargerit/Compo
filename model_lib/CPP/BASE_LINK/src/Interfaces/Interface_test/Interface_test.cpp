
#include "Interfaces/Interface_test/Interface_test.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/Interface_test/Interface_test_caller.hpp"
#include "Interfaces/Interface_test/Interface_test_fake.hpp"

Interface_test::Interface_test() : c(nullptr) {}

Interface_test::~Interface_test() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *Interface_test::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Fake *(Function_stream &, Return_stream &)>
build_fake(Interface_test *t) {
  std::function<Fake *(Function_stream &, Return_stream &)> f =
      Interface_test::MyFake::Build_func;
  return f;
}

// Fake* Interface_test::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }