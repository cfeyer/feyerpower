#ifndef TRIGGER_H
#define TRIGGER_H


#include "Trigger_Message.h"
#include <stdint.h>
#include "Trigger_Position_Enum.h"


template <Trigger_Message & trigger_message_out>
class Trigger
{
   public:

      Trigger();

      void periodic_update_1_ms();

      void set_debounce_time_ms( uint8_t debounce_ms );

   private:

      uint8_t m_debounce_delay_interval_ms;
      Trigger_Position::Enum m_previous_debounced_trigger_position;
      uint8_t m_debounce_delay_remaining_ms;

      uint16_t m_time_in_present_state_ms;
      uint16_t m_time_in_previous_state_ms;
};

#include "Trigger.i"

#endif /* TRIGGER_H */