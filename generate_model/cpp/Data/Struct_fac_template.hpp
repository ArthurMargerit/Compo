#pragma once

#include <map>
#include <functional>
#include <istream>
#include <ostream>
#include <memory>

class {{NAME}};

class {{NAME}}_fac
{
 public:
 using Build_fac_f = std::function<{{NAME}}*(const std::string&, std::istream&)>;

 static
 {{NAME}}_fac& get_inst() {
   static {{NAME}}_fac inst;
   return inst;
 }

 {{NAME}}* build(const std::string& p_type, std::istream& p);

 void init();

 void subscribe(const std::string& ss, Build_fac_f v);
 private:
 {{NAME}}_fac();
 virtual ~{{NAME}}_fac();
 std::map<std::string,Build_fac_f> childs;

};

std::ostream& operator<<(std::ostream& os, const {{NAME}}* c);
std::istream& operator>>(std::istream& os,{{NAME}}*& c);
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<{{NAME}}> c);
std::istream& operator>>(std::istream& os, std::shared_ptr<{{NAME}}>& c);
