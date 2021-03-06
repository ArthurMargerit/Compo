#include "Serialization_context.hpp"
#include "Components/{{F_NAME}}.hpp"
#include "CompoMe/Log.hpp"
#include <string>
#include <cstdlib>

{% include "helper/namespace_open.hpp" with context %}

std::ostream& operator<<(std::ostream& os, const {{NAME}}& c) {
    CompoMe::Serialization_context_export p_ctx;
    c.to_stream(os, p_ctx);
    p_ctx.export_wanted(os);
    return os;
  }

std::istream& operator>>(std::istream& is, {{NAME}}& c) {
    CompoMe::Serialization_context_import p_ctx;
    c.from_stream(is, p_ctx);
    p_ctx.import_wanted(is);
    return is;
  }

constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}


std::ostream& {{NAME}}::to_stream_data(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const {
  os << ",data:{";
  {% for d in DATA -%}
  os << "{{d.NAME}}:";

  {%if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
  this->{{d.NAME}}.to_stream(os, p_ctx);
  {%else%}{# is a type #}
  {% if Function.model_test.is_a_pointer_type(d.TYPE) %}
  p_to_stream(os, this->{{d.NAME}}, p_ctx);
  {%- else -%}{# is a basic type #}
  os << this->{{d.NAME}};
  {%- endif -%}
  {%- endif -%}
  {% if not loop.last -%} os << ","; {%- endif-%}
  {% endfor -%}
  os << "}";

  return os;
}


std::ostream& {{NAME}}::to_stream_sc(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const {
    os << ",components:{";
    {% for sc in COMPONENT_INSTANCE %}
    os << "{{sc.NAME}}:";
    this->{{sc.NAME}}.to_stream(os, p_ctx);
    {% if not loop.last -%}os << ",";{%- endif-%}
    {% endfor %}
    os << "}";
    return os;
}

std::ostream& {{NAME}}::to_stream_provide(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const {
  os << ",provide:{";
  {% for i_p in PROVIDE %}
  os << "{{i_p.NAME}}:";
  this->{{i_p.NAME}}.to_stream(os, p_ctx);
  {% if not loop.last -%}os << ",";{%- endif-%}
  {% endfor %}
  os << "}";
  return os;
}


  /////////////////////////////////////////////////////////////////////////////
  //                            LOAD/SAVE                                    //
  /////////////////////////////////////////////////////////////////////////////
void {{NAME}}::to_stream(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const {
    os << "{";
    os << "addr:" << (void*) this;
    p_ctx.declare(this);

    os << ",type:" << "{{D_NAME}}";

    {% if PARENT -%}
    os << ",parent:";
    {{PARENT.D_NAME}}::{{PARENT.NAME}}::to_stream(os, p_ctx);
    {%- endif-%}

    {% if DATA -%}
    this->to_stream_data(os, p_ctx);
    {%- endif -%}

    {% if COMPONENT_INSTANCE -%}
    this->to_stream_sc(os, p_ctx);
    {%- endif -%}

    {% if PROVIDE -%}
    this->to_stream_provide(os, p_ctx);
    {%- endif -%}

    {% if EXTRA -%}
    os << ",extra:";
    this->extra_export(os, p_ctx);
    {% endif -%}

    os << '}';
    //    return os;
}

  {% if EXTRA -%}
void {{NAME}}::extra_export(std::ostream& os, CompoMe::Serialization_context_export& p_ctx) const {
    os << "";
  }

void {{NAME}}::extra_import(std::istream& is, CompoMe::Serialization_context_import& p_ctx) {

  }
  {% endif -%}


std::istream& {{NAME}}::from_stream_provide(std::istream& is, CompoMe::Serialization_context_import& p_ctx) {
      char l_c = is.get();
      if(l_c != '{') {
        C_ERROR("Wrong start: '",  l_c ,"' != '{'");
        throw "Wrong start: '"  "' != '{'";
      }

      do {
        std::string args;
        std::getline(is, args, ':');

        switch(str2int(args.c_str())) {
          {%- for i_p in PROVIDE if i_p.NAME not in OPTIONS.HIDE %}
        case str2int("{{i_p.NAME}}"):
          this->get_{{i_p.NAME}}().from_stream(is, p_ctx);
          break;
          {% endfor %}

        default:
          C_ERROR("wrong attribute: \"", args, "\" not in data {{NAME}}");
          throw "wrong attribute: \""+ args +"\" not in provide {{NAME}}";
          break;
        }

        l_c = is.get();
      } while(l_c == ',');

  return is;
}

std::istream& {{NAME}}::from_stream_data(std::istream& is, CompoMe::Serialization_context_import& p_ctx) {
      char l_c = is.get();
      if(l_c != '{') {
        C_ERROR("Wrong start: '", l_c , "' != '{'");
        throw "Wrong start: '"  "' != '{'";
      }

      do {
        std::string args;
        std::getline(is, args, ':');

        switch(str2int(args.c_str())) {
          {%- for d in DATA if d.NAME not in OPTIONS.HIDE %}
        case str2int("{{d.NAME}}"):
          {% if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) -%}
          this->{{d.NAME}}.from_stream(is, p_ctx);
          {% elif Function.model_test.is_a_pointer_type(d.TYPE) -%}
          p_from_stream(is, (CompoMe::Serializable_Item*&) this->{{d.NAME}}, p_ctx);
          {% else -%}
          is >> this->{{d.NAME}};
          {% endif -%}
          break;
          {% endfor %}

        default:
          C_ERROR("wrong attribute: \"",args ,"\" not in data {{NAME}}");
          throw "wrong attribute: \""+ args +"\" not in data {{NAME}}";
          break;
        }

        l_c = is.get();
      } while(l_c == ',');


  return is;
  }

std::istream& {{NAME}}::from_stream_sc(std::istream& is , CompoMe::Serialization_context_import& p_ctx) {
      char l_c = is.get();
      if(l_c != '{') {
        C_ERROR("Wrong start: '",  l_c, "' != '{'");
        throw "Wrong start: '"  "' != '{'";
      }

      do {
        std::string args;
        std::getline(is, args, ':');

        switch(str2int(args.c_str())) {
          {%- for i_c in COMPONENT_INSTANCE if i_c.NAME not in OPTIONS.HIDE %}
        case str2int("{{i_c.NAME}}"):
          this->{{i_c.NAME}}.from_stream(is, p_ctx);
          break;
          {% endfor %}

        default:
          C_ERROR("wrong attribute: \"", args ,"\" not in data {{NAME}}");
          throw "wrong attribute: \""+ args +"\" not in sub components {{NAME}}";
          break;
        }

        l_c = is.get();
      } while(l_c == ',');

    return is;
  }


void {{NAME}}::from_stream(std::istream& is, CompoMe::Serialization_context_import& p_ctx) {
    {{NAME}} l_reset;
    *this = l_reset;

    char l_c = is.get();
    if(l_c != '{') {
      C_ERROR("Wrong start: '", l_c, "' != '{'");
      throw "Wrong start: '"  "' != '{'";
    }

    do {
      std::string args;
      std::getline(is, args, ':');

      switch(str2int(args.c_str())) {
        // TYPE ///////////////////////////////////////////////////////////////
      case str2int("type"): {

        auto t = CompoMe::get_word(is, {',','}'});
        if(t.first != "{{NAME}}") {
          throw "Wrong Type: ";// + "{{NAME}}" + " != " + t.first ;
        }
        break;
      }

        // ADDR ///////////////////////////////////////////////////////////////
      case str2int("addr"): {
        void* addr;
        is >> addr;
        p_ctx.inscribe(addr, this);
        break;
      }

        // PARRENT ////////////////////////////////////////////////////////////
        {% if PARENT %}
      case str2int("parent"): {
        {{PARENT.NAME}}::from_stream(is, p_ctx);
        break;
      }
        {% endif %}

        // DATA ///////////////////////////////////////////////////////////////
        {% if DATA %}
      case str2int("data"): {
        this->from_stream_data(is, p_ctx);
        break;
      }
        {% endif %}

        // COMPONENT //////////////////////////////////////////////////////////
        {% if COMPONENT_INSTANCE %}
      case str2int("components"): {
        this->from_stream_sc(is, p_ctx);
        break;
      }
        {% endif %}

        // PROVIDE ////////////////////////////////////////////////////////////
        {% if PROVIDE %}
      case str2int("provide"): {
        this->from_stream_provide(is, p_ctx);
        break;
      }
        {% endif %}

      default: {
            C_ERROR("wrong attribute: \"", args, "\" not in {{NAME}}");
            throw "wrong attribute: \""+ args +"\" not in {{NAME}}";
            break;
      }

      }

      l_c = is.get();
      } while(l_c == ',');

      if(l_c != '}') {
        C_ERROR("Wrong end: '", l_c, "' != '}'" );
        throw "Wrong end";
      }

        //   default:
        //     std::cerr << "wrong attribute: \""<< args <<"\" not in {{NAME}}";
        //     throw "wrong attribute: \""+ args +"\" not in {{NAME}}";
        //     break;
        //   }

        //   {% if EXTRA %}
        //   case str2int("extra"):
        //      this->extra_import(is, p_ctx);
        //      break;
        //   {% endif %}
  
  //   // {%- for d in DATA if d.NAME not in OPTIONS.HIDE %}
  //   // case str2int("{{d.NAME}}"):
  //   //   {% if Function.model_test.is_struct(d.TYPE.D_NAME, MAIN) %}
  //   //   this->{{d.NAME}}.from_stream(is, p_ctx);
  //   //   {% elif Function.model_test.is_a_pointer_type(d.TYPE) %}
  //   //   p_from_stream(is, (Serializable_Item*&) this->{{d.NAME}}, p_ctx);
  //   //   {%else%}
  //   //   is >> this->{{d.NAME}};
  //   //   {% endif %}
  //   //   break;
  //   // {% endfor %}

  //   l_c = is.get();
  // }while(l_c == ',');

  // if(l_c != '}') {
  //   std::cerr << "Wrong end: '"<< l_c <<"' != '}'" << std::endl;
  //   throw "Wrong end";
  // }

      //    return is;
  }

{% include "helper/namespace_close.hpp" with context %}

