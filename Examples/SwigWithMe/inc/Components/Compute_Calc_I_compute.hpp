#pragma once

#include "Data/file.hpp"
#include "Interfaces/Calc_I/Calc_I.hpp"

#include "Serialization_context.hpp"

class Compute;

class Compute_Calc_I_compute : public ::Calc_I {
public:
  Compute *composant;

  //! Default constructor
  Compute_Calc_I_compute(Compute *comp);

  //! Destructor
  virtual ~Compute_Calc_I_compute() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Calc_I /////////////////////////////////////////////////////////
  virtual double add(double a, double b) override;
  virtual double sub(double a, double b) override;
  virtual double time(double a, double b) override;
  virtual double div(double a, double b) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Calc_I ///////////////////////////////////////////////////////////////////

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
  Compute &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Calc_I
};
