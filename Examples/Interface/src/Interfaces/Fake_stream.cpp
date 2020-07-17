#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {

Fake_stream::Fake_stream(CompoMe::Function_stream_send &p_o,
                         CompoMe::Return_stream_recv &p_i)
    : a_o(p_o), a_i(p_i) {}

Fake_stream::~Fake_stream() {}

} // namespace CompoMe