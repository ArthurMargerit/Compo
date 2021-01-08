#pragma once

#include "Data/CompoMe.hpp"
#include "Interfaces/CompoMe/Component_Control/Component_Control.hpp"

#include "Serialization_context.hpp"

namespace CompoMe {

class Component_Core;

class Component_Core_Component_Control_handle
    : public ::CompoMe::Component_Control {
public:
  //! Default constructor
  Component_Core_Component_Control_handle(Component_Core *comp);

  //! Destructor
  virtual ~Component_Core_Component_Control_handle() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Component_Control /////////////////////////////////////////////////////////
  virtual void step() override;
  virtual void start() override;
  virtual void stop() override;
  virtual void init() override;
  virtual void uninit() override;
  virtual void connect() override;
  virtual void configure() override;
  virtual CompoMe::String name() override;
  virtual CompoMe::Component_state state() override;
  virtual CompoMe::String status() override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Component_Control
  // ///////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  //                            SAVE/LOAD                                  //
  ///////////////////////////////////////////////////////////////////////////
  // void save(std::ostream& os) const;
  // void load(std::istream& is);
  std::ostream &to_stream(std::ostream &,
                          CompoMe::Serialization_context_export &) const;
  std::istream &from_stream(std::istream &,
                            CompoMe::Serialization_context_import &);

private:
  Component_Core &get_c() const;
  Component_Core *composant;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Component_Control
};

} // namespace CompoMe
