#pragma once

#include "Ports/Port.hpp"

// TYPES

// d.D_NAME

#include "Types/CompoMe/String.hpp"

// STRUCT

namespace CompoMe {

namespace Core {

class DCI_map_out : public CompoMe::Port {
public:
  //! Default constructor
  DCI_map_out();

  //! Destructor
  virtual ~DCI_map_out() noexcept;

  // FUNCTION OUT//////////////////////////////////////////////////////////////
  virtual bool connect_require(CompoMe::String dest_key,
                               CompoMe::String component_key,
                               CompoMe::String interface_key,
                               CompoMe::Require_helper &p_r);

  virtual CompoMe::Require_helper &get_require(CompoMe::String dest_key,
                                               CompoMe::String component_key,
                                               CompoMe::String interface_key);

  std::map<std::tuple<CompoMe::String, CompoMe::String, CompoMe::String>,
           CompoMe::Require_helper *>
  get_require_list();

  virtual bool is_connected_require(CompoMe::Require_helper &p_i);
  virtual bool is_connected_require(CompoMe::String dest_key,
                                    CompoMe::String component_key,
                                    CompoMe::String interface_key);

  virtual bool disconnect_require(CompoMe::String dest_key,
                                  CompoMe::String component_key,
                                  CompoMe::String interface_key);
  virtual bool disconnect_require(CompoMe::Require_helper &p_r);

  // FUNCTION /////////////////////////////////////////////////////////////////

  // GET/SET //////////////////////////////////////////////////////////////////

private:
  // YOU PRIVATE DATA//////////////////////////////////////////////////////////
  std::map<std::tuple<CompoMe::String, CompoMe::String, CompoMe::String>,
           CompoMe::Require_helper *>
      map_dest_compo_inter_require;
  //---------------------------------------------------------------------------
};

} // namespace Core

} // namespace CompoMe
