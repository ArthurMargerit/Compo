{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set imr  = MAIN.INTERFACES[INTERFACE_MANY_RETURN] %}

#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{imr.NAME}}/{{imr.NAME}}.hpp"

#include <vector>
#include <random>

class {{NAME}} {
 public:

   class {{NAME}}_{{imr.NAME}} :  public {{imr.NAME}} {
  public:

    {{NAME}}_{{imr.NAME}}({{NAME}}& p_c): {{imr.NAME}}(), _c(p_c){}
    virtual ~{{NAME}}_{{imr.NAME}}(){}

    {%for f in imr.FUNCTION %}
    //--> {{f.NAME}} >--//
    virtual
    {{f.RETURN.NAME}} {{f.NAME}} (
      {%- for p in f.SIGNATURE -%}
      {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%}) {

      {%if f.RETURN.NAME == "void" %}
      for(auto& l_i : this->get__c().list_r) {
          l_i->{{f.NAME}}({%- for p in f.SIGNATURE -%}
           {{p.NAME}}{% if not loop.last %},{%endif%}{%- endfor -%});
      }
      return;
      {%else%}
      {{f.RETURN.NAME}} l_ret;
      for(auto& l_i : this->get__c().list_r){
      l_ret.push_back(
      l_i->{{f.NAME}}({%- for p in f.SIGNATURE -%}
       {{p.NAME}}{% if not loop.last %},{%endif%}
        {%- endfor -%}));
      }
      return l_ret;
      {%endif%}
    }
    {%endfor%}

    {{NAME}}& _c;
    {{NAME}}& get__c() {
      return this->_c;
    }
    {{NAME}}& get__c() const  {
      return this->_c;
    }
  };

  {{NAME}}():c(*this){}
  virtual ~{{NAME}}(){}
  std::vector<{{i.NAME}}*> list_r;
  {{NAME}}_{{imr.NAME}} c;
};
