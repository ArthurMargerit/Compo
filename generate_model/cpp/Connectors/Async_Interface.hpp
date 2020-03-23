class {{NAME}}_{{ic.NAME}} :  public {{ic.D_NAME}} {
  public:
    // Constructor
    {{NAME}}_{{ic.NAME}}({{D_NAME}}& p_c): {{ic.NAME}}(), _c(p_c){}
    virtual ~{{NAME}}_{{ic.NAME}}(){}

    // Function ///////////////////////////////////////////////////////
    {%include "Connectors/Async_Interface_function.hpp" with context %}

    // get child
    {{D_NAME}}& _c;

    {{D_NAME}}& get__c() {
      return _c;
    }
};
