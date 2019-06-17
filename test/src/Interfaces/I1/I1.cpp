
#include "Interfaces/I1/I1.hpp"
#include "Interfaces/Caller.hpp"
#include "Interfaces/Fake.hpp"
#include "Interfaces/I1/I1_caller.hpp"
#include "Interfaces/I1/I1_fake.hpp"

I1::I1() : c(nullptr) {}

I1::~I1() noexcept {
  if (c != nullptr) {
    delete c;
  }
}

Caller *I1::get_caller() {
  if (c == nullptr) {
    c = new MyCaller(*this);
  }

  return c;
}

std::function<Fake *(Function_stream &, Return_stream &)> build_fake(I1 *t) {
  std::function<Fake *(Function_stream &, Return_stream &)> f =
      I1::MyFake::Build_func;
  return f;
}

// Fake* I1::get_fake(std::ostream& os, std::istream& is)
// {
//   return new  MyFake(os, is);
// }