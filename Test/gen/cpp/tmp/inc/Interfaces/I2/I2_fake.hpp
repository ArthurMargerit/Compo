#pragma once

#include "Data/Types.hpp"
#include "Interfaces/I2/I2.hpp"

#include <ostream>

template <typename To, typename Ti>
class I2_fake : public I2
{
public:
  //! Default constructor
  I2_fake(std::string& des, To& out, Ti& in):des(des),o(out),i(in)
            {

            }

  //! Destructor
  virtual ~I2_fake() noexcept{}

  /////////////////////////////////////////////////////////////////////////////
  //                               GET and SET                               //
  /////////////////////////////////////////////////////////////////////////////


protected:

private:
  std::string des;
  To& o;
  Ti& i;
};

