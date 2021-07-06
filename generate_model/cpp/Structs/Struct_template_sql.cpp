
#include "Structs/{{F_NAME}}_sql.hpp"
#include <sstream>
{% for a in OPTIONS.SQL_FK %}
  {% set fk_d = DATA | selectattr("NAME", "equalto", a) | list | first %}
#include "Structs/{{fk_d.TYPE.F_NAME}}_sql.hpp"
{% endfor %}

{%include "helper/namespace_open.hpp" with context %}

{{NAME}}_sql::{{NAME}}_sql({{D_NAME}} & p_data):element(p_data){}

{{NAME}}_sql::~{{NAME}}_sql(){}

std::string {{NAME}}_sql::get_all() {
  std::stringstream ss;
  ss << "SELECT " << get_select_header("{{OPTIONS.SQL_TABLE}}")<< " FROM {{OPTIONS.SQL_TABLE}} " << {{NAME}}_sql::get_select_join() ;
  return ss.str();
}

// select * from With_ext_key INNER JOIN With_key wk1 ON wk1.id = With_ext_key.k1 INNER JOIN With_key wk2 ON wk2.id = With_ext_key.k2;

std::string {{NAME}}_sql::get_select_join(std::string prefix) {
  std::stringstream ss;

  {% for a in OPTIONS.SQL_FK %}
  {% set fk_d = DATA | selectattr("NAME", "equalto", a) | list | first %}
  ss << " INNER JOIN {{fk_d.TYPE.OPTIONS.SQL_TABLE}} AS " << prefix << "{{a}}_table ON "<< prefix<<"{{a}}_table.{{fk_d.TYPE.OPTIONS.SQL_PK}} = " << ((prefix=="")?("{{OPTIONS.SQL_TABLE}}"):(prefix+"table"))<<".{{a}}"
    {% if fk_d.TYPE.OPTIONS.SQL_FK %}
    << {{fk_d.TYPE.D_NAME}}_sql::get_select_join("{{a}}_")
    {% endif %};
  {% endfor %}
  return ss.str();
}
std::string {{NAME}}_sql::get_select_header(std::string prefix, bool add_as, std::string prefix_as, bool first) {
  std::stringstream ss;
  ss
  {% for d in DATA %}
    {% if "SQL_FK" in OPTIONS and d.NAME in OPTIONS.SQL_FK %}
      {% set fk_d = DATA | selectattr("NAME", "equalto", d.NAME) | list | first %}
        << {{d.TYPE.NAME}}_sql::get_select_header(((!first)?prefix:"")+"{{d.NAME}}_",
                                                  true, prefix_as+"{{d.NAME}}__", false)
    {% else %}
      << prefix << ((!first)?"table.":".") <<"{{d.NAME}}" << ((add_as)?" as "+prefix_as+"{{d.NAME}}":"")
    {% endif %}

    {%if not loop.last%} << ","{%endif%}
  {%endfor%};
  return ss.str();
}

std::string  {{NAME}}_sql::get_table() {
  std::stringstream ss;
  ss << "CREATE TABLE {{OPTIONS.SQL_TABLE}} ("
  {%- for d in DATA -%}
  {% if not loop.first%}<< ","{% endif %}

  {% if not Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
    {% if "SQL_TYPE" in d.TYPE.OPTIONS %}
      {% if d.TYPE.OPTIONS.SQL_TYPE in ["INT","BIGINT"] and  "SQL_PK" in OPTIONS and (d.NAME == OPTIONS.SQL_PK or d.NAME in OPTIONS.SQL_PK ) %}
        << "{{d.NAME}} serial"
      {% else %}
        << "{{d.NAME}} {{d.TYPE.OPTIONS.SQL_TYPE}} {{d.TYPE.OPTIONS.SQL_OPTIONS}}"
      {% endif %}
    {% else %}
      // -> {{d.TYPE}}
    {% endif %}
  {% else %}
    {% if d.TYPE.OPTIONS.SQL == true %}
      << "{{d.NAME}} serial"
    {% endif %}
  {% endif %}
  {% endfor -%}

  {% if "SQL_PK" in OPTIONS %} << ",PRIMARY KEY ( {{OPTIONS.SQL_PK}})"  {% endif %}
  {% if "SQL_FK" in OPTIONS %}
  {%- for fk in  OPTIONS.SQL_FK-%}
  {% set fk_d = DATA | selectattr("NAME", "equalto", fk) | list | first %}
    << ",FOREIGN KEY ({{fk}}) REFERENCES {{fk_d.TYPE.OPTIONS.SQL_TABLE}}({{fk_d.TYPE.OPTIONS.SQL_PK}}) ON DELETE CASCADE"
   {%- endfor -%}
  {% endif %}
  << ");";
  return ss.str();
}

 std::string  {{NAME}}_sql::get_by_id(unsigned int id) {
   std::stringstream ss;
   ss << "SELECT ({% for d in DATA %}{{d.NAME}}{%if not loop.last%},{%endif%}{%endfor%}) from {{OPTIONS.SQL_TABLE}} WHERE {{OPTIONS.SQL_PK}} == " << id <<";" ;
   return ss.str();
}

std::string {{NAME}}_sql::get_delete() {
  std::stringstream ss;
  ss << "DELETE from {{OPTIONS.SQL_TABLE}} where {{OPTIONS.SQL_PK}} = " << this->element.a_{{OPTIONS.SQL_PK}}() <<" ;";
  return ss.str();
}

std::string {{NAME}}_sql::get_insert_with() {
  std::stringstream ss;

  {% for a in OPTIONS.SQL_FK %}

  {% set fk_d = DATA | selectattr("NAME", "equalto", a) | list | first %}
  {{fk_d.TYPE.D_NAME}}_sql l_{{fk_d.NAME}}(this->element.a_{{a}}());
  {%if fk_d.TYPE.OPTIONS.SQL_FK %}
  ss << l_{{fk_d.NAME}}.get_insert_with()<<",";
  {%endif%}
  ss << "{{a}}_tmp_view as ("
          << l_{{fk_d.NAME}}.get_insert(true,"{{a}}_id",false,false)
          << ")"  {% if not loop.last %} << ","{% endif %};
  {% endfor %}

  return ss.str();
}

std::string {{NAME}}_sql::get_insert(bool return_key , std::string key_name, bool add_semicol,bool add_with) {
  {# two situation #}

  std::stringstream ss;

  {% if OPTIONS.SQL_FK %}

  ss << ((add_with)?"WITH ":"") << ((add_with)?get_insert_with():"");

  ss << "INSERT INTO {{OPTIONS.SQL_TABLE}} " << get_insert_header() << " SELECT " << get_insert_data(false) <<" FROM {% for s in OPTIONS.SQL_FK %} {{s}}_tmp_view {% if not loop.last %},{% endif %}{%endfor%}";

  {%else%}
  ss << "INSERT INTO {{OPTIONS.SQL_TABLE}} " << get_insert_header() << " VALUES " << get_insert_data();
  {% endif %};

  if(return_key) {
    ss << "returning {{OPTIONS.SQL_PK}} as "<< key_name;
  }

  ss << ((add_semicol) ? ";" : "");

  return ss.str();
}

void {{NAME}}_sql::build(pqxx::row p_sql_result,std::string prefix){
  {% for d in DATA %}
  {% if "VARCHAR" == d.TYPE.OPTIONS.SQL_TYPE %}
  this->element.set_{{d.NAME}}(p_sql_result[prefix+"{{d.NAME}}"].as<std::string>());
  {% elif Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
  {
    {{d.TYPE.D_NAME}}_sql e(this->element.a_{{d.NAME}}());
    e.build(p_sql_result, prefix+"{{d.NAME}}__");
  }

  {%else%}
  this->element.set_{{d.NAME}}(p_sql_result[prefix+"{{d.NAME}}"].as<{{d.TYPE.NAME}}>());
  {% endif %}
  {%endfor%};
}

std::string  {{NAME}}_sql::get_insert_header() {
  std::stringstream ss;
  ss << "(" << {% for d in DATA %} {% if OPTIONS.SQL_PK != d.NAME %} "{{d.NAME}}" << {%if not loop.last%}","<<{%endif%}{%endif%}{%endfor%} ")";
  return ss.str();
}

std::string  {{NAME}}_sql::get_insert_data(bool add_backet){
  std::stringstream ss;
  ss << ((add_backet)?"(":"")
  {% for d in DATA %}
    {% if OPTIONS.SQL_PK != d.NAME %}
      {% if "VARCHAR" == d.TYPE.OPTIONS.SQL_TYPE %}
        << "'" << this->element.a_{{d.NAME}}().str << "'"
      {% elif Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
        << "{{d.NAME}}_id"
      {% else %}
        << this->element.a_{{d.NAME}}()
      {% endif %}
      {%if not loop.last%}<< "," {%endif%}
    {% endif %}
  {%endfor%}
  << ((add_backet)?")":"");

  return ss.str();
}

{%include "helper/namespace_close.hpp" with context %}
