/*
 * Three_Shot_Burst_Firing_Mode.cpp
 *
 * Created: 6/22/2013 9:07:45 AM
 *  Author: Chris
 */ 

#define BALLS_PER_SALVO 3
#define INTERSHOT_WAIT_INTERVAL_MS 77


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
Three_Shot_Burst_Firing_Mode<trigger_message, solenoid_message>::Three_Shot_Burst_Firing_Mode(void)
{
   reset();
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Three_Shot_Burst_Firing_Mode<trigger_message, solenoid_message>::periodic_update_1_ms(void)
{
   solenoid_message.command = Solenoid_Command::idle;

   if( m_intershot_wait_remaining_ms != 0 )
   {
      m_intershot_wait_remaining_ms--;
   }

   if( (trigger_message.debounced_position == Trigger_Position::pulled) &&
       (trigger_message.transitioned == true) &&
       (m_balls_remaining_in_salvo == 0) )
   {
      m_balls_remaining_in_salvo = BALLS_PER_SALVO;
   }

   if( (m_balls_remaining_in_salvo != 0) &&
       (m_intershot_wait_remaining_ms == 0) )
   {
      solenoid_message.command = Solenoid_Command::initiate_firing;
      m_balls_remaining_in_salvo--;
      m_intershot_wait_remaining_ms = INTERSHOT_WAIT_INTERVAL_MS;
   }
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Three_Shot_Burst_Firing_Mode<trigger_message, solenoid_message>::reset()
{
   m_intershot_wait_remaining_ms = 0;
   m_balls_remaining_in_salvo = 0;
}