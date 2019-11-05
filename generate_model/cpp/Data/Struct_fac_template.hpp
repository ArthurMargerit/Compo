#pragma once

#include <map>
#include <functional>
#include <istream>
#include <memory>

class {{NAME}};

class {{NAME}}_fac
{
 public:
 using Build_fac_f = std::function<{{NAME}}*(const std::string&, std::istream&)>;
 using Build_fac_f_sp = std::function<std::shared_ptr<{{NAME}}>(const std::string&, std::istream&)>;

 static
 {{NAME}}_fac& get_inst() {
   static {{NAME}}_fac inst;
   return inst;
 }

 {{NAME}}* build(const std::string& p_type, std::istream& p);
 std::shared_ptr<{{NAME}}> build_sp(const std::string& p_type, std::istream& p);

 void init();

 void subscribe(const std::string& ss, Build_fac_f v, Build_fac_f_sp v_sp);
 private:
 {{NAME}}_fac();
 virtual ~{{NAME}}_fac();
 std::map<std::string,std::pair<Build_fac_f,Build_fac_f_sp>> childs;

};

std::ostream& operator<<(std::ostream& os, const {{NAME}}* c);
std::istream& operator>>(std::istream& os,{{NAME}}*& c);
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<{{NAME}}>& c);
std::istream& operator>>(std::istream& os, std::shared_ptr<{{NAME}}>& c);
