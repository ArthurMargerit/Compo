#pragma once

#include "Data/file.hpp"

#include "Interfaces/Information/Information.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

class Information_fake_stream : public Information,
                                public CompoMe::Fake_stream {
public:
  // constructor
  Information_fake_stream(CompoMe::Function_stream_send &out,
                          CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~Information_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<Information*>(new Information_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual CompoMe::String get_name() override;

  virtual CompoMe::String get_type() override;

  virtual CompoMe::String get_location() override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////
};
