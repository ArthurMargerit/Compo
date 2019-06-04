#include "Data/Struct_Temperature_sample.hpp"
#include <iostream>

#include <istream>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const Temperature_sample *c) {
  os << (Struct *)c;
  return os;
}

std::istream &operator>>(std::istream &is, Temperature_sample *&c) {
  std::string t = get_type(is);
  if (t != "Temperature_sample"

      ) {
    std::cerr << "ERR: TYPE ERROR\n"
              << "\t" << t << " is not a <Temperature_sample>\n";
  }
  is >> (Struct *&)c;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Temperature_sample &c) {
  os << "{"
     << "type:"
     << "Temperature_sample,"
     << "val:" << c.val << ","
     << "pos:" << c.pos << ","
     << "place:" << c.place << "}";
  return os;
}

std::istream &operator>>(std::istream &is, Temperature_sample &c) {
  is.ignore(100, '{');
  std::string type;
  is.ignore(100, ':');
  std::getline(is, type, ',');
  if (type != "Temperature_sample") {
    std::cerr << "ERREUR TYPE:"
              << ">Temperature_sample< != >" << type << "<" << std::endl;
  }

  is.ignore(100, ':') >> c.val;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.pos;
  is.ignore(1, ',');
  is.ignore(100, ':') >> c.place;
  is.ignore(1, '}');

  return is;
}

Temperature_sample::Temperature_sample(double p_val, Vec3 p_pos, String p_place)
    : val(p_val), pos(p_pos), place(p_place) {}

Temperature_sample::Temperature_sample()
    : val(0.0), pos(
                    /*WARNING NO DEFAULT VALUE FOR THIS TYPE*/),
      place("UNDEF") {}
double Temperature_sample::get_val() const { return this->val; }

void Temperature_sample::set_val(const double value) { this->val = value; }
Vec3 Temperature_sample::get_pos() const { return this->pos; }

void Temperature_sample::set_pos(const Vec3 value) { this->pos = value; }
String Temperature_sample::get_place() const { return this->place; }

void Temperature_sample::set_place(const String value) { this->place = value; }

void Temperature_sample::to_stream(std::ostream &os) const { os << *this; }