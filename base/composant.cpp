
#include <iostream>

#include "{{NAME}}/{{NAME}}.hpp"

namespace {{NAME}}{

  {{NAME}}::{{NAME}}()
                      {
                        std::cout << "--CONST : {{NAME}}" << std::endl;
                        return;
                      }

  //! Copy constructor
  {{NAME}}::{{NAME}}(const {{NAME}} &other)
                      {
                        std::cout << "--CPCT  : {{NAME}}" << std::endl;  
                        return;
                      }

  //! Move constructor
  {{NAME}}::{{NAME}}({{NAME}} &&other) noexcept
                      {
                        std::cout << "--MVCT  : {{NAME}}" << std::endl;  
                        return;
                      }

  //! Destructor
  {{NAME}}::~{{NAME}}() noexcept
                       {
                         std::cout << "--DEST  : {{NAME}}" << std::endl;
                         return;
                       }

  //! Copy assignment operator
  {{NAME}}& {{NAME}}::operator=(const {{NAME}} &other)
                        {


                        }

  //! Move assignment operator
  {{NAME}}& {{NAME}}::operator=({{NAME}} &&other) noexcept
                        {


                        }


  void {{NAME}}::configuration()
                   {
                     std::cout << "--CONF  : {{NAME}}" << std::endl;
                     return;
                   }

  void {{NAME}}::connection()
                   {
                     std::cout << "--CONECT: {{NAME}}" << std::endl;
                     return;
                   }

  void {{NAME}}::start()
                   {
                     std::cout << "--START : {{NAME}}" << std::endl;
                     return;
                   }

  void {{NAME}}::stop()
                   {
                     std::cout << "--STOP  : {{NAME}}" << std::endl;
                     return;
                   }

  void {{NAME}}::status()
                   {
                     std::cout << "--STATUS: {{NAME}}" << std::endl;
                     return;
                   }
}
