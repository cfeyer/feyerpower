/*
 * Semi_Auto_Firing_Mode.h
 *
 * Created: 6/22/2013 8:16:11 AM
 *  Author: Chris
 */ 


#ifndef SEMI_AUTO_FIRING_MODE_H_
#define SEMI_AUTO_FIRING_MODE_H_


#include "Firing_Mode_Interface.h"
#include "Solenoid_Message.h"
#include "Trigger_Message.h"


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
class Semi_Auto_Firing_Mode : public Firing_Mode_Interface
{
   public:

      Semi_Auto_Firing_Mode(void);

      void periodic_update_1_ms(void);
      void reset(void);
};

#include "Semi_Auto_Firing_Mode.i"

#endif /* SEMI_AUTO_FIRING_MODE_H_ */