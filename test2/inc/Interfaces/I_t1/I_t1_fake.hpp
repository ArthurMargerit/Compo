#pragma once

#include "Data/test2.hpp"

#include "Interfaces/I_t1/I_t1.hpp"

#include "Interfaces/Fake.hpp"

#include "Interfaces/Function_stream.hpp"
#include "Interfaces/Return_stream.hpp"

class I_t1_fake : public I_t1, private Fake {
public:
  // constructor
  I_t1_fake(Function_stream &out, Return_stream &in);

  //! Destructor
  virtual ~I_t1_fake() noexcept;

  static Interface *Build_func(Function_stream &os, Return_stream &is) {
    return (I_t1 *)new I_t1_fake(os, is);
  }

  /////////////////////////////////////////////////////////////////////////////
  //                                 FUNCTION                                //
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////

  virtual A get_sa() const;
  virtual void set_sa(const A sa);

  virtual B get_sb() const;
  virtual void set_sb(const B sb);

  virtual C get_sc() const;
  virtual void set_sc(const C sc);

  virtual D get_sd() const;
  virtual void set_sd(const D sd);

protected:
private:
};
