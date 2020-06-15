#include "Data/User.hpp"
#include "Data/User_fac.hpp"
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

User::User() : User(int(), string(), string(), double(), File()) {}

User::User(int p_id, string p_first_name, string p_last_name, double p_score,
           File p_profile_img)
    : Struct(), id(p_id)

      ,
      first_name(p_first_name)

      ,
      last_name(p_last_name)

      ,
      score(p_score)

      ,
      profile_img(p_profile_img) {}

User::~User() {}

// GET SET ////////////////////////////////////////////////////////////////////
// get/set id
int User::get_id() const { return this->id; }

void User::set_id(const int &p_id) { this->id = p_id; }

int &User::a_id() { return this->id; }
// get/set first_name
string User::get_first_name() const { return this->first_name; }

void User::set_first_name(const string &p_first_name) {
  this->first_name = p_first_name;
}

string &User::a_first_name() { return this->first_name; }
// get/set last_name
string User::get_last_name() const { return this->last_name; }

void User::set_last_name(const string &p_last_name) {
  this->last_name = p_last_name;
}

string &User::a_last_name() { return this->last_name; }
// get/set score
double User::get_score() const { return this->score; }

void User::set_score(const double &p_score) { this->score = p_score; }

double &User::a_score() { return this->score; }
// get/set profile_img
File User::get_profile_img() const { return this->profile_img; }

void User::set_profile_img(const File &p_profile_img) {
  this->profile_img = p_profile_img;
}

File &User::a_profile_img() { return this->profile_img; }

// FUNCTION ///////////////////////////////////////////////////////////////////
// from User

// GENERATE CODE //////////////////////////////////////////////////////////////
// operator
bool User::operator==(const User &other) const {
  return true

         && this->id == other.id

         && this->first_name == other.first_name

         && this->last_name == other.last_name

         && this->score == other.score

         && this->profile_img == other.profile_img;
}

bool User::operator!=(const User &other) const { return !(*this == other); }
