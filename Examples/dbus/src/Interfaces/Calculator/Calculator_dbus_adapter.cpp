
#include "Interfaces/Calculator//Calculator_dbus_adapter.hpp"
#include "Errors/Error.hpp"



constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

Calculator_Dbus_adapter::Calculator_Dbus_adapter(Calculator& pcomp):Dbus_adapter(),comp(pcomp){}

void Calculator_Dbus_adapter::introspection(std::stringstream& ss){

  

  
  ss << "<method name=\"add\">"
  
    
    << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"
  
    
    << "<arg type=\"d\" name=\"b\" direction=\"in\"/>"
  

  
    << "<arg type=\"d\" name=\"ret\" direction=\"out\"/>"
  

    << "</method>";
  
  ss << "<method name=\"sub\">"
  
    
    << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"
  
    
    << "<arg type=\"d\" name=\"b\" direction=\"in\"/>"
  

  
    << "<arg type=\"d\" name=\"ret\" direction=\"out\"/>"
  

    << "</method>";
  
  ss << "<method name=\"time\">"
  
    
    << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"
  
    
    << "<arg type=\"d\" name=\"b\" direction=\"in\"/>"
  

  
    << "<arg type=\"d\" name=\"ret\" direction=\"out\"/>"
  

    << "</method>";
  
  ss << "<method name=\"div\">"
  
    
    << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"
  
    
    << "<arg type=\"d\" name=\"b\" direction=\"in\"/>"
  

  
    << "<arg type=\"d\" name=\"ret\" direction=\"out\"/>"
  

    << "</method>";
  

  
}


bool Calculator_Dbus_adapter::call(DBus::CallMessage::pointer msg,
                                 DBus::ReturnMessage::pointer reply) {

  std::string name_function = msg->member();
  bool b = this->call(name_function,msg,reply);
  return b;
}



bool Calculator_Dbus_adapter::call(std::string &name_function, DBus::CallMessage::pointer msg,
                                 DBus::ReturnMessage::pointer reply) {
  bool result = false;

  switch(str2int(name_function.c_str())) {
    // Function
    
  case str2int("add"):
    result= this->add(msg, reply);
    break;
    
  case str2int("sub"):
    result= this->sub(msg, reply);
    break;
    
  case str2int("time"):
    result= this->time(msg, reply);
    break;
    
  case str2int("div"):
    result= this->div(msg, reply);
    break;
    

    // Get/Set
    

    
  };

  return result;
}

 
bool Calculator_Dbus_adapter::add(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    double l_a;
    i = i >> l_a;
    
    

    double l_b;
    i = i >> l_b;
    

    try {
      
  reply << this->comp.add(l_a, l_b);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool Calculator_Dbus_adapter::sub(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    double l_a;
    i = i >> l_a;
    
    

    double l_b;
    i = i >> l_b;
    

    try {
      
  reply << this->comp.sub(l_a, l_b);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool Calculator_Dbus_adapter::time(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    double l_a;
    i = i >> l_a;
    
    

    double l_b;
    i = i >> l_b;
    

    try {
      
  reply << this->comp.time(l_a, l_b);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool Calculator_Dbus_adapter::div(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    double l_a;
    i = i >> l_a;
    
    

    double l_b;
    i = i >> l_b;
    

    try {
      
  reply << this->comp.div(l_a, l_b);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}



