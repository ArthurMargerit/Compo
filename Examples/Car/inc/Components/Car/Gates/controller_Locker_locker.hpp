#pragma once

#include "Data/file.hpp"
#include "Interfaces/Car/Gate/Locker/Locker.hpp"

#include "Serialization_context.hpp"

namespace Car {

namespace Gates {

class controller;

class controller_Locker_locker : public ::Car::Gate::Locker {
public:
  controller *composant;

  //! Default constructor
  controller_Locker_locker(controller *comp);

  //! Destructor
  virtual ~controller_Locker_locker() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Locker /////////////////////////////////////////////////////////
  virtual void open_window() override;
  virtual void close_window() override;
  virtual CompoMe::String state() override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Locker ///////////////////////////////////////////////////////////////////

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
  controller &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Locker
};

} // namespace Gates

} // namespace Car
