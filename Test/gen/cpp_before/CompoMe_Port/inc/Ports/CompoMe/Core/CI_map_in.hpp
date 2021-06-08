#pragma once

#include "Ports/Port.hpp"

// TYPES

// d.D_NAME

#include "Types/CompoMe/String.hpp"

// STRUCT

namespace CompoMe {

namespace Core {

class CI_map_in : public CompoMe::Port {
public:
  //! Default constructor
  CI_map_in();

  //! Destructor
  virtual ~CI_map_in() noexcept;

  // FUNCTION_IN //////////////////////////////////////////////////////////////
  virtual bool connect_interface(CompoMe::String component_key,
                                 CompoMe::String interface_key,
                                 CompoMe::Interface &p_i);

  virtual CompoMe::Interface &get_interface(CompoMe::String component_key,
                                            CompoMe::String interface_key);

  std::map<std::tuple<CompoMe::String, CompoMe::String>, CompoMe::Interface *>
  get_interfaces_list();

  virtual bool is_connected_interface(CompoMe::Interface &p_i);
  virtual bool is_connected_interface(CompoMe::String component_key,
                                      CompoMe::String interface_key);

  virtual bool disconnect_interface(CompoMe::String component_key,
                                    CompoMe::String interface_key);
  virtual bool disconnect_interface(CompoMe::Interface &p_i);

  // FUNCTION /////////////////////////////////////////////////////////////////

  // GET/SET //////////////////////////////////////////////////////////////////

private:
  // YOU PRIVATE DATA//////////////////////////////////////////////////////////
  std::map<std::tuple<CompoMe::String, CompoMe::String>, CompoMe::Interface *>
      map_compo_inter;
  //---------------------------------------------------------------------------
};

} // namespace Core

} // namespace CompoMe
