/*
 * Pushbutton_Message.h
 *
 * Created: 6/23/2013 5:25:18 AM
 *  Author: Chris
 */ 


#ifndef PUSHBUTTON_MESSAGE_H_
#define PUSHBUTTON_MESSAGE_H_


#include "Pushbutton_Position_Enum.h"

#include <stdint.h>

class Pushbutton_Message
{
   public:

      Pushbutton_Message(void);

      Pushbutton_Position::Enum position;
      bool transitioned;

      uint16_t time_in_present_state_ms;
      uint16_t time_in_previous_state_ms;
};


#endif /* PUSHBUTTON_MESSAGE_H_ */