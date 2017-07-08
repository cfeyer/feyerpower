/*
 * Full_Auto_Firing_Mode.h
 *
 * Created: 6/22/2013 9:11:07 AM
 *  Author: Chris
 */ 


#ifndef FULL_AUTO_FIRING_MODE_H_
#define FULL_AUTO_FIRING_MODE_H_


#include "Firing_Mode_Interface.h"
#include "Solenoid_Message.h"
#include "Trigger_Message.h"
#include <stdint.h>

template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
class Full_Auto_Firing_Mode : public Firing_Mode_Interface
{
   public:

      Full_Auto_Firing_Mode();

      void periodic_update_1_ms(void);
      void reset(void);

      void set_balls_per_second( uint8_t rate_bps );

   private:

      uint8_t m_min_firing_period_ms;
      uint8_t m_intershot_wait_remaining_ms;
};


#include "Full_Auto_Firing_Mode.i"

#endif /* FULL_AUTO_FIRING_MODE_H_ */