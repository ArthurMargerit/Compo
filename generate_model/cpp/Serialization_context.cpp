#include "Serialization_context.hpp"

#include "Data/Struct.hpp"
#include "Errors/Error.hpp"
#include "Components/Component.hpp"
#include "Data/Struct_fac.hpp"
#include <algorithm>
#include <iostream>

void *to_pointer(std::shared_ptr<Struct> ptr) {
  std::stringstream ss;
  ss << ptr.get();
  void *r;
  ss >> r;
  return r;
}

std::string get_type(std::istream &is) {
  int tg = is.tellg();

  while (is.peek() != '{') {
    std::cerr << "wrong start: '" << (char)is.get() << "'";
    return "None";
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
  return "None";
}

std::string get_addr(std::istream &is) {
  int tg = is.tellg();

  while (is.peek() != '{') {
    std::cerr << "wrong start: '" << (char)is.get() << "'";
    return "None";
  }
  is.get();

  while (is.peek() != '}') {
    auto k = get_word(is, {':', '}'});
    is.get();
    auto s = get_word(is, {',', '}'});
    is.get();

    if (k.first == "addr") {
      is.seekg(tg);
      return s.first;
    }
  }

  is.seekg(tg);
  return "None";
}

///////////////////////////////////////////////////////////////////////////////
//                        SERIALIZATION IMPORT CONTEXT                       //
///////////////////////////////////////////////////////////////////////////////
Serialization_context_import::Serialization_context_import() {
  this->ext2local[NULL] = {nullptr, nullptr};
}

Serialization_context_import::~Serialization_context_import() {}

void Serialization_context_import::inscribe(void *p_ext, Struct *p_loc) {
  // if (this->is_inscribe(p_ext)) {
  //   throw "Double inscribe";
  // }

  this->ext2local[p_ext] = {p_loc, nullptr};
  if (is_wanted_loc(p_ext)) {

    for (auto &at : this->want_loc[p_ext]) {
      *at = p_loc;
    }

    this->want_loc.erase(p_ext);
  }

  if (is_wanted_loc_sp(p_ext)) {
    std::shared_ptr<Struct> l_sp(p_loc);
    this->ext2local[p_ext].second = l_sp;
    for (auto &at : this->want_loc_sp[p_ext]) {
      *at = l_sp;
    }

    this->want_loc_sp.erase(p_ext);
  }
}

bool Serialization_context_import::is_inscribe(void *p_ext) {
  auto f = this->ext2local.find(p_ext);
  return f != this->ext2local.end();
}

void Serialization_context_import::get_loc(void *p_ext, Struct *&p_at) {
  if (is_inscribe(p_ext)) {
    p_at = this->ext2local[p_ext].first;
    return;
  }

  this->want_loc[p_ext].push_back(&p_at);
  return;
}

void Serialization_context_import::get_loc(void *p_ext,
                                           std::shared_ptr<Struct> &p_at) {
  if (is_inscribe(p_ext)) {
    if (this->ext2local[p_ext].second == nullptr) {
      std::shared_ptr<Struct> l_sp(this->ext2local[p_ext].first);
      this->ext2local[p_ext].second = l_sp;
    }
    p_at = this->ext2local[p_ext].second;
    return;
  }

  this->want_loc_sp[p_ext].push_back(&p_at);
  return;
}

bool Serialization_context_import::is_wanted_loc(void *p_ext) {
  auto f = this->want_loc.find(p_ext);
  return f != this->want_loc.end();
}

bool Serialization_context_import::is_wanted_loc_sp(void *p_ext) {
  auto f = this->want_loc_sp.find(p_ext);
  return f != this->want_loc_sp.end();
}

void Serialization_context_import::import_wanted(std::istream &is) {
  while (this->want_loc.size() != 0 || this->want_loc_sp.size() != 0) {
    std::string t = get_type(is);
    Struct_fac::get_inst().build(t, is, *this);
  }
  return;
}

///////////////////////////////////////////////////////////////////////////////
//                        SERIALIZATION EXPORT CONTEXT                       //
///////////////////////////////////////////////////////////////////////////////
Serialization_context_export::Serialization_context_export() {
  this->declare_ext_s.push_back(NULL);
  this->declare_ext_c.push_back(NULL);
}

Serialization_context_export::~Serialization_context_export() {}

void Serialization_context_export::want(const Struct *p_s) {
  if (nullptr == p_s || this->is_declare(p_s)) {
    return;
  }

  this->declare_want_s.push_back(p_s);
}

void Serialization_context_export::want(const Error *p_e) {
  if (nullptr == p_e || this->is_declare(p_e)) {
    return;
  }

  this->declare_want_e.push_back(p_e);
}

void Serialization_context_export::want(const Component *p_c) {
  if (nullptr == p_c || this->is_declare(p_c)) {
    return;
  }

  this->declare_want_c.push_back(p_c);
}

void Serialization_context_export::export_wanted(std::ostream &os) {
  while (this->declare_want_s.size() != 0 || this->declare_want_c.size() != 0 || this->declare_want_e.size() != 0) {
    if (this->declare_want_c.size() != 0) {
      (*this->declare_want_c.begin())->to_stream(os, *this);
      continue;
    }

    if (this->declare_want_s.size() != 0) {
      (*this->declare_want_s.begin())->to_stream(os, *this);
      continue;
    }

    if (this->declare_want_e.size() != 0) {
      (*this->declare_want_e.begin())->to_stream(os, *this);
      continue;
    }
  }
}

bool Serialization_context_export::is_declare(const Struct *p_ext) {
  auto f =
      std::find(this->declare_ext_s.begin(), this->declare_ext_s.end(), p_ext);
  return f != this->declare_ext_s.end();
}

bool Serialization_context_export::is_declare(const Error *p_e) {
  auto f =
    std::find(this->declare_ext_e.begin(), this->declare_ext_e.end(), p_e);
  return f != this->declare_ext_e.end();
}

bool Serialization_context_export::is_declare(const Component *p_c) {
  auto f =
      std::find(this->declare_ext_c.begin(), this->declare_ext_c.end(), p_c);
  return f != this->declare_ext_c.end();
}

bool Serialization_context_export::is_wanted(const Struct *p_ext) {
  auto f = std::find(this->declare_want_s.begin(), this->declare_want_s.end(),
                     p_ext);
  return f != this->declare_want_s.end();
}

bool Serialization_context_export::is_wanted(const Error *p_e) {
  auto f = std::find(this->declare_want_e.begin(), this->declare_want_e.end(),
                     p_e);
  return f != this->declare_want_e.end();
}

bool Serialization_context_export::is_wanted(const Component *p_c) {
  auto f =
      std::find(this->declare_want_c.begin(), this->declare_want_c.end(), p_c);
  return f != this->declare_want_c.end();
}

void Serialization_context_export::declare(const Struct *p_s) {

  if (this->is_wanted(p_s)) {
    this->declare_want_s.erase(std::remove(this->declare_want_s.begin(),
                                           this->declare_want_s.end(), p_s),
                               this->declare_want_s.end());
  }

  this->declare_ext_s.push_back(p_s);
}

void Serialization_context_export::declare(const Error *p_e) {

  if (this->is_wanted(p_e)) {
    this->declare_want_e.erase(std::remove(this->declare_want_e.begin(),
                                           this->declare_want_e.end(), p_e),
                               this->declare_want_e.end());
  }

  this->declare_ext_e.push_back(p_e);
}

void Serialization_context_export::declare(const Component *p_c) {

  if (this->is_wanted(p_c)) {
    this->declare_want_c.erase(std::remove(this->declare_want_c.begin(),
                                           this->declare_want_c.end(), p_c),
                               this->declare_want_c.end());
  }

  this->declare_ext_c.push_back(p_c);
}
