#pragma once

#include "Ports/Port.hpp"

// TYPES

// STRUCT

namespace CompoMe {

namespace Core {

class out : public CompoMe::Port {
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

  // GET/SET //////////////////////////////////////////////////////////////////

private:
  // YOU PRIVATE DATA//////////////////////////////////////////////////////////
  CompoMe::Require_helper *a_re;
  //---------------------------------------------------------------------------
};

} // namespace Core

} // namespace CompoMe
