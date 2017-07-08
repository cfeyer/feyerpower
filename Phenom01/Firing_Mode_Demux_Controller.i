/*
 * Firing_Mode_Demux_Controller.cpp
 *
 * Created: 7/5/2013 12:32:13 PM
 *  Author: Chris
 */ 


template <const Pushbutton_Message & pushbutton_message,
          Firing_Mode_Demux & firing_mode_demux,
          Number_Flasher_Command_Message & number_command_message>
Firing_Mode_Demux_Controller<pushbutton_message, 
                             firing_mode_demux,
                             number_command_message>::Firing_Mode_Demux_Controller(void) :
   m_issued_number_flasher_command( false )
{
}


template <const Pushbutton_Message & pushbutton_message,
          Firing_Mode_Demux & firing_mode_demux,
          Number_Flasher_Command_Message & number_command_message>
void Firing_Mode_Demux_Controller<pushbutton_message,
                                  firing_mode_demux,
                                  number_command_message>::periodic_update_1_ms(void)
{
   if( m_issued_number_flasher_command == true )
   {
      number_command_message.transitioned = false;
      m_issued_number_flasher_command = false;
   }

   // Update mux mode out here since mux's periodic update
   // may not always be called depending upon state of
   // three shot safety
   if( (pushbutton_message.transitioned == true) &&
       (pushbutton_message.position == Pushbutton_Position::pressed) &&
       (pushbutton_message.time_in_previous_state_ms >= 200) )
   {
      firing_mode_demux.select_next_mode();

      number_command_message.transitioned = true;
      number_command_message.color = Light_State::green;
      number_command_message.number = (firing_mode_demux.get_mode_index() + 1);
      m_issued_number_flasher_command = true;
   }
}