#include "Interfaces/Fake_json.hpp"

namespace CompoMe {

Fake_json::Fake_json(Function_json_send &out, Return_json_recv &in)
    : a_o(out), a_i(in) {}

Fake_json::~Fake_json() {}

} // namespace CompoMe
