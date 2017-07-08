/*
 * Firing_Mode_Interface.h
 *
 * Created: 6/22/2013 7:40:03 AM
 *  Author: Chris
 */ 


#ifndef FIRING_MODE_INTERFACE_H_
#define FIRING_MODE_INTERFACE_H_


class Firing_Mode_Interface
{
   public:

      virtual ~Firing_Mode_Interface(void) {}
      virtual void periodic_update_1_ms(void) = 0;
      virtual void reset(void) = 0;

};


#endif /* FIRING_MODE_INTERFACE_H_ */