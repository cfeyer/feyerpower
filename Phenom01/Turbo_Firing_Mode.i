/*
 * Turbo_Firing_Mode.cpp
 *
 * Created: 6/22/2013 9:33:17 AM
 *  Author: Chris
 */

#define TURBO_INTERSHOT_WAIT_INTERVAL_MS 67
#define AUTO_WINDOW_MS 1000


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
Turbo_Firing_Mode<trigger_message, solenoid_message>::Turbo_Firing_Mode(void)
{
   reset();
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Turbo_Firing_Mode<trigger_message, solenoid_message>::periodic_update_1_ms(void)
{
   if( m_auto_window_remaining_ms != 0 )
   {
      m_auto_window_remaining_ms--;
   }

   if( m_intershot_wait_remaining_ms != 0 )
   {
      m_intershot_wait_remaining_ms--;
   }

   solenoid_message.command = Solenoid_Command::idle;

   if( trigger_message.debounced_position == Trigger_Position::pulled )
   {
      if( trigger_message.transitioned == true )
      {
         m_auto_window_remaining_ms = AUTO_WINDOW_MS;
      }

      if( (m_auto_window_remaining_ms != 0) &&
          (m_intershot_wait_remaining_ms == 0 ) )
      {
         solenoid_message.command = Solenoid_Command::initiate_firing;
         m_intershot_wait_remaining_ms = TURBO_INTERSHOT_WAIT_INTERVAL_MS;
      }
   }
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Turbo_Firing_Mode<trigger_message, solenoid_message>::reset()
{
   m_auto_window_remaining_ms = 0;
   m_intershot_wait_remaining_ms = 0;
}