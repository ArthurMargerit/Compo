#pragma once

#include "Interfaces/test_p//test_p.hpp"


#include "Interfaces/Dbus_adapter.hpp"





class test_p_Dbus_adapter : public Dbus_adapter
{
 private:
 test_p& comp;

 public:

 test_p_Dbus_adapter(test_p& pcomp);

 bool call(DBus::CallMessage::pointer msg,
           DBus::ReturnMessage::pointer reply) override;

 void introspection(std::stringstream& ss) override;

 protected:
 bool call(std::string &name_function,
           DBus::CallMessage::pointer msg,
           DBus::ReturnMessage::pointer reply) override;
 private:

 
 bool f0(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool f1(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool f2(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool f3(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool f5(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool f6(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 

 
};

