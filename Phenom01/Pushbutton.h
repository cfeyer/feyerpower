/*
 * Pushbutton.h
 *
 * Created: 6/21/2013 6:33:28 PM
 *  Author: Chris
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_


#include "Pushbutton_Message.h"
#include <stdint.h>

template <Pushbutton_Message & pushbutton_message>
class Pushbutton
{
   public:

      Pushbutton();

      void periodic_update_1_ms();

   private:

      Pushbutton_Position::Enum m_previous_position;
      uint16_t m_time_in_present_state_ms;
      uint16_t m_time_in_previous_state_ms;
};

#include "Pushbutton.i"

#endif /* PUSHBUTTON_H_ */