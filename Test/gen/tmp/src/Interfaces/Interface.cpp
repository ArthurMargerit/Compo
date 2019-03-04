#include "Interfaces/Interface.hpp"

Interface::Interface() {

}

Interface::~Interface() {

}


std::function<Interface*(std::ostream&,std::istream&)> build_fake(Interface* t)
{
  std::cout <<  "ERROR the type of Interface t pointer need to be know"<< "\n";
}