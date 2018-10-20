#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I1/I1.hpp"


namespace CC {

  class CC;

  class  I1 : public ::I1
  {
  public:

    CC* composant;

    //! Default constructor
    I1(CC* comp);

    //! Destructor
    virtual ~I1() noexcept;

    I1() = delete;
    //! Copy constructor
    I1(const I1 &other)=delete;
    //! Move constructor
    I1(I1 &&other) = delete;
    // //! Copy assignment operator
    // I1& operator=(const I1 &other)=delete;
    // //! Move assignment operator
    // I1& operator=(I1 &&other) noexcept;

  protected:
  private:
  };

};