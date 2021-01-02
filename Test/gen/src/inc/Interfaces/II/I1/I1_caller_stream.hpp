#pragma once

#include "Interfaces/II/I1/I1.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

namespace II {

class I1_caller_stream : public CompoMe::Caller_stream {
private:
  II::I1 &comp;

public:
  I1_caller_stream(II::I1 &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool f1(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f2(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool f3(CompoMe::Function_stream_recv &is, CompoMe::Return_stream_send &os);

  bool get_v(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
  bool set_v(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
};

} // namespace II
