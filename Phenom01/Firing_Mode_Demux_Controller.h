/*
 * Firing_Mode_Demux_Controller.h
 *
 * Created: 7/5/2013 12:32:03 PM
 *  Author: Chris
 */ 


#ifndef FIRING_MODE_DEMUX_CONTROLLER_H_
#define FIRING_MODE_DEMUX_CONTROLLER_H_

#include "Pushbutton_Message.h"
#include "Firing_Mode_Demux.h"
#include "Number_Flasher_Command_Message.h"


template <const Pushbutton_Message & pushbutton_message,
          Firing_Mode_Demux & firing_mode_demux,
          Number_Flasher_Command_Message & number_command_message>
class Firing_Mode_Demux_Controller
{
   public:

      Firing_Mode_Demux_Controller(void);
      void periodic_update_1_ms(void);

   private:

      bool m_issued_number_flasher_command;
};

#include "Firing_Mode_Demux_Controller.i"

#endif /* FIRING_MODE_DEMUX_CONTROLLER_H_ */