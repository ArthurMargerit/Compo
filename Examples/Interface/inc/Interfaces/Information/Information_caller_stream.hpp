#pragma once

#include "Interfaces/Information/Information.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

class Information_caller_stream : public CompoMe::Caller_stream {
private:
  Information &comp;

public:
  Information_caller_stream(Information &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool get_name(CompoMe::Function_stream_recv &is,
                CompoMe::Return_stream_send &os);

  bool get_type(CompoMe::Function_stream_recv &is,
                CompoMe::Return_stream_send &os);

  bool get_location(CompoMe::Function_stream_recv &is,
                    CompoMe::Return_stream_send &os);
};
