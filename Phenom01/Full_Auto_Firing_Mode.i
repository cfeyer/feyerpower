/*
 * Full_Auto_Firing_Mode.cpp
 *
 * Created: 6/22/2013 9:12:23 AM
 *  Author: Chris
 */ 

// firing rate [8 bps, 15 bps] (default = 13 bps) ==>
// period [125 ms, 67 ms] (default = 77 ms)

#include <stdint.h>

template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
Full_Auto_Firing_Mode<trigger_message, solenoid_message>::Full_Auto_Firing_Mode() :
   m_min_firing_period_ms( 77 )
{
   reset();
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Full_Auto_Firing_Mode<trigger_message, solenoid_message>::periodic_update_1_ms(void)
{
   solenoid_message.command = Solenoid_Command::idle;

   if( m_intershot_wait_remaining_ms != 0 )
   {
      m_intershot_wait_remaining_ms--;
   }

   if( (trigger_message.debounced_position == Trigger_Position::pulled) &&
       (m_intershot_wait_remaining_ms == 0) )
   {
      solenoid_message.command = Solenoid_Command::initiate_firing;
      m_intershot_wait_remaining_ms = m_min_firing_period_ms;
   }
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Full_Auto_Firing_Mode<trigger_message, solenoid_message>::reset()
{
   m_intershot_wait_remaining_ms = 0;
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Full_Auto_Firing_Mode<trigger_message, solenoid_message>::set_balls_per_second( uint8_t rate_bps )
{
   switch( rate_bps )
   {
      case 8:
         m_min_firing_period_ms = 125;
         break;
         
      case 9:
         m_min_firing_period_ms = 111;
         break;
         
      case 10:
         m_min_firing_period_ms = 100;
         break;
         
      case 11:
         m_min_firing_period_ms = 91;
         break;
         
      case 12:
         m_min_firing_period_ms = 83;
         break;
         
      case 13:
         m_min_firing_period_ms = 77;
         break;
         
      case 14:
         m_min_firing_period_ms = 71;
         break;
         
      case 15:
         m_min_firing_period_ms = 67;
         break;
         
      default:
         m_min_firing_period_ms = 77;
   }
}
