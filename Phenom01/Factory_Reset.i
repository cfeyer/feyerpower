/*
 * Factory_Reset.cpp
 *
 * Created: 7/6/2013 7:13:50 PM
 *  Author: Chris
 */ 

#define FACTORY_RESET_BUTTON_HOLD_TIME_MS 10000

template <const Pushbutton_Message & pushbutton_message,
          Light_Message & light_message,
          User_Configuration & user_configuration,
          Runtime_State_Message & runtime_state_message>
Factory_Reset<pushbutton_message, light_message, user_configuration, runtime_state_message>::Factory_Reset()
{
}


template <const Pushbutton_Message & pushbutton_message,
          Light_Message & light_message,
          User_Configuration & user_configuration,
          Runtime_State_Message & runtime_state_message>
void Factory_Reset<pushbutton_message, light_message, user_configuration, runtime_state_message>::periodic_update_1_ms()
{
   if( pushbutton_message.position == Pushbutton_Position::pressed )
   {
      if( pushbutton_message.time_in_present_state_ms < FACTORY_RESET_BUTTON_HOLD_TIME_MS)
      {
         light_message.light_state = Light_State::red;
      }
      else
      {
         user_configuration = User_Configuration();
         user_configuration.store();
         light_message.light_state = Light_State::green_red;
         runtime_state_message.state = Runtime_State::reboot_required;
      }         
   }
}
