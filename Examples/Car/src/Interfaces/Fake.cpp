#include "Interfaces/Fake.hpp"

Fake::Fake(Function_stream_send &p_o, Return_stream_recv &p_i)
    : a_o(p_o), a_i(p_i) {}

Fake::~Fake() {}