/*
 * Runtime_State_Manager.h
 *
 * Created: 7/6/2013 6:11:29 PM
 *  Author: Chris
 */ 


#ifndef RUNTIME_STATE_MANAGER_H_
#define RUNTIME_STATE_MANAGER_H_

#include "Runtime_State_Message.h"
#include "Pushbutton_Message.h"
#include "Light_Message.h"

template <Runtime_State_Message & runtime_state_message,
          Light_Message & light_message,
          const Pushbutton_Message & pushbutton_message>
class Runtime_State_Manager
{
   public:

      Runtime_State_Manager();

      void periodic_update_1_ms();
};


#include "Runtime_State_Manager.i"


#endif /* RUNTIME_STATE_MANAGER_H_ */