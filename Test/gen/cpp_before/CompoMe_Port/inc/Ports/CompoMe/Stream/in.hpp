#pragma once

#include "Ports/CompoMe/Core/in.hpp"

// TYPES

// d.D_NAME

#include "Types/Pair.hpp"

// d.D_NAME

// d.D_NAME

#include "Types/CompoMe/String.hpp"

// STRUCT

namespace CompoMe {

namespace Stream {

class in : public CompoMe::Core::in {
public:
  //! Default constructor
  in();

  //! Destructor
  virtual ~in() noexcept;

  // FUNCTION_IN //////////////////////////////////////////////////////////////
  virtual bool connect_interface(CompoMe::Interface &p_i);

  virtual CompoMe::Interface &get_interface();

  virtual bool is_connected_interface(CompoMe::Interface &p_i);
  virtual bool is_connected_interface();

  virtual bool disconnect_interface();
  virtual bool disconnect_interface(CompoMe::Interface &p_i);

  // FUNCTION /////////////////////////////////////////////////////////////////
  virtual Pair<bool, CompoMe::String> call(CompoMe::String cmd);

  // GET/SET //////////////////////////////////////////////////////////////////

private:
  // YOU PRIVATE DATA//////////////////////////////////////////////////////////

  //---------------------------------------------------------------------------
};

} // namespace Stream

} // namespace CompoMe
