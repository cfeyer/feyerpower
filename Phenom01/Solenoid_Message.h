/*
 * Solenoid_Message.h
 *
 * Created: 6/22/2013 1:40:25 PM
 *  Author: Chris
 */ 


#ifndef Solenoid_Message_H_
#define Solenoid_Message_H_


#include "Solenoid_Command_Enum.h"

class Solenoid_Message
{
   public:

      Solenoid_Message(void);

      Solenoid_Command::Enum command;
};



#endif /* Solenoid_Message_H_ */