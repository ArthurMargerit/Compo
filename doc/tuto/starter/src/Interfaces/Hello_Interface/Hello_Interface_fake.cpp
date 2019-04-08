#include "Interfaces/Hello_Interface/Hello_Interface_fake.hpp"

Hello_Interface_fake::Hello_Interface_fake(Function_stream &out,
                                           Return_stream &in)
    : o(out), i(in) {}

Hello_Interface_fake::~Hello_Interface_fake() noexcept {}
void Hello_Interface_fake::hello_word() {
  o.start();
  o << "hello_word("

    << ")";
  o.call();

  i.pull();
}