
#include "Interfaces/I4/I4.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I4/I4_caller.hpp"
#include "Interfaces/I4/I4_fake.hpp"

I4::I4() : c(nullptr) {}

I4::~I4() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I4::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(I4 *t) {
  std::function<Fake *(Function_stream &, Return_stream &)> f =
      I4::MyFake::Build_func;
  return f;
}

// Fake* I4::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }