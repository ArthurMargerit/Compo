
class {{NAME}}_{{i.NAME}} :  public {{i.D_NAME}} {
 private:
  {{NAME}}* a_c;

 public:
  {{NAME}}_{{i.NAME}}({{D_NAME}}* p_lo = NULL);

  // FUNCTION ///////////////////////////////////////////////////////////////
  {% include "Connectors/Logger_Interface_function.hpp" with context %}

  // GET/SET ////////////////////////////////////////////////////////////////
  {% include "Connectors/Logger_Interface_get_set.hpp" with context %}

  // INTERNAL
  {{D_NAME}}& get_c() const;
};
