/*
 * Three_Shot_Burst_Firing_Mode.h
 *
 * Created: 6/22/2013 9:07:03 AM
 *  Author: Chris
 */ 


#ifndef THREE_SHOT_BURST_FIRING_MODE_H_
#define THREE_SHOT_BURST_FIRING_MODE_H_


#include "Firing_Mode_Interface.h"
#include "Solenoid_Message.h"
#include "Trigger_Message.h"
#include <stdint.h>


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
class Three_Shot_Burst_Firing_Mode : public Firing_Mode_Interface
{
   public:

      Three_Shot_Burst_Firing_Mode(void);

      void periodic_update_1_ms(void);
      void reset(void);

   private:

      uint8_t m_intershot_wait_remaining_ms;
      uint8_t m_balls_remaining_in_salvo;
};

#include "Three_Shot_Burst_Firing_Mode.i"

#endif /* THREE_SHOT_BURST_FIRING_MODE_H_ */