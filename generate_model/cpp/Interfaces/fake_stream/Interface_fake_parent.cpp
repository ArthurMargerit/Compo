#include "Interfaces/Fake_stream.hpp"

Fake_stream::Fake_stream(Function_stream_send &p_o, Return_stream_recv &p_i): a_o(p_o), a_i(p_i) {}

Fake_stream::~Fake_stream() {}
