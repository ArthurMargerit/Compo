#include "Interfaces/I3/I3_fake.hpp"

I3_fake::I3_fake(Function_stream &out, Return_stream &in) : o(out), i(in) {}

I3_fake::~I3_fake() noexcept {}