/*
 * Menu.cpp
 *
 * Created: 7/4/2013 3:53:02 PM
 *  Author: Chris
 */ 

#define LONG_PULL_MS 1000

template <const Trigger_Message & trigger_message,
          const Number_Flasher_Status_Message & number_status_message,
          Number_Flasher_Command_Message & number_command_message,
          User_Configuration & user_configuration>
Menu<trigger_message, number_status_message, number_command_message, user_configuration>::Menu() :
   m_state( Menu_State::disabled ),
   m_parameter_number( 0 ),
   m_edit_mode( navigate_menu ),
   m_issued_number_flasher_command( false ),
   m_edit_value_submode( count_not_yet_displayed ),
   m_value_changed( false )
{
}


template <const Trigger_Message & trigger_message,
          const Number_Flasher_Status_Message & number_status_message,
          Number_Flasher_Command_Message & number_command_message,
          User_Configuration & user_configuration>
void Menu<trigger_message, number_status_message, number_command_message, user_configuration>::periodic_update_1_ms(void)
{
   Menu_Command command = no_command;

   if( (trigger_message.transitioned == true) &&
       (trigger_message.debounced_position == Trigger_Position::released) )
   {
      if( trigger_message.time_in_previous_state_ms < LONG_PULL_MS )
      {
         command = command_step;
      }
      else
      {
         command = command_enter;
      }
   }

   if( m_issued_number_flasher_command == true )
   {
      number_command_message.transitioned = false;
      m_issued_number_flasher_command = false;
   }

   if( m_edit_mode == navigate_menu )
   {
      if( command == no_command )
      {
         if( number_status_message.idle == true )
         {
            number_command_message.number = (m_parameter_number + 1);
            number_command_message.color = Light_State::green;
            number_command_message.transitioned = true;
            m_issued_number_flasher_command = true;
         }
      }
      else if( command == command_step )
      {
         m_parameter_number++;
         if( m_parameter_number == user_configuration.get_parameter_count() )
         {
            m_parameter_number = 0;
         }
         
         number_command_message.number = (m_parameter_number + 1);
         number_command_message.color = Light_State::green;
         number_command_message.transitioned = true;
         m_issued_number_flasher_command = true;
      }
      else if( command == command_enter )
      {
         m_edit_mode = edit_value;
         m_edit_value_submode = count_not_yet_displayed;
      }
   }
   else if( m_edit_mode == edit_value )
   {
      if( command == no_command )
      {
         uint8_t blink_count =
            user_configuration.get_parameter_value( m_parameter_number );

         if( user_configuration.get_parameter_minimum( m_parameter_number ) == 0 )
         {
            blink_count++;
         }

         if( m_edit_value_submode == count_not_yet_displayed )
         {  
            number_command_message.number = blink_count;
            number_command_message.color = Light_State::red;
            number_command_message.transitioned = true;
            m_issued_number_flasher_command = true;

            m_edit_value_submode = displaying_count_1;
         }
         else if( m_edit_value_submode == displaying_count_1 )
         {
            if( number_status_message.idle == true )
            {
               number_command_message.number = blink_count;
               number_command_message.color = Light_State::red;
               number_command_message.transitioned = true;
               m_issued_number_flasher_command = true;

               m_edit_value_submode = displaying_count_2;
            }
         }
         else if( m_edit_value_submode == displaying_count_2 )
         {
            if( number_status_message.idle == true )
            {
               if( m_value_changed == true )
               {
                  user_configuration.store();
                  m_value_changed = false;
               }

               m_edit_mode = navigate_menu;
            }
         }
      }      
      else if( (command == command_step) ||
               (command == command_enter) )
      {
         uint8_t new_value =
            user_configuration.get_parameter_value( m_parameter_number ) + 1;

         if( new_value > user_configuration.get_parameter_maximum( m_parameter_number ) )
         {
            new_value = user_configuration.get_parameter_minimum( m_parameter_number );
         }

         user_configuration.set_parameter_value( m_parameter_number, new_value );

         m_value_changed = true;

         m_edit_value_submode = count_not_yet_displayed;
      }
   }
}
