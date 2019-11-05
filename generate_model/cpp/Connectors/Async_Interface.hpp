class {{NAME}}_{{ic.NAME}} :  public {{ic.NAME}} {
  public:
    // Constructor
    {{NAME}}_{{ic.NAME}}({{NAME}}& p_c): {{ic.NAME}}(), _c(p_c){}
    virtual ~{{NAME}}_{{ic.NAME}}(){}

    // Function ///////////////////////////////////////////////////////
    {%include "Connectors/Async_Interface_function.hpp" with context %}

    // get child
    {{NAME}}& _c;

    {{NAME}}& get__c() {
      return _c;
    }
};
