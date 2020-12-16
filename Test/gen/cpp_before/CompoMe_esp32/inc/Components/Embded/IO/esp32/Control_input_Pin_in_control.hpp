#pragma once

#include "Data/CompoMe_esp32.hpp"
#include "Interfaces/Embded/IO/Pin_in/Pin_in.hpp"

#include "Serialization_context.hpp"

namespace Embded {

namespace IO {

namespace esp32 {

class Control_input;

class Control_input_Pin_in_control : public ::Embded::IO::Pin_in {
public:
  //! Default constructor
  Control_input_Pin_in_control(Control_input *comp);

  //! Destructor
  virtual ~Control_input_Pin_in_control() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Pin_in /////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Pin_in ///////////////////////////////////////////////////////////////////
  // get/set state
  Embded::IO::Pin_State get_state() const override;
  void set_state(const Embded::IO::Pin_State &state) override;

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
  Control_input &get_c() const;
  Control_input *composant;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Pin_in
  Embded::IO::Pin_State state;
};

} // namespace esp32

} // namespace IO

} // namespace Embded
