/*
 * Runtime_State_Manager.cpp
 *
 * Created: 7/6/2013 6:12:01 PM
 *  Author: Chris
 */ 


#define RSM_DURATION_HOLD_BUTTON_FOR_CONFIG_MS 2000

template <Runtime_State_Message & runtime_state_message,
          Light_Message & light_message,
          const Pushbutton_Message & pushbutton_message>
Runtime_State_Manager<runtime_state_message, light_message, pushbutton_message>::Runtime_State_Manager()
{
}


template <Runtime_State_Message & runtime_state_message,
          Light_Message & light_message,
          const Pushbutton_Message & pushbutton_message>
void Runtime_State_Manager<runtime_state_message, light_message, pushbutton_message>::periodic_update_1_ms()
{
   if( pushbutton_message.position == Pushbutton_Position::pressed )
   {
      if( pushbutton_message.time_in_present_state_ms >= RSM_DURATION_HOLD_BUTTON_FOR_CONFIG_MS )
      {
         light_message.light_state = Light_State::red;
      }
      else
      {
         light_message.light_state = Light_State::green;
      }
   }
   else if( (pushbutton_message.position == Pushbutton_Position::released) &&
            (pushbutton_message.time_in_previous_state_ms >= RSM_DURATION_HOLD_BUTTON_FOR_CONFIG_MS) )
   {
      runtime_state_message.state = Runtime_State::configure;
      light_message.light_state = Light_State::off;
   }
   else
   {
      runtime_state_message.state = Runtime_State::shoot;
      light_message.light_state = Light_State::off;
   }
}
