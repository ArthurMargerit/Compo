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
   void f1() override;
   int f2() override;
   int f3(int a) override;
   int f4(int a, int b) override;
   S1 get_myS1(int a, int b) override;
   Vec<S1> get_allS1() override;
  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // I1 ///////////////////////////////////////////////////////////////////
  // get/set a
  int get_a() const override;
  void set_a(const int &a) override;
  // get/set b
  int get_b() const override;
  void set_b(const int &b) override;

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
  int a;
  int b;
};
