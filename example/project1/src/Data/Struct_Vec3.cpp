#include "Data/Struct_Vec3.hpp"
#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Vec3 *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, Vec3 *&c) {
  std::string t = get_type(is);
  if (t != "Vec3"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <Vec3>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Vec3 &c) {
  os << "{"
     << "type:"
     << "Vec3,"
     << "x:" << c.x << ","
     << "y:" << c.y << ","
     << "z:" << c.z << "}";
  return os;
}

std::istream &operator>>(std::istream &is, Vec3 &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "Vec3") {
    std::cerr << "ERREUR TYPE:"
              << ">Vec3< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.x;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.y;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.z;
  is.ignore(1, '}');

  return is;
}

Vec3::Vec3(double p_x, double p_y, double p_z) : x(p_x), y(p_y), z(p_z) {}

Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}
double Vec3::get_x() const { return this->x; }

void Vec3::set_x(const double value) { this->x = value; }
double Vec3::get_y() const { return this->y; }

void Vec3::set_y(const double value) { this->y = value; }
double Vec3::get_z() const { return this->z; }

void Vec3::set_z(const double value) { this->z = value; }

void Vec3::to_stream(std::ostream &os) const { os << *this; }