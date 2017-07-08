/*
 * Trigger_Status.cpp
 *
 * Created: 6/22/2013 12:38:18 PM
 *  Author: Chris
 */ 

#include "Trigger_Message.h"

Trigger_Message::Trigger_Message() :
   debounced_position( Trigger_Position::released ),
   transitioned( false ),
   time_in_present_state_ms( 0 ),
   time_in_previous_state_ms( 0 )
{
}