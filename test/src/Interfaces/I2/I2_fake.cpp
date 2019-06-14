#include "Interfaces/I2/I2_fake.hpp"

I2_fake::I2_fake(Function_stream &out, Return_stream &in) : o(out), i(in) {}

I2_fake::~I2_fake() noexcept {}