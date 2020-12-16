
#include "Structs/User_builder.hpp"
#include "Structs/User_fac.hpp"

User_builder::User_builder()

    :

      id(),

      first_name(),

      last_name(),

      score(),

      profile_img()

{}
User_builder::~User_builder() {}

User_builder &User_builder::set_id(const i32 &p_id) {
  this->id = p_id;
  return *this;
}

User_builder &
User_builder::set_first_name(const CompoMe::String &p_first_name) {
  this->first_name = p_first_name;
  return *this;
}

User_builder &User_builder::set_last_name(const CompoMe::String &p_last_name) {
  this->last_name = p_last_name;
  return *this;
}

User_builder &User_builder::set_score(const double &p_score) {
  this->score = p_score;
  return *this;
}

User_builder &User_builder::set_profile_img(const File &p_profile_img) {
  this->profile_img = p_profile_img;
  return *this;
}

void User_builder::asign(User &p_User) {

  p_User.set_id(this->id);
  p_User.set_first_name(this->first_name);
  p_User.set_last_name(this->last_name);
  p_User.set_score(this->score);
  p_User.set_profile_img(this->profile_img);
}

User User_builder::build() {
  User p_this;
  this->asign(p_this);
  return p_this;
}

User *User_builder::build_p() {
  User *p_this = new User();
  this->asign(*p_this);
  return p_this;
}

std::shared_ptr<User> User_builder::build_sp() {
  auto p_this = std::make_shared<User>();
  this->asign(*p_this);
  return p_this;
}
