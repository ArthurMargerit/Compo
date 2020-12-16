#pragma once

#include "Data/code.hpp"

#include "Interfaces/II/I1/I1.hpp"

#include "Interfaces/Fake_stream.hpp"

namespace CompoMe {
class Function_stream_send;
class Return_stream_recv;
} // namespace CompoMe

namespace II {

class I1_fake_stream : public II::I1, public CompoMe::Fake_stream {
public:
  // constructor
  I1_fake_stream(CompoMe::Function_stream_send &out,
                 CompoMe::Return_stream_recv &in);

  //! Destructor
  virtual ~I1_fake_stream() noexcept;

  // static
  //   Interface* Build_func(Function_stream& os, Return_stream& is) {
  //   return dynamic_cast<II::I1*>(new II::I1_fake(os,is));
  // }

  bool is_fake() override { return true; }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  virtual B::i f1() override;

  virtual B::i f2(B::i a, B::i b) override;

  virtual B::i f3(S1 a, S::S2 b) override;

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual B::i get_v() const override;
  virtual void set_v(const B::i &v) override;
};

} // namespace II
