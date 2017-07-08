/*
 * Time_Frame_Manager.cpp
 *
 * Created: 7/6/2013 5:32:19 PM
 *  Author: Chris
 */ 


#include "Time_Frame_Manager.h"

#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "Bit_Ops.h"


void Time_Frame_Manager::enable_frame_generation()
{
   //
   // Generate a periodic interrupt with 1 ms period / 1 KHz frequency
   // using 8-bit Timer 0's compare module A and a pre-scaled internal
   // clock signal.  OCF0A will be set when this interrupt occurs.
   //
   
   // Use internal clock pre-scaled by /8
   CLEAR_BIT( TCCR0B, CS00 );
   SET_BIT( TCCR0B, CS01 );
   CLEAR_BIT( TCCR0B, CS02 );

   // Configure "Clear Timer on Compare Match" mode
   CLEAR_BIT( TCCR0A, WGM00 );
   SET_BIT( TCCR0A, WGM01 );
   CLEAR_BIT( TCCR0B, WGM02 );

   // Make timer count up from 0.  "TOP" value of timer is to 125
   // ( (1 MHz / 8) / 125 = 1000 KHz ) and interrupt will be triggered
   // once value is reached.
   OCR0A = 125 - 1; // -1 fudge for time to come out of sleep & handle interrupt

   TCNT0 = 0;

   SET_BIT( TIMSK0, OCIE0A );

   set_sleep_mode( SLEEP_MODE_IDLE );

   sei();   
}


void Time_Frame_Manager::wait_for_top_of_frame()
{
   sleep_mode();
}


ISR( TIM0_COMPA_vect ) // Timer 0 expiration interrupt (indicates top-of-frame)
{
   // Do nothing.  Triggering of this interrupt will bring us out of low-power sleep.
}
