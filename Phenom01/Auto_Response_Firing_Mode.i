/*
 * Auto_Response_Firing_Mode.cpp
 *
 * Created: 6/22/2013 9:15:35 AM
 *  Author: Chris
 */ 

#define FIRE_ON_TRIGGER_RELEASE_WINDOW_MS 1000


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
Auto_Response_Firing_Mode<trigger_message, solenoid_message>::Auto_Response_Firing_Mode(void)
{
   reset();
}

template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Auto_Response_Firing_Mode<trigger_message, solenoid_message>::periodic_update_1_ms(void)
{
   solenoid_message.command = Solenoid_Command::idle;

   if( m_pull_timeout_ms != 0 )
   {
      m_pull_timeout_ms--;
   }
   
   if( trigger_message.transitioned == true )
   {
      // Fire if trigger was just pulled
      if( trigger_message.debounced_position == Trigger_Position::pulled )
      {
         m_pull_timeout_ms = FIRE_ON_TRIGGER_RELEASE_WINDOW_MS;
         solenoid_message.command = Solenoid_Command::initiate_firing;
      }
      // Fire if trigger was just released in close temporal proximity to
      // being pulled
      else if( m_pull_timeout_ms != 0 )
      {
         solenoid_message.command = Solenoid_Command::initiate_firing;
      }
   }
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Auto_Response_Firing_Mode<trigger_message, solenoid_message>::reset()
{
   m_pull_timeout_ms = 0;
}