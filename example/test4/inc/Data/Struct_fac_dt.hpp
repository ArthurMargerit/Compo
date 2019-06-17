#pragma once

#include <map>
#include <functional>
#include <istream>
#include <ostream>

class dt;

class dt_fac
{
 public:
 using Build_fac_f = std::function<dt*(const std::string&, std::istream&)>;

 static
 dt_fac& get_inst() {
   static dt_fac inst;
   return inst;
 }

 dt* build(const std::string& p_type, std::istream& p);

 void init();

 void subscribe(const std::string& ss, Build_fac_f v);
 private:
 dt_fac();
 virtual ~dt_fac();
 std::map<std::string,Build_fac_f> childs;

};

std::ostream& operator<<(std::ostream& os, const dt* c);
std::istream& operator>>(std::istream& os,dt*& c);