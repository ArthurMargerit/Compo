#pragma once

#include "Interfaces/Calculator//Calculator.hpp"


#include "Interfaces/Dbus_adapter.hpp"





class Calculator_Dbus_adapter : public Dbus_adapter
{
 private:
 Calculator& comp;

 public:

 Calculator_Dbus_adapter(Calculator& pcomp);

 bool call(DBus::CallMessage::pointer msg,
           DBus::ReturnMessage::pointer reply) override;

 void introspection(std::stringstream& ss) override;

 protected:
 bool call(std::string &name_function,
           DBus::CallMessage::pointer msg,
           DBus::ReturnMessage::pointer reply) override;
 private:

 
 bool add(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool sub(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool time(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 
 bool div(DBus::CallMessage::pointer msg,
                      DBus::ReturnMessage::pointer reply);
 

 
};
