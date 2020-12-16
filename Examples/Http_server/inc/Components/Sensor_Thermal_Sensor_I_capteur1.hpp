#pragma once

#include "Data/file.hpp"
#include "Interfaces/Thermal_Sensor_I/Thermal_Sensor_I.hpp"

#include "Serialization_context.hpp"

class Sensor;

class Sensor_Thermal_Sensor_I_capteur1 : public ::Thermal_Sensor_I {
public:
  Sensor *composant;

  //! Default constructor
  Sensor_Thermal_Sensor_I_capteur1(Sensor *comp);

  //! Destructor
  virtual ~Sensor_Thermal_Sensor_I_capteur1() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Thermal_Sensor_I /////////////////////////////////////////////////////////
  virtual double get_temperature() override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Thermal_Sensor_I
  // ///////////////////////////////////////////////////////////////////
  // get/set ofset
  double get_ofset() const override;
  void set_ofset(const double &ofset) override;

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

  // DATA for Thermal_Sensor_I
  double ofset;
};
