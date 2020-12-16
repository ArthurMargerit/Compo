#include "Structs/User.hpp"

// GET SET ////////////////////////////////////////////////////////////////////

// get/set id
i32 User::get_id() const { return this->id; }

void User::set_id(const i32 &p_id) { this->id = p_id; }

i32 &User::a_id() { return this->id; }

// get/set first_name
CompoMe::String User::get_first_name() const { return this->first_name; }

void User::set_first_name(const CompoMe::String &p_first_name) {
  this->first_name = p_first_name;
}

CompoMe::String &User::a_first_name() { return this->first_name; }

// get/set last_name
CompoMe::String User::get_last_name() const { return this->last_name; }

void User::set_last_name(const CompoMe::String &p_last_name) {
  this->last_name = p_last_name;
}

CompoMe::String &User::a_last_name() { return this->last_name; }

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
