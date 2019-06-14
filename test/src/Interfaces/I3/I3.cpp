
#include "Interfaces/I3/I3.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I3/I3_caller.hpp"
#include "Interfaces/I3/I3_fake.hpp"

I3::I3() : c(nullptr) {}

I3::~I3() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I3::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(I3 *t) {
  std::function<Fake *(Function_stream &, Return_stream &)> f =
      I3::MyFake::Build_func;
  return f;
}

// Fake* I3::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }