/*
 * Number_Flasher.h
 *
 * Created: 7/7/2013 7:43:28 AM
 *  Author: Chris
 */ 


#ifndef NUMBER_FLASHER_H_
#define NUMBER_FLASHER_H_

#include <stdint.h>
#include "Number_Flasher_Command_Message.h"
#include "Number_Flasher_Status_Message.h"
#include "Light_Message.h"

template <const Number_Flasher_Command_Message & number_command_message,
          Number_Flasher_Status_Message & number_status_message,
          Light_Message & light_message>
class Number_Flasher
{
   public:

      Number_Flasher();

      void periodic_update_1_ms();

   private:

      enum State
      {
         idle,
         preamble_dark_1,
         preamble_lit,
         preamble_dark_2,
         count_lit,
         count_dark
      };

      State m_state;

      uint16_t m_time_left_in_current_state_ms;
      uint8_t m_count_remaining;

      Light_State::Enum m_count_color;
};

#include "Number_Flasher.i"

#endif /* NUMBER_FLASHER_H_ */