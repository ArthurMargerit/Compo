#include "Data/Types.hpp"

#include "Data/Struct_Tree.hpp"

#include <ostream>
#include <istream>

std::ostream& operator<<(std::ostream& os, const Tree&  c)
{
  os << "{"
     << "g:"<< c.g<<","
     << "d:"<< c.d<<","
     << "e:"<< c.e
     << "}";
  return os;
}


std::istream& operator>>(std::istream& is, Tree& c)
{
  is.ignore(100, '{');
  is.ignore(100, ':') >> c.g ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.d ;is.ignore(1, ',');
  is.ignore(100, ':') >> c.e ;
  is.ignore(1, '}');

  return is;
}


  Tree::Tree(pTree p_g,pTree p_d,pTree p_e)
  :
    g(p_g),
    d(p_d),
    e(p_e)
  {

  }


  Tree::Tree()
  :
    g(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
    d(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
    e(
/*WARNING NO DEFAULT VALUE FOR THIS TYPE*/)
  {
  }
pTree
Tree::get_g() const {
    return this->g;
 }

void
Tree::set_g(const pTree value) {
  this->g = value;
}
pTree
Tree::get_d() const {
    return this->d;
 }

void
Tree::set_d(const pTree value) {
  this->d = value;
}
pTree
Tree::get_e() const {
    return this->e;
 }

void
Tree::set_e(const pTree value) {
  this->e = value;
}

