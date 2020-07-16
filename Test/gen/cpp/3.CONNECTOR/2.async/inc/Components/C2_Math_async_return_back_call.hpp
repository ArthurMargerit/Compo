#pragma once

#include "Data/b.hpp"
#include "Interfaces/Math_async_return/Math_async_return.hpp"

#include "Serialization_context.hpp"

class C2;

class C2_Math_async_return_back_call : public ::Math_async_return {
public:
  C2 *composant;

  //! Default constructor
  C2_Math_async_return_back_call(C2 *comp);

  //! Destructor
  virtual ~C2_Math_async_return_back_call() noexcept;

  bool is_fake() override { return false; }

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Math_async_return /////////////////////////////////////////////////////////
  virtual void ping(int p_ping) override;
  virtual void f1(int p_f1) override;
  virtual void f2(int p_f2) override;
  virtual void f3() override;
  virtual void get_a(int p_a) override;
  virtual void set_a() override;
  virtual void get_b(int p_b) override;
  virtual void set_b() override;

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Math_async_return
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
  C2 &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Math_async_return
};
