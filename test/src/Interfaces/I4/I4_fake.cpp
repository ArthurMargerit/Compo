#include "Interfaces/I4/I4_fake.hpp"

I4_fake::I4_fake(Function_stream &out, Return_stream &in) : o(out), i(in) {}

I4_fake::~I4_fake() noexcept {}