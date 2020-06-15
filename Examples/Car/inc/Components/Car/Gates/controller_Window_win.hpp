#pragma once

#include "Data/file.hpp"
#include "Interfaces/Car/Gate/Window/Window.hpp"

#include "Serialization_context.hpp"

namespace Car {

namespace Gates {

class controller;

class controller_Window_win : public ::Car::Gate::Window {
public:
  controller *composant;

  //! Default constructor
  controller_Window_win(controller *comp);

  //! Destructor
  virtual ~controller_Window_win() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Window /////////////////////////////////////////////////////////
  virtual void lock() override;
  virtual void unlock() override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Window ///////////////////////////////////////////////////////////////////
  // get/set percent
  ui8 get_percent() const override;
  void set_percent(const ui8 &percent) override;

  ///////////////////////////////////////////////////////////////////////////
  //                            SAVE/LOAD                                  //
  ///////////////////////////////////////////////////////////////////////////
  // void save(std::ostream& os) const;
  // void load(std::istream& is);
  std::ostream &to_stream(std::ostream &, Serialization_context_export &) const;
  std::istream &from_stream(std::istream &, Serialization_context_import &);

private:
  controller &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Window
  ui8 percent;
};

} // namespace Gates

} // namespace Car
