/*
 * Battery.h
 *
 * Created: 7/2/2013 6:33:04 PM
 *  Author: Chris
 */ 


#ifndef BATTERY_H_
#define BATTERY_H_

#include <stdint.h>
#include "Light_Message.h"

template <Light_Message & light_message>
class Battery
{
   public:

      Battery(void);

      void periodic_update_1_ms(void);

   private:

      uint16_t m_time_until_next_update_ms;
      Battery_Health::Enum m_battery_health;
};

#include "Battery.i"



#endif /* BATTERY_H_ */