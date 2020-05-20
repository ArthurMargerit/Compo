// #pragma once

// #include <map>
// #include <functional>
// #include <istream>
// #include <memory>

// {%include "helper/namespace_open.hpp" with context%} 
// struct {{NAME}};

// class {{NAME}}_fac
// {
//  public:
//  using Build_fac_f = std::function<{{D_NAME}}*(const std::string&, std::istream&)>;
//  using Build_fac_f_sp = std::function<std::shared_ptr<{{D_NAME}}>(const std::string&, std::istream&)>;

//  static
//  {{NAME}}_fac& get_inst() {
//    static {{NAME}}_fac inst;
//    return inst;
//  }

//  {{D_NAME}}* build(const std::string& p_type, std::istream& p);
//  std::shared_ptr<{{D_NAME}}> build_sp(const std::string& p_type, std::istream& p);

//  void init();

//  void subscribe(const std::string& ss, Build_fac_f v, Build_fac_f_sp);

//  private:
//  {{NAME}}_fac();
//  virtual ~{{NAME}}_fac();

//  std::map<std::string,std::pair<Build_fac_f,Build_fac_f_sp>> childs;
// };

// {%include "helper/namespace_close.hpp" with context%} 
