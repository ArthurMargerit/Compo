{% set i  = MAIN.INTERFACES[INTERFACE] %}
{% set im  = MAIN.INTERFACES[INTERFACE_MANY] %}

#include "Interfaces/{{i.NAME}}/{{i.NAME}}.hpp"
#include "Interfaces/{{im.NAME}}/{{im.NAME}}.hpp"

#include <vector>

class {{NAME}} {
 public:

   class {{NAME}}_{{im.NAME}} :  public {{im.NAME}} {
  public:

    {{NAME}}_{{im.NAME}}({{NAME}}& p_c): {{im.NAME}}(), _c(p_c){}
    virtual ~{{NAME}}_{{im.NAME}}(){}

    {%for f in im.FUNCTION %}
    //--> {{f.NAME}} >--//
    virtual
    {{f.RETURN.NAME}} {{f.NAME}} (
      {%- for p in f.SIGNATURE -%}
      {{p.TYPE.NAME}} {{p.NAME}}{% if not loop.last %},{%endif%}
      {%- endfor -%}) {

      {%- for p in f.SIGNATURE -%}
      unsigned int l_{{p.NAME}}_size = {{p.NAME}}.size();
      {% endfor %}

      {%if f.RETURN.NAME == "void" %}
      for(unsigned int i = 0; i < this->get__c().list_r.size(); i++) {
        this->get__c().list_r[i]->{{f.NAME}}({%- for p in f.SIGNATURE -%}
           {{p.NAME}}[i%l_{{p.NAME}}_size]{% if not loop.last %},{%endif%}{%- endfor -%});
      }
      return;

      {%else%}
      {{f.RETURN.NAME}} l_ret;
      for(unsigned int i = 0; i < this->get__c().list_r.size(); i++) {
      l_ret.push_back(
                      this->get__c().list_r[i]->{{f.NAME}}({%- for p in f.SIGNATURE -%}
       {{p.NAME}}[i%l_{{p.NAME}}_size]{% if not loop.last %},{%endif%}
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
  {{NAME}}_{{im.NAME}} c;
};
