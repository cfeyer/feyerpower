/*
 * Number_Flasher_Command.cpp
 *
 * Created: 7/7/2013 8:02:31 AM
 *  Author: Chris
 */ 

#include "Number_Flasher_Command_Message.h"

Number_Flasher_Command_Message::Number_Flasher_Command_Message() :
   transitioned( false ),
   number( 0 ),
   color( Light_State::off )
{
}