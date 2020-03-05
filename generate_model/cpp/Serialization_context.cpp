#include "Serialization_context.hpp"

#include "Data/Struct.hpp"
#include "Data/Struct_fac.hpp"
#include <algorithm>
#include <iostream>

Serialization_context::Serialization_context() {
  this->ext2local[NULL] = NULL;
  this->declare_ext.push_back(NULL);
}

Serialization_context::~Serialization_context() {}

void Serialization_context::inscribe(void *p_ext, Struct *p_loc) {
  if (this->is_inscribe(p_ext)) {
    throw "Double inscribe";
  }

  this->ext2local[p_ext] = p_loc;
  if (is_wanted_loc(p_ext)) {

    for (auto &at : this->want_loc[p_ext]) {
      *at = p_loc;
    }

    this->want_loc.erase(p_ext);
  }
}

bool Serialization_context::is_inscribe(void *p_ext) {
  auto f = this->ext2local.find(p_ext);
  return f != this->ext2local.end();
}

void Serialization_context::get_loc(void *p_ext, Struct *&p_at) {
  if (is_inscribe(p_ext)) {
    p_at = this->ext2local[p_ext];
    return;
  }

  return this->want_loc[p_ext].push_back(&p_at);
}

void Serialization_context::declare(const Struct *p_ext) {
  if (this->is_declare(p_ext)) {
    throw "Double declaration";
  }

  if (this->is_wanted(p_ext)) {
    this->declare_want.erase(std::remove(this->declare_want.begin(),
                                         this->declare_want.end(), p_ext),
                             this->declare_want.end());
  }

  this->declare_ext.push_back(p_ext);
}

bool Serialization_context::is_declare(const Struct *p_ext) {
  auto f = std::find(this->declare_ext.begin(), this->declare_ext.end(), p_ext);
  return f != this->declare_ext.end();
}

bool Serialization_context::is_wanted(const Struct *p_ext) {
  auto f =
      std::find(this->declare_want.begin(), this->declare_want.end(), p_ext);
  return f != this->declare_want.end();
}

bool Serialization_context::is_wanted_loc(void *p_ext) {
  auto f = this->want_loc.find(p_ext);
  return f != this->want_loc.end();
}

void Serialization_context::want(const Struct *t) {
  if (NULL == t || this->is_declare(t)) {
    return;
  }

  this->declare_want.push_back(t);
}

void Serialization_context::export_wanted(std::ostream &os) {
  while (this->declare_want.size() != 0) {
    (*this->declare_want.begin())->to_stream(os, *this);
  }
}

std::string get_type(std::istream &is) {
  int tg = is.tellg();

  while (is.peek() != '{') {
    std::cerr << "error not a type" + is.get();
  }
  is.get();

  while (is.peek() != '}') {
    auto k = get_word(is, {':', '}'});
    is.get();
    auto s = get_word(is, {',', '}'});
    is.get();

    if (k.first == "type") {
      is.seekg(tg);
      return s.first;
    }
  }

  is.seekg(tg);
  return "None1";
}

void Serialization_context::import_wanted(std::istream &is) {
  while (this->want_loc.size() != 0) {
    std::string t = get_type(is);
    std::cout << "-> " << t << "\n";
    Struct_fac::get_inst().build(t, is, *this);
  }
  return;
}
