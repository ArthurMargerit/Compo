#pragma once

#include "Interfaces/Hello_I/Hello_I.hpp"

#include "Interfaces/Caller_stream.hpp"

#include <string>

class Hello_I_caller_stream : public CompoMe::Caller_stream {
private:
  Hello_I &comp;

public:
  Hello_I_caller_stream(Hello_I &pcomp);
  bool call(CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

protected:
  bool call(std::string &name_function, CompoMe::Function_stream_recv &is,
            CompoMe::Return_stream_send &os) override;

private:
  bool hello(CompoMe::Function_stream_recv &is,
             CompoMe::Return_stream_send &os);
};
