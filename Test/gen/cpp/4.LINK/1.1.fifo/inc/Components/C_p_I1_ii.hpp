#pragma once

#include "Data/code.hpp"
#include "Interfaces/I1/I1.hpp"

#include "Serialization_context.hpp"

class C_p;

class C_p_I1_ii : public ::I1 {
public:
  C_p *composant;

  //! Default constructor
  C_p_I1_ii(C_p *comp);

  //! Destructor
  virtual ~C_p_I1_ii() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // I1 /////////////////////////////////////////////////////////
  virtual void f1() override;
  virtual int f2() override;
  virtual int f3(int a) override;
  virtual int f4(int a, int b) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // I1 ///////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////
  //                            SAVE/LOAD                                  //
  ///////////////////////////////////////////////////////////////////////////
  // void save(std::ostream& os) const;
  // void load(std::istream& is);
  std::ostream &to_stream(std::ostream &,CompoMe::Serialization_context_export &) const;
  std::istream &from_stream(std::istream &,CompoMe::Serialization_context_import &);

private:
  C_p &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for I1
};
