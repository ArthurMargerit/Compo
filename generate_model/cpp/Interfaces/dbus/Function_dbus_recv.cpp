#include "Interfaces/Function_dbus_recv.hpp"

#include "Structs/Struct.hpp"

namespace CompoMe {
void import_struct(CompoMe::Function_dbus_recv &s, Struct &e) {
  e.from_stream(s.get_si(), s.get_ctx());
}

} // namespace CompoMe
