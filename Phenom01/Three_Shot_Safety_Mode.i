/*
 * Three_Shot_Safety_Mode.cpp
 *
 * Created: 6/22/2013 9:48:24 AM
 *  Author: Chris
 */ 

#include <avr/io.h>
#include "Bit_Ops.h"


#define TRIGGER_REPITITION_WINDOW_TO_ENABLE_ENHANCED_MODE_MS 1000

template <const Trigger_Message & trigger_message>
Three_Shot_Safety_Mode<trigger_message>::Three_Shot_Safety_Mode( Firing_Mode_Interface * const p_default_mode,
                                                Firing_Mode_Interface * const p_enhanced_mode ) :
   m_state( state_enhanced_ineligible ),
   mp_default_mode( p_default_mode ),
   mp_enhanced_mode( p_enhanced_mode )
{
   reset();
}


template <const Trigger_Message & trigger_message>
void Three_Shot_Safety_Mode<trigger_message>::set_policy( Enhanced_Firing_Mode_Guard_Policy::Enum policy )
{
   if( policy == Enhanced_Firing_Mode_Guard_Policy::immediate )
   {
      m_state = state_enhanced_active_permanent;
   }
   else
   {
      m_state = state_enhanced_ineligible;
   }

   reset();
}


template <const Trigger_Message & trigger_message>
void Three_Shot_Safety_Mode<trigger_message>::periodic_update_1_ms(void)
{
   if( m_first_pull_timeout_ms != 0 )
   {
      m_first_pull_timeout_ms--;
   }

   if( m_second_pull_timeout_ms != 0 )
   {
      m_second_pull_timeout_ms--;
   }

   bool timed_out = (m_first_pull_timeout_ms == 0) ||
                    (m_second_pull_timeout_ms == 0);


   if( m_state == state_enhanced_ineligible )
   {
      if( timed_out == false )
      {
         m_state = state_enhanced_eligible;
      }
   }

   if( m_state == state_enhanced_eligible )
   {
      if( timed_out == false )
      {
         if( (trigger_message.transitioned == true ) &&
             (trigger_message.debounced_position == Trigger_Position::released) )
         {
            m_state = state_enhanced_active_temporary;
            mp_enhanced_mode->reset();
         }
      }
      else
      {
         m_state = state_enhanced_ineligible;
      }
   }

   if( m_state == state_enhanced_active_temporary )
   {
      if( timed_out == true )
      {
         m_state = state_enhanced_ineligible;
         mp_default_mode->reset();
      }
   }

   if( (m_state == state_enhanced_active_temporary) ||
       (m_state == state_enhanced_active_permanent) )
   {
      mp_enhanced_mode->periodic_update_1_ms();

      if( trigger_message.debounced_position == Trigger_Position::pulled )
      {
         m_first_pull_timeout_ms = TRIGGER_REPITITION_WINDOW_TO_ENABLE_ENHANCED_MODE_MS;
         m_second_pull_timeout_ms = TRIGGER_REPITITION_WINDOW_TO_ENABLE_ENHANCED_MODE_MS;
      }
   }
   else
   {
      mp_default_mode->periodic_update_1_ms();
   }

   if( (trigger_message.debounced_position == Trigger_Position::pulled) &&
       (trigger_message.transitioned == true) )
   {
      m_first_pull_timeout_ms = m_second_pull_timeout_ms;
      m_second_pull_timeout_ms = TRIGGER_REPITITION_WINDOW_TO_ENABLE_ENHANCED_MODE_MS;
   } 
}

template <const Trigger_Message & trigger_message>
void Three_Shot_Safety_Mode<trigger_message>::reset()
{
   m_first_pull_timeout_ms = 0;
   m_second_pull_timeout_ms = 0;
   mp_default_mode->reset();
   mp_enhanced_mode->reset();
}
