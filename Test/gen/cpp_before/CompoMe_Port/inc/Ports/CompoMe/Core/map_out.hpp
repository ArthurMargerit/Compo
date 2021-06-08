#pragma once

#include "Ports/Port.hpp"

// TYPES

// d.D_NAME

#include "Types/CompoMe/String.hpp"

// STRUCT

namespace CompoMe {

namespace Core {

class map_out : public CompoMe::Port {
public:
  //! Default constructor
  map_out();

  //! Destructor
  virtual ~map_out() noexcept;

  // FUNCTION OUT//////////////////////////////////////////////////////////////
  virtual bool connect_require(CompoMe::String interface_key,
                               CompoMe::Require_helper &p_r);

  virtual CompoMe::Require_helper &get_require(CompoMe::String interface_key);

  const std::map<std::tuple<CompoMe::String>, CompoMe::Require_helper *> &
  get_require_list();

  virtual bool is_connected_require(CompoMe::Require_helper &p_i);
  virtual bool is_connected_require(CompoMe::String interface_key);

  virtual bool disconnect_require(CompoMe::String interface_key);
  virtual bool disconnect_require(CompoMe::Require_helper &p_r);

  // FUNCTION /////////////////////////////////////////////////////////////////

  // GET/SET //////////////////////////////////////////////////////////////////

private:
  // YOU PRIVATE DATA//////////////////////////////////////////////////////////
  std::map<std::tuple<CompoMe::String>, CompoMe::Require_helper *> map_require;
  //---------------------------------------------------------------------------
};

} // namespace Core

} // namespace CompoMe
