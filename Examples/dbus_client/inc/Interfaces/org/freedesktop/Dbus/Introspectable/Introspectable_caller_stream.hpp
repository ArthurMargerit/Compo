#pragma once

#include "Interfaces/org/freedesktop/Dbus/Introspectable/Introspectable.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace org {

namespace freedesktop {

namespace Dbus {

class Introspectable_caller_stream : public CompoMe::Caller_stream {
private:
  org::freedesktop::Dbus::Introspectable &comp;

public:
  Introspectable_caller_stream(org::freedesktop::Dbus::Introspectable &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool Introspect(CompoMe::Function_stream_recv &is,
                  CompoMe::Return_stream_send &os);
};

} // namespace Dbus

} // namespace freedesktop

} // namespace org
