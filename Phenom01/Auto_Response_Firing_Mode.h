/*
 * Auto_Response_Firing_Mode.h
 *
 * Created: 6/22/2013 9:14:40 AM
 *  Author: Chris
 */ 


#ifndef AUTO_RESPONSE_FIRING_MODE_H_
#define AUTO_RESPONSE_FIRING_MODE_H_


#include "Firing_Mode_Interface.h"
#include "Solenoid_Message.h"
#include "Trigger_Message.h"
#include <stdint.h>


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
class Auto_Response_Firing_Mode : public Firing_Mode_Interface
{
   public:

      Auto_Response_Firing_Mode(void);
      void periodic_update_1_ms(void);
      void reset(void);

   private:

      uint16_t m_pull_timeout_ms;
};

#include "Auto_Response_Firing_Mode.i"

#endif /* AUTO_RESPONSE_FIRING_MODE_H_ */