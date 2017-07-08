/*
 * Battery.cpp
 *
 * Created: 7/2/2013 6:34:05 PM
 *  Author: Chris
 */ 


#include "Debug_Pin.h"

#define BATTERY_POLL_INTERVAL_MS 5000

template <Light_Message & light_message>
Battery<light_message>::Battery(void) :
   m_time_until_next_update_ms( 0 ),
   m_battery_health( Battery_Health::low )
{
}


template <Light_Message & light_message>
void Battery<light_message>::periodic_update_1_ms(void)
{
   if( m_time_until_next_update_ms > (BATTERY_POLL_INTERVAL_MS/2) )
   {
      if( m_battery_health == Battery_Health::good )
      {
         light_message.light_state = Light_State::green;
      }
      else
      {
         light_message.light_state = Light_State::red;
      }
   }
   else if( m_time_until_next_update_ms > 0 )
   {
      light_message.light_state = Light_State::off;
   }
   else // Time to run ADC to re-measure battery voltage
   {
      m_time_until_next_update_ms = BATTERY_POLL_INTERVAL_MS;
      light_message.light_state = Light_State::off;

      // TODO
   }

   m_time_until_next_update_ms--;
}
