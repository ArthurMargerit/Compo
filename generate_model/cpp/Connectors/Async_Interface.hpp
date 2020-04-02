class {{NAME}}_{{ic.NAME}}:  public {{ic.D_NAME}} {
  public:
    // Constructor
  {{NAME}}_{{ic.NAME}}({{D_NAME}}* p_c);
  virtual ~{{NAME}}_{{ic.NAME}}();

  {{D_NAME}}& get_c();

  // Function ///////////////////////////////////////////////////////
  {%include "Connectors/Async_Interface_function.hpp" with context %}

 private:
    // get child
    {{D_NAME}}* _c;
};
