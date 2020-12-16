#pragma once

#include "Data/file.hpp"
#include "Interfaces/Information_I/Information_I.hpp"

#include "Serialization_context.hpp"

class Sensor;

class Sensor_Information_I_information : public ::Information_I {
public:
  Sensor *composant;

  //! Default constructor
  Sensor_Information_I_information(Sensor *comp);

  //! Destructor
  virtual ~Sensor_Information_I_information() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Information_I /////////////////////////////////////////////////////////
  virtual CompoMe::String get_name() override;
  virtual CompoMe::String get_type() override;
  virtual CompoMe::String get_location() override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Information_I
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
  Sensor &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Information_I
};
