#pragma once

#include "Ports/CompoMe/Core/out.hpp"

// TYPES

// d.D_NAME

#include "Types/Pair.hpp"

// d.D_NAME

// d.D_NAME

#include "Types/CompoMe/String.hpp"

// STRUCT

namespace CompoMe {

namespace Stream {

class out : public CompoMe::Core::out {
public:
  //! Default constructor
  out();

  //! Destructor
  virtual ~out() noexcept;

  // FUNCTION OUT//////////////////////////////////////////////////////////////
  virtual bool connect_require(CompoMe::Require_helper &p_r);

  virtual CompoMe::Require_helper &get_require();

  virtual bool is_connected_require(CompoMe::Require_helper &p_i);
  virtual bool is_connected_require();

  virtual bool disconnect_require();
  virtual bool disconnect_require(CompoMe::Require_helper &p_r);

  // FUNCTION /////////////////////////////////////////////////////////////////
  virtual Pair<bool, CompoMe::String> call(CompoMe::String cmd);

  // GET/SET //////////////////////////////////////////////////////////////////

private:

  // YOU PRIVATE DATA//////////////////////////////////////////////////////////

  //---------------------------------------------------------------------------
};

} // namespace Stream

} // namespace CompoMe
