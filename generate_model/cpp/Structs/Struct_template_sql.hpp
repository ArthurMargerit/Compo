#pragma once

#include "Structs/{{F_NAME}}.hpp"
#include <pqxx/pqxx>

{%include "helper/namespace_open.hpp" with context %}

class {{NAME}}_sql {
  {{D_NAME}} & element;

public:
  {{NAME}}_sql({{D_NAME}} & p_data);
  virtual ~{{NAME}}_sql();

  static std::string get_table();
  static std::string get_all();
  static std::string get_by_id(unsigned int id);
  static std::string get_select_header(std::string prefix="", bool add_as=false, std::string prefix_as="", bool first=true);
  static std::string get_select_join(std::string prefix="");
  std::string get_delete();

  // insert
  std::string get_insert(bool return_key = false , std::string key_name = "key", bool add_semicol = true,bool add_with = true);
  std::string get_update();
  std::string get_insert_header();
  std::string get_insert_with();
  std::string get_insert_data(bool add_backet = true);

  void build(pqxx::row p_sql_result, std::string prefix="");
};

{%include "helper/namespace_close.hpp" with context %}



