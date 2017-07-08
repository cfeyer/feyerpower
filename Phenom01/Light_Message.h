/*
 * Light_Message.h
 *
 * Created: 7/4/2013 7:45:30 PM
 *  Author: Chris
 */ 


#ifndef LIGHT_MESSAGE_H_
#define LIGHT_MESSAGE_H_

#include "Light_State_Enum.h"

class Light_Message
{
   public:

      Light_Message();

      Light_State::Enum light_state;
};


#endif /* LIGHT_MESSAGE_H_ */