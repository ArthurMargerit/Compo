
#include "Interfaces/test_p//test_p_dbus_adapter.hpp"
#include "Errors/Error.hpp"



constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

test_p_Dbus_adapter::test_p_Dbus_adapter(test_p& pcomp):Dbus_adapter(),comp(pcomp){}

void test_p_Dbus_adapter::introspection(std::stringstream& ss){

  

  
  ss << "<method name=\"f0\">"
  

  

    << "</method>";
  
  ss << "<method name=\"f1\">"
  
    
    << "<arg type=\"d\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  
  ss << "<method name=\"f2\">"
  
    
    << "<arg type=\"y\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  
  ss << "<method name=\"f3\">"
  
    
    << "<arg type=\"n\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  
  ss << "<method name=\"f5\">"
  
    
    << "<arg type=\"i\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  
  ss << "<method name=\"f6\">"
  
    
    << "<arg type=\"x\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  

  
}


bool test_p_Dbus_adapter::call(DBus::CallMessage::pointer msg,
                                 DBus::ReturnMessage::pointer reply) {

  std::string name_function = msg->member();
  bool b = this->call(name_function,msg,reply);
  return b;
}



bool test_p_Dbus_adapter::call(std::string &name_function, DBus::CallMessage::pointer msg,
                                 DBus::ReturnMessage::pointer reply) {
  bool result = false;

  switch(str2int(name_function.c_str())) {
    // Function
    
  case str2int("f0"):
    result= this->f0(msg, reply);
    break;
    
  case str2int("f1"):
    result= this->f1(msg, reply);
    break;
    
  case str2int("f2"):
    result= this->f2(msg, reply);
    break;
    
  case str2int("f3"):
    result= this->f3(msg, reply);
    break;
    
  case str2int("f5"):
    result= this->f5(msg, reply);
    break;
    
  case str2int("f6"):
    result= this->f6(msg, reply);
    break;
    

    // Get/Set
    

    
  };

  return result;
}

 
bool test_p_Dbus_adapter::f0(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    

    try {
      
      this->comp.f0();
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool test_p_Dbus_adapter::f1(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    double l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f1(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool test_p_Dbus_adapter::f2(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    i8 l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f2(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool test_p_Dbus_adapter::f3(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    i16 l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f3(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool test_p_Dbus_adapter::f5(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    i32 l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f5(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool test_p_Dbus_adapter::f6(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    i64 l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f6(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}



