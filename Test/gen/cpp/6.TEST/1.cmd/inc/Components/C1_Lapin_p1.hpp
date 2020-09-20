#pragma once

#include "Data/exist.hpp"
#include "Interfaces/Lapin/Lapin.hpp"

#include "Serialization_context.hpp"

class C1;

class C1_Lapin_p1 : public ::Lapin {
public:
  C1 *composant;

  //! Default constructor
  C1_Lapin_p1(C1 *comp);

  //! Destructor
  virtual ~C1_Lapin_p1() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Lapin /////////////////////////////////////////////////////////
  virtual i32 add(i32 a, i32 b) override;
  virtual i32 sub(i32 a, i32 b) override;
  virtual i32 time(i32 a, i32 b) override;
  virtual i32 div(i32 a, i32 b) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Lapin ///////////////////////////////////////////////////////////////////

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
  C1 &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Lapin
};
