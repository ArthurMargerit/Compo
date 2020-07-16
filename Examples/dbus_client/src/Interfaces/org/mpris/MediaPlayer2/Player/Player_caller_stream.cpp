
#include "Interfaces/org/mpris/MediaPlayer2/Player/Player_caller_stream.hpp"
#include "Errors/Error.hpp"

#include "Interfaces/Function_stream_recv.hpp"
#include "Interfaces/Return_stream_send.hpp"

namespace org {

namespace mpris {

namespace MediaPlayer2 {

constexpr unsigned int str2int(const char *str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

Player_caller_stream::Player_caller_stream(Player &pcomp)
    : Caller_stream(), comp(pcomp) {
  return;
}

bool Player_caller_stream::call(CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {
  is.pull();
  os.start();

  std::string name_function;
  std::getline(is.get_si(), name_function, '(');
  bool b = this->call(name_function, is, os);

  is.end();
  os.send();
  return b;
}

bool Player_caller_stream::call(std::string &name_function,
                                CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {
  bool result = false;

  switch (str2int(name_function.c_str())) {

  case str2int("Next"):
    result = this->Next(is, os);
    break;

  case str2int("Previous"):
    result = this->Previous(is, os);
    break;

  case str2int("PlayPause"):
    result = this->PlayPause(is, os);
    break;

  case str2int("Play"):
    result = this->Play(is, os);
    break;

  case str2int("Pause"):
    result = this->Pause(is, os);
    break;

  case str2int("OpenUri"):
    result = this->OpenUri(is, os);
    break;

  case str2int("Seek"):
    result = this->Seek(is, os);
    break;

  case str2int("Stop"):
    result = this->Stop(is, os);
    break;
  };

  return result;
}

bool Player_caller_stream::Next(CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.Next();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Player_caller_stream::Previous(CompoMe::Function_stream_recv &is,
                                    CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.Previous();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Player_caller_stream::PlayPause(CompoMe::Function_stream_recv &is,
                                     CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.PlayPause();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Player_caller_stream::Play(CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.Play();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Player_caller_stream::Pause(CompoMe::Function_stream_recv &is,
                                 CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.Pause();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Player_caller_stream::OpenUri(CompoMe::Function_stream_recv &is,
                                   CompoMe::Return_stream_send &os) {

  string l_Uri;
  is >> l_Uri;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.OpenUri(l_Uri);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Player_caller_stream::Seek(CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {

  i64 l_offset;
  is >> l_offset;

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.Seek(l_offset);

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

bool Player_caller_stream::Stop(CompoMe::Function_stream_recv &is,
                                CompoMe::Return_stream_send &os) {

  char _l = is.get();
  if (_l != ')') {
    return false;
  }

  try {

    this->comp.Stop();

  } catch (const CompoMe::Error &e) {
    os << "!" << &e;
  }

  return true;
}

} // namespace MediaPlayer2

} // namespace mpris

} // namespace org
