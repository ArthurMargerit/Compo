%module Call;

%include <std_string.i>
%include <std_pair.i>
%include <std_map.i>
%include <std_vector.i>

%include "Interfaces/Interface.i"


%module Call
%{
#include "CompoMe/Tools/Call.hpp"
#include "Interfaces/Caller_stream.hpp"
%};


%include "CompoMe/Tools/Call.hpp"
%include "Interfaces/Caller_stream.hpp"
%template(call_result) std::pair<bool,std::string>;
%template(map_Caller_stream) std::map< std::string , CompoMe::Caller_stream* >;
%template(map_map_Caller_stream) std::map< std::string , std::map< std::string , CompoMe::Caller_stream* > >;

// i don't no why but swig need it a the end of this file ...
%{
  namespace swig {
    template <> struct traits< CompoMe::Caller_stream > {
      typedef value_category category;
      static const char* type_name() { return"CompoMe::Caller_stream"; }
    };
  }
%}
