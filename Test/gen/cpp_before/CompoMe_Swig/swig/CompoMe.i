
%module CompoMe
%{
#include "Data/CompoMe.hpp"
#include "Types/CompoMe/String.hpp"
%}

typedef short i16;
typedef unsigned short ui16;

typedef int i32;
typedef unsigned int ui32;

typedef long int i64;
typedef unsigned long int ui64;

%include "Data/CompoMe.hpp"
%include "Types/CompoMe/String.hpp"
