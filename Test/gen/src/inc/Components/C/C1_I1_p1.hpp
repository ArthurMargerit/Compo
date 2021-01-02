#pragma once

#include "Data/code.hpp"
#include "Interfaces/II/I1/I1.hpp"

#include "Serialization_context.hpp"

namespace C {

class C1;

class C1_I1_p1 : public ::II::I1 {
public:
  //! Default constructor
  C1_I1_p1(C1 *comp);

  //! Destructor
  virtual ~C1_I1_p1() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // I1 /////////////////////////////////////////////////////////
  virtual B::i f1() override;
  virtual B::i f2(B::i a, B::i b) override;
  virtual B::i f3(S1 a, S::S2 b) override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // I1 ///////////////////////////////////////////////////////////////////
  // get/set v
  B::i get_v() const override;
  void set_v(const B::i &v) override;

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
  C1 *composant;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for I1
  B::i v;
};

} // namespace C
