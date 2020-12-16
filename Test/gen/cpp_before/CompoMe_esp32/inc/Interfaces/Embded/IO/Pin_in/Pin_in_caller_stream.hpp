#pragma once

#include "Interfaces/Embded/IO/Pin_in/Pin_in.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace Embded {

namespace IO {

class Pin_in_caller_stream : public CompoMe::Caller_stream {
private:
  Embded::IO::Pin_in &comp;

public:
  Pin_in_caller_stream(Embded::IO::Pin_in &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool get_state(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);
  bool set_state(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);
};

} // namespace IO

} // namespace Embded
