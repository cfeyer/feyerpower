/*
 * Solenoid.h
 *
 * Created: 6/21/2013 6:29:53 PM
 *  Author: Chris
 */ 


#ifndef SOLENOID_H_
#define SOLENOID_H_


#include "Solenoid_Message.h"
#include <stdint.h>
#include "Light_Message.h"


template <const Solenoid_Message & solenoid_message_in,
          Light_Message & light_message>
class Solenoid
{
   public:

      Solenoid();

      void periodic_update_1_ms();

      void set_dwell_time_ms( uint8_t dwell_time_ms );

   private:

      uint8_t m_dwell_remaining_ms;
      uint8_t m_dwell_interval_ms;
};

#include "Solenoid.i"

#endif /* SOLENOID_H_ */