#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Math/Math.hpp"


namespace Math_P{

  class Math_P;

  class  Math_m : public ::Math
  {
  public:

    Math_P* composant;

    //! Default constructor
    Math_m(Math_P* comp);

    //! Destructor
    virtual ~Math_m() noexcept;

    Math_m() = delete;
    //! Copy constructor
    Math_m(const Math_m &other)=delete;
    //! Move constructor
    Math_m(Math_m &&other) = delete;
    // //! Copy assignment operator
    // Math& operator=(const Math &other)=delete;
    // //! Move assignment operator
    // Math& operator=(Math &&other) noexcept;
    virtual int add(int a,int b);
    virtual int time(int a,int b);
    virtual int sub(int a,int b);
    virtual int div(int a,int b);
    virtual int power(int a,int b);
    virtual int mod(int a,int b);

  protected:
  private:
  };

};