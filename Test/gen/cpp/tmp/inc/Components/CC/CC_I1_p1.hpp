#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I1/I1.hpp"


namespace CC{

  class CC;

  class  I1_p1 : public ::I1
  {
  public:

    CC* composant;

    //! Default constructor
    I1_p1(CC* comp);

    //! Destructor
    virtual ~I1_p1() noexcept;

    I1_p1() = delete;
    //! Copy constructor
    I1_p1(const I1_p1 &other)=delete;
    //! Move constructor
    I1_p1(I1_p1 &&other) = delete;
    // //! Copy assignment operator
    // I1& operator=(const I1 &other)=delete;
    // //! Move assignment operator
    // I1& operator=(I1 &&other) noexcept;
    virtual int call1();

  protected:
  private:
  };

};