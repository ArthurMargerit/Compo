#pragma once

#include "Data/file.hpp"

#include "Interfaces/Information/Information.hpp"

#include "Interfaces/Fake.hpp"

class Function_stream_send;
class Return_stream_recv;

class Information_fake : public Information, public Fake {
public:
  // constructor
  Information_fake(Function_stream_send &out, Return_stream_recv &in);

  //! Destructor
  virtual ~Information_fake() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Information*>(new Information_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual string get_name() override;

  virtual string get_type() override;

  virtual string get_location() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
