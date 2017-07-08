/*
 * Semi_Auto_Firing_Mode.cpp
 *
 * Created: 6/22/2013 8:17:28 AM
 *  Author: Chris
 */ 


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
Semi_Auto_Firing_Mode<trigger_message, solenoid_message>::Semi_Auto_Firing_Mode(void)
{
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Semi_Auto_Firing_Mode<trigger_message, solenoid_message>::periodic_update_1_ms(void)
{
   solenoid_message.command = Solenoid_Command::idle;

   if( (trigger_message.debounced_position == Trigger_Position::pulled) &&
       (trigger_message.transitioned == true) )
   {
      solenoid_message.command = Solenoid_Command::initiate_firing;
   }
}


template <const Trigger_Message & trigger_message,
          Solenoid_Message & solenoid_message>
void Semi_Auto_Firing_Mode<trigger_message, solenoid_message>::reset()
{
   // No state data, therefore nothing to reset
}