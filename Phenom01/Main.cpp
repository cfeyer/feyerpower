/*
 * CPPFile1.cpp
 *
 * Created: 6/22/2013 8:07:57 AM
 *  Author: Chris
 */ 

#include "Trigger.h"
#include "Solenoid.h"
#include "Pushbutton.h"
#include "Lights.h"
#include "User_Configuration.h"
#include "Firing_Modes_Enum.h"
#include "Three_Shot_Burst_Firing_Mode.h"
#include "Full_Auto_Firing_Mode.h"
#include "Auto_Response_Firing_Mode.h"
#include "Turbo_Firing_Mode.h"
#include "Semi_Auto_Firing_Mode.h"
#include "Firing_Mode_Demux.h"
#include "Three_Shot_Safety_Mode.h"
#include "Trigger_Message.h"
#include "Solenoid_Command_Enum.h"
#include "Solenoid_Message.h"
#include "Enhanced_Firing_Mode_Guard_Policy_Enum.h"
#include "Pushbutton_Message.h"
#include "Phenom_IO.h"
#include "Battery_Message.h"
#include "Battery.h"
#include "Debug_Pin.h"
#include "Menu.h"
#include "Light_Message.h"
#include "Firing_Mode_Demux_Controller.h"
#include "Time_Frame_Manager.h"
#include "Runtime_State_Message.h"
#include "Runtime_State_Manager.h"
#include "Factory_Reset.h"
#include "Number_Flasher.h"
#include "Number_Flasher_Command_Message.h"
#include "Number_Flasher_Status_Message.h"

Runtime_State_Message runtime_state_message;
Trigger_Message trigger_message;
Solenoid_Message solenoid_message;
Pushbutton_Message pushbutton_message;
Light_Message light_message;
Number_Flasher_Command_Message number_command_message;
Number_Flasher_Status_Message number_status_message;

Trigger<trigger_message> trigger;

Solenoid<solenoid_message, light_message> solenoid;

Pushbutton<pushbutton_message> pushbutton;

Lights<light_message> lights;

Battery<light_message> battery;

User_Configuration user_configuration;

Three_Shot_Burst_Firing_Mode<trigger_message, solenoid_message> three_shot_burst_firing_mode;

Full_Auto_Firing_Mode<trigger_message, solenoid_message> full_auto_firing_mode;

Auto_Response_Firing_Mode<trigger_message, solenoid_message> auto_response_firing_mode;

Turbo_Firing_Mode<trigger_message, solenoid_message> turbo_firing_mode;

Semi_Auto_Firing_Mode<trigger_message, solenoid_message> semi_auto_firing_mode;

Firing_Mode_Demux firing_mode_demux( &three_shot_burst_firing_mode,
                                     &full_auto_firing_mode,
                                     &auto_response_firing_mode,
                                     &turbo_firing_mode,
                                     &semi_auto_firing_mode );

Three_Shot_Safety_Mode<trigger_message> three_shot_safety_mode( &semi_auto_firing_mode, &firing_mode_demux );

Menu<trigger_message, number_status_message, number_command_message, user_configuration> menu;

Firing_Mode_Demux_Controller<pushbutton_message, firing_mode_demux, number_command_message> firing_mode_demux_controller;

Runtime_State_Manager<runtime_state_message, light_message, pushbutton_message> runtime_state_manager;

Factory_Reset<pushbutton_message, light_message, user_configuration, runtime_state_message> factory_reset;

Number_Flasher<number_command_message, number_status_message, light_message> number_flasher;

void load_and_apply_configuration(void);

int main(void)
{
   load_and_apply_configuration();
   Time_Frame_Manager::enable_frame_generation();

   // Reduce noise
   //SET_BIT( DDRA, DDA4 ); CLEAR_BIT( PORTA, PA4 ); // Pin 9
   //SET_BIT( DDRA, DDA1 ); CLEAR_BIT( PORTA, PA1 ); // Pin
   //SET_BIT( DDRA, DDA2 ); CLEAR_BIT( PORTA, PA2 ); // Pin

   while( true )
   {  
      Time_Frame_Manager::wait_for_top_of_frame();
   
      switch( runtime_state_message.state )
      {
         case Runtime_State::undecided:
         {
            pushbutton.periodic_update_1_ms();
            runtime_state_manager.periodic_update_1_ms();
            lights.periodic_update_1_ms();
            break;
         }

         case Runtime_State::shoot:
         {
            solenoid.periodic_update_1_ms(); // Jitter sensitive; do first for best determinism
            trigger.periodic_update_1_ms();
            firing_mode_demux_controller.periodic_update_1_ms();
            three_shot_safety_mode.periodic_update_1_ms();
            pushbutton.periodic_update_1_ms();
            lights.periodic_update_1_ms();
            battery.periodic_update_1_ms();
            number_flasher.periodic_update_1_ms();
            break;
         }

         case Runtime_State::configure:
         {
            trigger.periodic_update_1_ms();
            pushbutton.periodic_update_1_ms();
            menu.periodic_update_1_ms();
            number_flasher.periodic_update_1_ms();
            factory_reset.periodic_update_1_ms();
            lights.periodic_update_1_ms();
            break;
         }

         case Runtime_State::reboot_required:
         default:
         {
            lights.periodic_update_1_ms();
            break;
         }
      }
   }

   return 0;
}


void load_and_apply_configuration(void)
{
   user_configuration.load();

   solenoid.set_dwell_time_ms( user_configuration.get_parameter_value(PARAM_DWELL_TIME) );
   full_auto_firing_mode.set_balls_per_second( user_configuration.get_parameter_value(PARAM_FULL_AUTO_BPS) );
   trigger.set_debounce_time_ms( user_configuration.get_parameter_value(PARAM_DEBOUNCE_TIME) );
   firing_mode_demux.set_mode_by_index( user_configuration.get_parameter_value(PARAM_FIRING_MODE) );
   three_shot_safety_mode.set_policy(
      static_cast<Enhanced_Firing_Mode_Guard_Policy::Enum>(user_configuration.get_parameter_value(PARAM_ENHANCED_POLICY)) );
}
