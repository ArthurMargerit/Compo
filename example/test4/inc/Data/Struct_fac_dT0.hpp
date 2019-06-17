#pragma once

#include <map>
#include <functional>
#include <istream>
#include <ostream>

class dT0;

class dT0_fac
{
 public:
 using Build_fac_f = std::function<dT0*(const std::string&, std::istream&)>;

 static
 dT0_fac& get_inst() {
   static dT0_fac inst;
   return inst;
 }

 dT0* build(const std::string& p_type, std::istream& p);

 void init();

 void subscribe(const std::string& ss, Build_fac_f v);
 private:
 dT0_fac();
 virtual ~dT0_fac();
 std::map<std::string,Build_fac_f> childs;

};

std::ostream& operator<<(std::ostream& os, const dT0* c);
std::istream& operator>>(std::istream& os,dT0*& c);