#pragma once

#include "Data/file.hpp"

#include "Interfaces/Calculator/Calculator.hpp"

#include "Interfaces/Fake.hpp"

class Function_stream_send;
class Return_stream_recv;

class Calculator_fake : public Calculator, public Fake {
public:
  // constructor
  Calculator_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~Calculator_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Calculator*>(new Calculator_fake(os,is));
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
