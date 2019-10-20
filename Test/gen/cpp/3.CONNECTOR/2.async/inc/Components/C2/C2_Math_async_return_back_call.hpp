#pragma once

#include "Data/code.hpp"

#include "Interfaces/Math_async_return/Math_async_return.hpp"

namespace C2 {

class C2;

class Math_async_return_back_call : public ::Math_async_return {
public:
  C2 *composant;

  //! Default constructor
  Math_async_return_back_call(C2 *comp);

  //! Destructor
  virtual ~Math_async_return_back_call() noexcept;

  Math_async_return_back_call() = delete;
  //! Copy constructor
  Math_async_return_back_call(const Math_async_return_back_call &other) =
      delete;
  //! Move constructor
  Math_async_return_back_call(Math_async_return_back_call &&other) = delete;
  // //! Copy assignment operator
  // Math_async_return& operator=(const Math_async_return &other)=delete;
  // //! Move assignment operator
  // Math_async_return& operator=(Math_async_return &&other) noexcept;

  ///////////////////////////////////////////////////////////////////////////
  //                                FUNCTION                               //
  ///////////////////////////////////////////////////////////////////////////

  // Math_async_return /////////////////////////////////////////////////////////
  virtual void ping(int p_ping);
  virtual void f1(int p_f1);
  virtual void f2(int p_f2);
  virtual void f3();
  virtual void get_a(int p_a);
  virtual void set_a();
  virtual void get_b(int p_b);
  virtual void set_b();

  ///////////////////////////////////////////////////////////////////////////
  //                              GET/SET                                  //
  ///////////////////////////////////////////////////////////////////////////

  // Math_async_return
  // ///////////////////////////////////////////////////////////////////

private:
  C2 &get_c() const;

  ///////////////////////////////////////////////////////////////////////////
  //                                  DATA                                 //
  ///////////////////////////////////////////////////////////////////////////

  // DATA for Math_async_return
};
};