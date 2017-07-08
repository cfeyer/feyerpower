/*
 * Battery_Message.h
 *
 * Created: 7/2/2013 6:36:42 PM
 *  Author: Chris
 */ 


#ifndef BATTERY_MESSAGE_H_
#define BATTERY_MESSAGE_H_

#include "Battery_Health_Enum.h"

class Battery_Message
{
  public:

     Battery_Message();

     Battery_Health::Enum health;
};




#endif /* BATTERY_MESSAGE_H_ */