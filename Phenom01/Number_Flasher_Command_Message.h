/*
 * Number_Flasher_Command.h
 *
 * Created: 7/7/2013 8:01:22 AM
 *  Author: Chris
 */ 


#ifndef NUMBER_FLASHER_COMMAND_MESSAGE_H_
#define NUMBER_FLASHER_COMMAND_MESSAGE_H_

#include <stdint.h>
#include "Light_State_Enum.h"

class Number_Flasher_Command_Message
{
   public:

      Number_Flasher_Command_Message();

      bool transitioned;
      uint8_t number;
      Light_State::Enum color;
};



#endif /* NUMBER_FLASHER_COMMAND_MESSAGE_H_ */