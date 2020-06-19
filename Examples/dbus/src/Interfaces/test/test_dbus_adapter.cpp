
#include "Interfaces/test//test_dbus_adapter.hpp"
#include "Errors/Error.hpp"



constexpr unsigned int str2int(const char* str, int h = 0) {
  return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

test_Dbus_adapter::test_Dbus_adapter(test& pcomp):test_p_Dbus_adapter(pcomp),comp(pcomp){}

void test_Dbus_adapter::introspection(std::stringstream& ss){

  
  test_p_Dbus_adapter::introspection(ss);
  

  
  ss << "<method name=\"f7\">"
  
    
    << "<arg type=\"y\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  
  ss << "<method name=\"f8\">"
  
    
    << "<arg type=\"q\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  
  ss << "<method name=\"f9\">"
  
    
    << "<arg type=\"u\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  
  ss << "<method name=\"f10\">"
  
    
    << "<arg type=\"t\" name=\"a\" direction=\"in\"/>"
  

  

    << "</method>";
  

  
  ss << "<method name=\"get_a\">"
     << "<arg type=\"i\" name=\"ret\" direction=\"out\"/>"
     << "</method>";

  ss << "<method name=\"set_a\">"
     << "<arg type=\"i\" name=\"set\" direction=\"in\"/>"
     << "</method>";

  ss << "<property type=\"i\" name=\"a\" access=\"readwrite\"/>";
  
  ss << "<method name=\"get_b\">"
     << "<arg type=\"x\" name=\"ret\" direction=\"out\"/>"
     << "</method>";

  ss << "<method name=\"set_b\">"
     << "<arg type=\"x\" name=\"set\" direction=\"in\"/>"
     << "</method>";

  ss << "<property type=\"x\" name=\"b\" access=\"readwrite\"/>";
  
}


bool test_Dbus_adapter::call(DBus::CallMessage::pointer msg,
                                 DBus::ReturnMessage::pointer reply) {

  std::string name_function = msg->member();
  bool b = this->call(name_function,msg,reply);
  return b;
}



bool test_Dbus_adapter::call(std::string &name_function, DBus::CallMessage::pointer msg,
                                 DBus::ReturnMessage::pointer reply) {
  bool result = false;

  switch(str2int(name_function.c_str())) {
    // Function
    
  case str2int("f7"):
    result= this->f7(msg, reply);
    break;
    
  case str2int("f8"):
    result= this->f8(msg, reply);
    break;
    
  case str2int("f9"):
    result= this->f9(msg, reply);
    break;
    
  case str2int("f10"):
    result= this->f10(msg, reply);
    break;
    

    // Get/Set
    
  case str2int("get_a"):
    result = this->get_a(msg, reply);
    break;
  case str2int("set_a"):
    result = this->set_a(msg, reply);
    break;

    
  case str2int("get_b"):
    result = this->get_b(msg, reply);
    break;
  case str2int("set_b"):
    result = this->set_b(msg, reply);
    break;

    

    
  default:
    return test_p_Dbus_adapter::call(name_function, msg, reply);
    break;
    
  };

  return result;
}

 
bool test_Dbus_adapter::f7(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    u8 l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f7(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool test_Dbus_adapter::f8(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    u16 l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f8(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool test_Dbus_adapter::f9(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    u32 l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f9(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}

bool test_Dbus_adapter::f10(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply){
    
    
    auto i = msg->begin();
    

    u64 l_a;
    i = i >> l_a;
    

    try {
      
      this->comp.f10(l_a);
  

  } catch (const Error &e) {
      std::stringstream ss;
      ss << "!" << &e;
      reply << ss.str();
  }

  return true;
}



bool test_Dbus_adapter::get_a(DBus::CallMessage::pointer msg,
                                             DBus::ReturnMessage::pointer reply){
 try {
   reply << this->comp.get_a();
 } catch (const Error &e) {
   std::stringstream ss;
   ss << "!" << &e;
   reply << ss.str();
 }

 return true;
}

bool test_Dbus_adapter::set_a(DBus::CallMessage::pointer msg,
                                             DBus::ReturnMessage::pointer reply){
  i32 set_val;
  msg >> set_val;

  try {
    this->comp.set_a(set_val);
  } catch (const Error &e) {
     std::stringstream ss;
     ss << "!" << &e;
     reply << ss.str();
  }

  return true;
}

bool test_Dbus_adapter::get_b(DBus::CallMessage::pointer msg,
                                             DBus::ReturnMessage::pointer reply){
 try {
   reply << this->comp.get_b();
 } catch (const Error &e) {
   std::stringstream ss;
   ss << "!" << &e;
   reply << ss.str();
 }

 return true;
}

bool test_Dbus_adapter::set_b(DBus::CallMessage::pointer msg,
                                             DBus::ReturnMessage::pointer reply){
  i64 set_val;
  msg >> set_val;

  try {
    this->comp.set_b(set_val);
  } catch (const Error &e) {
     std::stringstream ss;
     ss << "!" << &e;
     reply << ss.str();
  }

  return true;
}
