#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I1/I1.hpp"


namespace CD {

  class CD;

  class  I1 : public ::I1
  {
  public:

    CD* composant;

    //! Default constructor
    I1(CD* comp);

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