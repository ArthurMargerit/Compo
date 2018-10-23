#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I1/I1.hpp"


namespace CF{

  class CF;

  class  I1_p2 : public ::I1
  {
  public:

    CF* composant;

    //! Default constructor
    I1_p2(CF* comp);

    //! Destructor
    virtual ~I1_p2() noexcept;

    I1_p2() = delete;
    //! Copy constructor
    I1_p2(const I1_p2 &other)=delete;
    //! Move constructor
    I1_p2(I1_p2 &&other) = delete;
    // //! Copy assignment operator
    // I1& operator=(const I1 &other)=delete;
    // //! Move assignment operator
    // I1& operator=(I1 &&other) noexcept;
    virtual int call1();

  protected:
  private:
  };

};