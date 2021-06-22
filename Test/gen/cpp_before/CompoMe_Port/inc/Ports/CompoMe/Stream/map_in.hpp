#pragma once

#include "Ports/CompoMe/Core/map_in.hpp"

// TYPES

// d.D_NAME

#include "Types/Pair.hpp"

// d.D_NAME

// d.D_NAME

#include "Types/CompoMe/String.hpp"

// STRUCT

namespace CompoMe {

namespace Stream {

class map_in : public CompoMe::Core::map_in {
public:
  //! Default constructor
  map_in();

  //! Destructor
  virtual ~map_in() noexcept;

  // FUNCTION_IN //////////////////////////////////////////////////////////////
  virtual bool connect_interface(CompoMe::String interface_key,
                                 CompoMe::Interface &p_i);

  virtual CompoMe::Interface &get_interface(CompoMe::String interface_key);

  const std::map<std::tuple<CompoMe::String>, CompoMe::Interface *> &
  get_interfaces_list();

  virtual bool is_connected_interface(CompoMe::Interface &p_i);
  virtual bool is_connected_interface(CompoMe::String interface_key);

  virtual bool disconnect_interface(CompoMe::String interface_key);
  virtual bool disconnect_interface(CompoMe::Interface &p_i);

  // FUNCTION /////////////////////////////////////////////////////////////////
  virtual Pair<bool, CompoMe::String> call(CompoMe::String cmd);
  virtual Pair<bool, CompoMe::String>
  call_on_interface(CompoMe::String interface, CompoMe::String cmd);

  // GET/SET //////////////////////////////////////////////////////////////////

private:

  // YOU PRIVATE DATA//////////////////////////////////////////////////////////

  //---------------------------------------------------------------------------
};

} // namespace Stream

} // namespace CompoMe
