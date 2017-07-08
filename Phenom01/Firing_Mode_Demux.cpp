/*
 * Firing_Mode_Demux.cpp
 *
 * Created: 6/22/2013 9:43:18 AM
 *  Author: Chris
 */ 


 #include "Firing_Mode_Demux.h"

Firing_Mode_Demux::Firing_Mode_Demux( Firing_Mode_Interface * p_mode_0,
                                      Firing_Mode_Interface * p_mode_1,
                                      Firing_Mode_Interface * p_mode_2,
                                      Firing_Mode_Interface * p_mode_3,
                                      Firing_Mode_Interface * p_mode_4 ) :
   m_active_mode_index( 0 )
{
   m_firing_mode_ptrs[0] = p_mode_0;
   m_firing_mode_ptrs[1] = p_mode_1;
   m_firing_mode_ptrs[2] = p_mode_2;
   m_firing_mode_ptrs[3] = p_mode_3;
   m_firing_mode_ptrs[4] = p_mode_4;
}


void Firing_Mode_Demux::periodic_update_1_ms(void)
{
  m_firing_mode_ptrs[m_active_mode_index]->periodic_update_1_ms();
}


void Firing_Mode_Demux::reset(void)
{
   m_firing_mode_ptrs[m_active_mode_index]->reset();
}


void Firing_Mode_Demux::select_next_mode(void)
{
   m_active_mode_index++;

   if( m_active_mode_index == m_mode_count )
   {
      m_active_mode_index = 0;
   }

   m_firing_mode_ptrs[m_active_mode_index]->reset();
}


void Firing_Mode_Demux::set_mode_by_index( uint8_t mode_index )
{
   if( mode_index <= m_mode_count )
   {
      m_active_mode_index = mode_index;
      m_firing_mode_ptrs[m_active_mode_index]->reset();
   }
}

uint8_t Firing_Mode_Demux::get_mode_index() const
{
   return m_active_mode_index;
}
