/*
 * Firing_Mode_Demux.h
 *
 * Created: 6/22/2013 9:42:05 AM
 *  Author: Chris
 */ 


#ifndef FIRING_MODE_DEMUX_H_
#define FIRING_MODE_DEMUX_H_


#include "Firing_Mode_Interface.h"
#include <stdint.h>

class Firing_Mode_Demux : public Firing_Mode_Interface
{
   public:

      Firing_Mode_Demux( Firing_Mode_Interface * p_mode_0,
                         Firing_Mode_Interface * p_mode_1,
                         Firing_Mode_Interface * p_mode_2,
                         Firing_Mode_Interface * p_mode_3,
                         Firing_Mode_Interface * p_mode_4 );

      void periodic_update_1_ms(void);
      void reset(void);

      void select_next_mode(void);

      void set_mode_by_index( uint8_t mode_index );

      uint8_t get_mode_index() const;

   private:

      static const uint8_t m_mode_count = 5;
      uint8_t m_active_mode_index;
      Firing_Mode_Interface * m_firing_mode_ptrs[m_mode_count];
};

#endif /* FIRING_MODE_DEMUX_H_ */