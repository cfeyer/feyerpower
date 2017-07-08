/*
 * Trigger_Status.h
 *
 * Created: 6/22/2013 10:12:21 AM
 *  Author: Chris
 */ 


#ifndef Trigger_Message_H_
#define Trigger_Message_H_


#include "Trigger_Position_Enum.h"
#include <stdint.h>

class Trigger_Message
{
   public:

      Trigger_Message();

      Trigger_Position::Enum debounced_position;
      bool transitioned;

      uint16_t time_in_present_state_ms;
      uint16_t time_in_previous_state_ms;
};


#endif /* Trigger_Message_H_ */
