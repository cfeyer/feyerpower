/*
 * Menu.h
 *
 * Created: 7/4/2013 3:51:20 PM
 *  Author: Chris
 */ 


#ifndef MENU_H_
#define MENU_H_

#include "Menu_State_Enum.h"
#include "Trigger_Message.h"
#include "User_Configuration.h"
#include "Number_Flasher_Command_Message.h"
#include "Number_Flasher_Status_Message.h"


template <const Trigger_Message & trigger_message,
          const Number_Flasher_Status_Message & number_status_message,
          Number_Flasher_Command_Message & number_command_message,
          User_Configuration & user_configuration>
class Menu
{
   public:

      Menu();

      void periodic_update_1_ms(void);

   private:

      Menu_State::Enum m_state;

      enum Menu_Command
      {
         no_command,
         command_step, // short trigger pulls
         command_enter // long trigger pulls
      };

      enum Edit_Mode
      {
         navigate_menu,
         edit_value
      };

      enum Edit_Value_Submodes
      {
         count_not_yet_displayed,
         displaying_count_1,
         displaying_count_2
      };

      uint8_t m_parameter_number;
      Edit_Mode m_edit_mode;
      bool m_issued_number_flasher_command;
      Edit_Value_Submodes m_edit_value_submode;
      bool m_value_changed;
};

#include "Menu.i"

#endif /* MENU_H_ */