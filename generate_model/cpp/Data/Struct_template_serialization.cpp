std::istream& {{NAME}}::from_stream(std::istream& is, Serialization_context& p_ctx) {
  {{NAME}} l_reset;
  *this = l_reset;

  char l_c = is.get();
  if(l_c != '{') {
    std::cerr << "Wrong start: '" <<  l_c << "' != '{'";
    throw "Wrong start: '"  "' != '{'";
  }

  std::string type_start;
  std::getline(is, type_start, ':');
  if (type_start != "type") {
    std::cerr << "wrong first args:"
              << "\"type\" != \"" << type_start << "\"" << std::endl;

    throw "Wrong first args: need \"type\" have \""+type_start+"\"";
  }

  auto pair_type = get_word(is, {',','}'});
    if (pair_type.first != "{{NAME}}") {
    std::cerr << "TYPE:"
              << "\"{{NAME}}\" != \"" << pair_type.first << "\"" << std::endl;
    throw "Wrong type: need \"{{NAME}}\" have \""+pair_type.first+"\"";
  }

  char l_c1 = is.get();
  if(l_c1 == '}' ) {
    {%if PARENT -%}
    throw "wrong miss parent";
    {%else%}
    return is;
    {%endif%}
  } else if(l_c1 != ',') {
    throw "Wrong separator: " + std::to_string(l_c1);
  }

  {%if PARENT -%}
  std::string parent;
  std::getline(is, parent, ':');
  if(parent != "parent"){
    std::cerr << "PARENT: no parent data in second position"<< std::endl;
    throw "Wrong type: need \"{{NAME}}\" have \""+pair_type.first+"\"";
  }

  is >> ({{PARENT.NAME}}&) *this;

  char l_c2 = is.get();
  if(l_c2 == '}') {
    return is;
  } else if (l_c2 != ',') {
    throw "Wrong separator: " + std::to_string(l_c2);
  }
  {%-endif%}

  {%if DATA %}
  do{
    std::string args;
    std::getline(is, args, ':');
    switch(str2int(args.c_str())) {
      {%- for d in DATA %}
    case str2int("{{d.NAME}}"):
      is >> this->{{d.NAME}};
      break;
      {%endfor%}
    default:
      std::cerr << "wrong attribute: \""<< args <<"\" not in {{NAME}}";
      throw "wrong attribute: \""+ args +"\" not in {{NAME}}";
      break;
    }

    l_c = is.get();
  }while(l_c == ',');

  if(l_c != '}') {
    std::cerr << "Wrong end: '"<< l_c <<"' != '}'" << std::endl;
    throw "Wrong end";
  }

  {%endif%}
  return is;
}

std::ostream& {{NAME}}::to_stream(std::ostream& os, Serialization_context& p_ctx) const {
  os << "{" ;
  os << "type:" <<"{{NAME}}";
  {%-if PARENT -%}
  os << "," << "parent:" << ({{PARENT.NAME}}) *this;
  {%-endif-%}
  {%- for d in DATA %}
  os << "," << "{{d.NAME}}:";
  {%if Function.model_test.is_struct(d.TYPE.NAME, STRUCT) %}
  this->{{d.NAME}}.to_stream(os, p_ctx);
  {%else%}
  os << this->{{d.NAME}};
  {% endif %}
  {%- endfor %}
  os << "}";
  return os;
}

std::ostream& operator<<(std::ostream& os, const {{NAME}}& c) {
  Serialization_context p_ctx;
  c.to_stream(os, p_ctx);
  return os;
}

std::istream& operator>>(std::istream& is, {{NAME}}& c) {
  Serialization_context p_ctx;
  c.from_stream(is, p_ctx);
  return is;
}

