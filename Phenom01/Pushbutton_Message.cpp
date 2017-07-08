/*
 * Pushbutton_Message.cpp
 *
 * Created: 6/23/2013 5:26:16 AM
 *  Author: Chris
 */ 

#include "Pushbutton_Message.h"

Pushbutton_Message::Pushbutton_Message(void) :
   position( Pushbutton_Position::released ),
   transitioned( false ),
   time_in_present_state_ms( 0 ),
   time_in_previous_state_ms( 0 )
{
}