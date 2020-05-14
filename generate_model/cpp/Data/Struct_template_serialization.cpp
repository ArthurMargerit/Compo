#include "Data/{{NAMESPACE.replace('::','/')}}/Struct_{{NAME}}.hpp"
#include "Serialization_context.hpp"

{%include "helper/namespace_open.hpp" with context %}
// STREAM /////////////////////////////////////////////////////////////////////
constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

std::istream& {{NAME}}::from_stream(std::istream& is, Serialization_context_import& p_ctx) {
  {{NAME}} l_reset;
  *this = l_reset;

  char l_c = is.get();
  if(l_c != '{') {
    std::cerr << "Wrong start: '" <<  l_c << "' != '{'";
    throw "Wrong start: '"  "' != '{'";
  }

  do {
    std::string args;
    std::getline(is, args, ':');

    switch(str2int(args.c_str())) {

    case str2int("type"): {
        auto t = get_word(is, {',','}'});
        if(t.first != "{{NAME}}") {
          throw "Wrong Type: ";// + "{{NAME}}" + " != " + t.first ;
        }
      break;
    }

    case str2int("addr"): {
        void* addr;
        is >> addr;
        p_ctx.inscribe(addr, this);
        break;
    }

    {% if PARENT %}
    case str2int("parent"): {
      {{PARENT.NAME}}::from_stream(is, p_ctx);
      break;
    }
    {% endif %}

    {%- for d in DATA if HIDE == NULL or d.NAME not in HIDE %}
    case str2int("{{d.NAME}}"):
      {% if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
      this->{{d.NAME}}.from_stream(is, p_ctx);
      {% elif Function.model_test.is_a_pointer_type(d.TYPE) %}
      p_from_stream(is, (Struct*&) this->{{d.NAME}}, p_ctx);
      {%else%}
      is >> this->{{d.NAME}};
      {% endif %}
      break;
    {% endfor %}

    {% if EXTRA %}
    case str2int("extra"):
       this->extra_import(is, p_ctx);
       break;
    {% endif %}
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

  return is;
}

std::ostream& {{NAME}}::to_stream(std::ostream& os, Serialization_context_export& p_ctx) const {
  os << "{" ;
  os << "addr:" << (void*) this;
  p_ctx.declare(this);

  os << ",type:" << "{{NAME}}";

  {%-if PARENT -%}
  os << ",parent:";
  {{PARENT.D_NAME}}::to_stream(os, p_ctx);
  //os << "," << "parent:" << ({{PARENT.D_NAME}}) *this;
  {%-endif-%}

  {% for d in DATA if HIDE == NULL or d.NAME not in HIDE%}
  os << ",{{d.NAME}}:";
  {%if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
  this->{{d.NAME}}.to_stream(os, p_ctx);
  {%else%}{# is a type #}
  {% if Function.model_test.is_a_pointer_type(d.TYPE) %}
  p_to_stream(os, this->{{d.NAME}}, p_ctx);
  {%- else -%}
  os << this->{{d.NAME}};
  {%- endif -%}
  {%- endif -%}
  {%- endfor %}

  {% if EXTRA %}
  // extra
  os << ",extra:";
  this->extra_export(os, p_ctx);
  {% endif %}
  os << "}";
  return os;
}


{% if EXTRA %}
void {{NAME}}::extra_export(std::ostream& os, Serialization_context_export& p_ctx) const {
  os << "TODO!";
}

void {{NAME}}::extra_import(std::istream& is, Serialization_context_import& p_ctx) {
  std::string s;
  std::getline(is, s, '!');
  if(s == "TODO") {
    std::cerr << "!!!!! extra not write !!!!!" << std::endl;
  }
}
{% endif %}

std::ostream& operator<<(std::ostream& os, const {{NAME}}& c) {
  Serialization_context_export p_ctx;
  c.to_stream(os, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream& operator>>(std::istream& is, {{NAME}}& c) {
  Serialization_context_import p_ctx;
  c.from_stream(is, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

std::ostream& operator<<(std::ostream& os, const {{NAME}}* c) {
  Serialization_context_export p_ctx;
  p_to_stream(os, c, p_ctx);
  p_ctx.export_wanted(os);
  return os;
}

std::istream& operator>>(std::istream& is, {{NAME}}*& c) {
  Serialization_context_import p_ctx;
  p_from_stream(is, (Struct*&) c, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<{{NAME}}>& c) {
  Serialization_context_export l_ctx;
  p_to_stream(os, c.get(), l_ctx);
  l_ctx.export_wanted(os);
  return os;
}

std::istream& operator>>(std::istream& is, std::shared_ptr<{{NAME}}>& c) {
  Serialization_context_import p_ctx;
  p_from_stream(is,(std::shared_ptr<Struct>&) c, p_ctx);
  p_ctx.import_wanted(is);
  return is;
}

{%include "helper/namespace_close.hpp" with context %}
