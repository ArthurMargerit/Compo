#pragma once


template<typename TI>
class {{NAME}}:public Link
{

 public:

  {{NAME}} link(TI*& require, const std::string& provide_name, TI& provide, const std::string& provide_name)
             {
               return 
             }

  {{NAME}} link_require_to(const std::string& require, TI*& p, const std::string& provide_name)
             {


             }

  {{NAME}} link_from(const std::string& require, TI r, const std::string& provide_name)
             {

             }

  virtual std::string status()
  {
    return this->get_from() + " -(" + typeid({{NAME}}).name() + "<" + typeid({{TI}}).name() + ">)-> " + this->get_to();
  }


 private:
  //! Default constructor
  {{NAME}}()= delete;

  {{NAME}}(std::string to ,std::string from):Link(to, from)
            {
              
            };

  //! Destructor
  virtual ~{{NAME}}() noexcept
                     {
                     }

  //! Copy constructor
  {{NAME}}(const {{NAME}} &other) = delete;

  //! Move constructor
  {{NAME}}({{NAME}} &&other) noexcept = delete;

  //! Copy assignment operator
  {{NAME}}& operator=(const {{NAME}} &other) = delete;

  //! Move assignment operator
  {{NAME}}& operator=({{NAME}} &&other) noexcept = delete;

protected:
};

