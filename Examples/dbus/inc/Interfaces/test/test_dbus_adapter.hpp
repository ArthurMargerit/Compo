#pragma once

#include "Interfaces/test//test.hpp"


#include "Interfaces/test_p/test_p_dbus_adapter.hpp"





class test_Dbus_adapter : public test_p_Dbus_adapter
{
 private:
 test& comp;

 public:

 test_Dbus_adapter(test& pcomp);

 bool call(DBus::CallMessage::pointer msg,
           DBus::ReturnMessage::pointer reply) override;

 void introspection(std::stringstream& ss) override;

 protected:
 bool call(std::string &name_function,
           DBus::CallMessage::pointer msg,
           DBus::ReturnMessage::pointer reply) override;
 private:

 
 bool f7(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool f8(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool f9(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool f10(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 

 
 bool get_a(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply);
 bool set_a(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply);
 
 bool get_b(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply);
 bool set_b(DBus::CallMessage::pointer msg,
                                            DBus::ReturnMessage::pointer reply);
 
};

