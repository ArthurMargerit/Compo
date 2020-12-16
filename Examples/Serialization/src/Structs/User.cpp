#include "Structs/User.hpp"
#include "Structs/User_fac.hpp"

#include <istream>
#include <ostream>
#include <sstream>

User::User()
    : User(i32(), CompoMe::String(), CompoMe::String(), double(), File()) {}

User::User(i32 p_id, CompoMe::String p_first_name, CompoMe::String p_last_name,
           double p_score, File p_profile_img)
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
