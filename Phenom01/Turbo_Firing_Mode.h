/*
 * Turbo_Firing_Mode.h
 *
 * Created: 6/22/2013 9:32:28 AM
 *  Author: Chris
 */ 


#ifndef TURBO_FIRING_MODE_H_
#define TURBO_FIRING_MODE_H_


#include "Firing_Mode_Interface.h"
#include "Solenoid_Message.h"
#include "Trigger_Message.h"
#include <stdint.h>


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
class Turbo_Firing_Mode : public Firing_Mode_Interface
{
   public:

      Turbo_Firing_Mode(void);

      void periodic_update_1_ms(void);
      void reset(void);

   private:

      uint16_t m_auto_window_remaining_ms;
      uint8_t m_intershot_wait_remaining_ms;
};

#include "Turbo_Firing_Mode.i"

#endif /* TURBO_FIRING_MODE_H_ */