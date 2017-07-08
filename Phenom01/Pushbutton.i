/*
 * Pushbutton.cpp
 *
 * Created: 6/21/2013 6:34:20 PM
 *  Author: Chris
 */ 

#include "Phenom_IO.h"
#include "Bit_Ops.h"

#include "Debug_Pin.h"

template <Pushbutton_Message & pushbutton_message>
Pushbutton<pushbutton_message>::Pushbutton() :
   m_previous_position( Pushbutton_Position::released ),
   m_time_in_present_state_ms( 0 ),
   m_time_in_previous_state_ms( 0 )
{
   // Configure pushbbutton pin as input
   SET_BIT( MARKER_PUSHBUTTON_PORT_REG, MARKER_PUSHBUTTON_PORT_BIT );
   CLEAR_BIT( MARKER_PUSHBUTTON_DD_REG, MARKER_PUSHBUTTON_DD_BIT );
}


template <Pushbutton_Message & pushbutton_message>
void Pushbutton<pushbutton_message>::periodic_update_1_ms()
{
   if( GET_BIT( MARKER_PUSHBUTTON_PIN_REG, MARKER_PUSHBUTTON_PIN_BIT ) == MARKER_PUSHBUTTON_PRESSED_VAL )
   {
      pushbutton_message.position = Pushbutton_Position::pressed;
   }
   else
   {
      pushbutton_message.position = Pushbutton_Position::released;
   }

   if( pushbutton_message.position != m_previous_position )
   {
      pushbutton_message.transitioned = true;
      m_time_in_previous_state_ms = m_time_in_present_state_ms;
      m_time_in_present_state_ms = 0;
   }
   else
   {
      pushbutton_message.transitioned = false;
   }

   pushbutton_message.time_in_present_state_ms = m_time_in_present_state_ms;
   pushbutton_message.time_in_previous_state_ms = m_time_in_previous_state_ms;

   m_previous_position = pushbutton_message.position;

   if( m_time_in_present_state_ms < 0xFFFF )
   {
      m_time_in_present_state_ms++;
   }
}