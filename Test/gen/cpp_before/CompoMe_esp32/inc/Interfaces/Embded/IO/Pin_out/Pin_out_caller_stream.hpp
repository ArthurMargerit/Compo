#pragma once

#include "Interfaces/Embded/IO/Pin_out/Pin_out.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace Embded {

namespace IO {

class Pin_out_caller_stream : public CompoMe::Caller_stream {
private:
  Embded::IO::Pin_out &comp;

public:
  Pin_out_caller_stream(Embded::IO::Pin_out &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool on(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool off(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool set(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool switch_v(CompoMe::Function_stream_recv &is,
                CompoMe::Return_stream_send &os);

  bool get_state(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);
  bool set_state(CompoMe::Function_stream_recv &is,
                 CompoMe::Return_stream_send &os);
};

} // namespace IO

} // namespace Embded
