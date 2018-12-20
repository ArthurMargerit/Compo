#pragma once

#include "Data/Types.hpp"

#include "Interfaces/Math/Math.hpp"


namespace Math_provider{

  class Math_provider;

  class  Math_m : public ::Math
  {
  public:

    Math_provider* composant;

    //! Default constructor
    Math_m(Math_provider* comp);

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