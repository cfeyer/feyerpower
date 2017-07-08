#include "Phenom_IO.h"
#include "Bit_Ops.h"

template <Trigger_Message & trigger_message_out>
Trigger<trigger_message_out>::Trigger() :
   m_debounce_delay_interval_ms( 52 ),
   m_previous_debounced_trigger_position( Trigger_Position::released ),
   m_debounce_delay_remaining_ms( 0 ),
   m_time_in_present_state_ms( 0 ),
   m_time_in_previous_state_ms( 0 )
{
   // Configure trigger pin as input
   CLEAR_BIT( MARKER_TRIGGER_DD_REG, MARKER_TRIGGER_DD_BIT );
   SET_BIT( MARKER_TRIGGER_PORT_REG, MARKER_TRIGGER_PORT_BIT );
}


template <Trigger_Message & trigger_message_out>
void Trigger<trigger_message_out>::periodic_update_1_ms()
{
   if( m_debounce_delay_remaining_ms != 0 )
   {
      m_debounce_delay_remaining_ms--;
   }

   // If trigger appears pulled
   if( GET_BIT( MARKER_TRIGGER_PIN_REG, MARKER_TRIGGER_PIN_BIT ) == MARKER_TRIGGER_PULLED_VAL )
   {
      // If continuation of a previously accepted pull
      if( m_previous_debounced_trigger_position == Trigger_Position::pulled )
      {
         trigger_message_out.debounced_position = Trigger_Position::pulled;
      }
      // If appears to be start of new pull
      else
      {
         // If we've cleared the debounce window from the previous pull
         if( m_debounce_delay_remaining_ms == 0 )
         {
            trigger_message_out.debounced_position = Trigger_Position::pulled;
            m_debounce_delay_remaining_ms = m_debounce_delay_interval_ms;
         }
         // If we haven't cleared the debounce window from the previous pull
         else
         {
            // Ignore this pull and do nothing.
         }
      }
   }
   // If trigger appears released
   else
   {
      // Always allow releasing without delay
      trigger_message_out.debounced_position = Trigger_Position::released;
   }

   if( trigger_message_out.debounced_position != m_previous_debounced_trigger_position )
   {
      trigger_message_out.transitioned = true;
      m_time_in_previous_state_ms = m_time_in_present_state_ms;
      m_time_in_present_state_ms = 0;
   }
   else
   {
      trigger_message_out.transitioned = false;
   }

   trigger_message_out.time_in_present_state_ms = m_time_in_present_state_ms;
   trigger_message_out.time_in_previous_state_ms = m_time_in_previous_state_ms;

   m_previous_debounced_trigger_position = trigger_message_out.debounced_position;
   
   if( m_time_in_present_state_ms < 0xffff )
   {
      m_time_in_present_state_ms++;
   }
}


template <Trigger_Message & trigger_message_out>
void Trigger<trigger_message_out>::set_debounce_time_ms( uint8_t debounce_ms )
{
   if( (25 <= debounce_ms) && (debounce_ms <= 65) )
   {
      m_debounce_delay_interval_ms = debounce_ms;
   }
}
