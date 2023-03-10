#include "{{KIND}}/{{F_NAME}}.hpp"
#include "{{KIND}}/{{F_NAME}}_fac.hpp"

{%if PARENT %}
#include "{{KIND}}/{{PARENT.F_NAME}}_fac.hpp"
{%endif%}

#include <utility>
#include <string>
#include <cstdlib>

#include "CompoMe/Log.hpp"

{%include "helper/namespace_open.hpp" with context %}

{{NAME}}_fac::{{NAME}}_fac() {
  this->init();
}

{{NAME}}_fac::~{{NAME}}_fac() {}

{{D_NAME}}* {{NAME}}_fac::build(const std::string& p_type, std::istream& p_stream, CompoMe::Serialization_context_import& p_ctx) {

  if (p_type == "{{D_NAME}}") {
    // void* l_addr = get_addr(is);
    // if(p_ctx.is_share_ptr(l_addr)) {
    //   std::shared_ptr<{NAME}}> b = std::make_shared<{{NAME}}>();
    //   b->from_stream(p_stream, p_ctx);
    // } else {
      {{D_NAME}}* b = new {{D_NAME}}();
      b->from_stream(p_stream, p_ctx);
      //    }
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.first(p_type, p_stream, p_ctx);
  }

  C_ERROR("Error: of Serializable* build ", "Your type \"", p_type, "\" is not include or not init as a child.");

  return NULL;
}

std::shared_ptr<{{D_NAME}}> {{NAME}}_fac::build_sp(const std::string& p_type, std::istream& p_stream) {

  if (p_type == "{{D_NAME}}") {
    auto b =std::make_shared<{{D_NAME}}>();
    p_stream >> *b;
    return b;
  }

  // child build
  auto f = this->childs.find(p_type);
  if (f != this->childs.end()) {
    return f->second.second(p_type, p_stream);
  }

  C_ERROR("Error: of std::shared_ptr<{{D_NAME}}> build ",
          "Your type \"", p_type,
          "\" is not include or not init as a child.");

  return std::shared_ptr<{{D_NAME}}>();
}

void {{NAME}}_fac::init() {

    {%if PARENT %}
    {{PARENT.D_NAME}}_fac::Build_fac_f f = [](const std::string& str,std::istream& p_s, CompoMe::Serialization_context_import& l_ctx)
                                         {return dynamic_cast<{{PARENT.D_NAME}}*>({{D_NAME}}_fac::get_inst().build(str, p_s, l_ctx));};

    {{PARENT.D_NAME}}_fac::Build_fac_f_sp f_sp = [](const std::string& str,std::istream& p_s)
                                               {return {{D_NAME}}_fac::get_inst().build_sp(str,p_s);};

    {{PARENT.D_NAME}}_fac::get_inst().subscribe("{{D_NAME}}", f, f_sp);
    {%else%}
    CompoMe::Serializable_fac::Build_fac_f  f= [](const std::string& str,std::istream& p_s, CompoMe::Serialization_context_import& l_ctx)
                                               {return dynamic_cast<CompoMe::Serializable_Item*>({{NAME}}_fac::get_inst().build(str, p_s, l_ctx)); };
    CompoMe::Serializable_fac::Build_fac_f_sp  f_sp= [](const std::string& str,std::istream& p_s)
                                {return {{NAME}}_fac::get_inst().build_sp(str,p_s); };

    CompoMe::Serializable_fac::get_inst().subscribe("{{D_NAME}}", f, f_sp);
    {%endif%}
  }

void {{NAME}}_fac::subscribe(const std::string& ss, Build_fac_f v,Build_fac_f_sp v_sp) {

  this->childs[ss] = std::make_pair(v,v_sp);

  {%if PARENT %}
  {{PARENT.D_NAME}}_fac::get_inst().subscribe(ss, v, v_sp);
  {%else%}
  CompoMe::Serializable_fac::get_inst().subscribe(ss, v, v_sp);
  {%endif%}
 }
{%include "helper/namespace_close.hpp" with context %}
