#pragma once

#include "Ports/CompoMe/Core/c_map_out.hpp"

// TYPES

// d.D_NAME

#include "Types/Pair.hpp"

// d.D_NAME

// d.D_NAME

#include "Types/CompoMe/String.hpp"

// STRUCT

namespace CompoMe {

namespace Stream {

class map_out : public CompoMe::Core::c_map_out {
public:
  //! Default constructor
  map_out();

  //! Destructor
  virtual ~map_out() noexcept;

  // FUNCTION OUT//////////////////////////////////////////////////////////////
  virtual bool connect_require(CompoMe::String interface_key,
                               CompoMe::Require_helper &p_r);

  virtual CompoMe::Require_helper &get_require(CompoMe::String interface_key);

  const std::map<std::tuple<CompoMe::String>, CompoMe::Require_helper *>&
  get_require_list();

  virtual bool is_connected_require(CompoMe::Require_helper &p_i);
  virtual bool is_connected_require(CompoMe::String interface_key);

  virtual bool disconnect_require(CompoMe::String interface_key);
  virtual bool disconnect_require(CompoMe::Require_helper &p_r);

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
