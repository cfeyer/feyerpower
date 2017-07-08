/*
 * Lights.h
 *
 * Created: 6/21/2013 6:43:42 PM
 *  Author: Chris
 */ 


#ifndef LIGHTS_H_
#define LIGHTS_H_


#include <stdint.h>
#include "Light_Message.h"


template <const Light_Message & light_message>
class Lights
{
   public:

      Lights();

      void periodic_update_1_ms();

   private:

      enum Orange_State
      {
         orange_green_1,
         orange_green_2,
         orange_red_1
      };

      Orange_State m_next_orange_state;
};

#include "Lights.i"

#endif /* LIGHTS_H_ */