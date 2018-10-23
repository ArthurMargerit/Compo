#pragma once

#include "Data/Types.hpp"

#include "Interfaces/I1/I1.hpp"


namespace CD{

  class CD;

  class  I1_p4 : public ::I1
  {
  public:

    CD* composant;

    //! Default constructor
    I1_p4(CD* comp);

    //! Destructor
    virtual ~I1_p4() noexcept;

    I1_p4() = delete;
    //! Copy constructor
    I1_p4(const I1_p4 &other)=delete;
    //! Move constructor
    I1_p4(I1_p4 &&other) = delete;
    // //! Copy assignment operator
    // I1& operator=(const I1 &other)=delete;
    // //! Move assignment operator
    // I1& operator=(I1 &&other) noexcept;
    virtual int call1();

  protected:
  private:
  };

};