#pragma once

#include "Data/file.hpp"

#include "Interfaces/Calc_I/Calc_I.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

class Calc_I_fake_stream : public Calc_I, public CompoMe::Fake_stream {
public:
  // constructor
  Calc_I_fake_stream(CompoMe::Function_stream_send &out,
                     CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Calc_I_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Calc_I*>(new Calc_I_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual double add(double a, double b) override;

  virtual double sub(double a, double b) override;

  virtual double time(double a, double b) override;

  virtual double div(double a, double b) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
