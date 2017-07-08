/*
 * Factory_Reset.h
 *
 * Created: 7/6/2013 7:12:53 PM
 *  Author: Chris
 */ 


#ifndef FACTORY_RESET_H_
#define FACTORY_RESET_H_

#include "Pushbutton_Message.h"
#include "Light_Message.h"
#include "User_Configuration.h"
#include "Runtime_State_Message.h"

template <const Pushbutton_Message & pushbutton_message,
          Light_Message & light_message,
          User_Configuration & user_configuation,
          Runtime_State_Message & runtime_state_message>
class Factory_Reset
{
   public:

      Factory_Reset();

      void periodic_update_1_ms();
};


#include "Factory_Reset.i"


#endif /* FACTORY_RESET_H_ */