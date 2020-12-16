#pragma once

#include "Interfaces/Information_I/Information_I.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

class Information_I_caller_stream : public CompoMe::Caller_stream {
private:
  Information_I &comp;

public:
  Information_I_caller_stream(Information_I &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

  void introspection(std::ostream &ss) override;

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
