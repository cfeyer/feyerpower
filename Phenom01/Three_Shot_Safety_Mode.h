/*
 * Three_Shot_Safety_Mode.h
 *
 * Created: 6/22/2013 9:47:32 AM
 *  Author: Chris
 */ 


#ifndef THREE_SHOT_SAFETY_MODE_H_
#define THREE_SHOT_SAFETY_MODE_H_


#include "Firing_Mode_Interface.h"
#include "Trigger_Message.h"
#include <stdint.h>
#include "Enhanced_Firing_Mode_Guard_Policy_Enum.h"


template <const Trigger_Message & trigger_message>
class Three_Shot_Safety_Mode : public Firing_Mode_Interface
{
   public:

      Three_Shot_Safety_Mode( Firing_Mode_Interface * const p_default_mode,
                              Firing_Mode_Interface * const p_enhanced_mode );

      void set_policy( Enhanced_Firing_Mode_Guard_Policy::Enum policy );

      void periodic_update_1_ms(void);
      void reset(void);

   private:

      enum State
      {
         state_enhanced_ineligible,
         state_enhanced_eligible,
         state_enhanced_active_temporary,
         state_enhanced_active_permanent
      };

      State m_state;

      Firing_Mode_Interface * const mp_default_mode;
      Firing_Mode_Interface * const mp_enhanced_mode;

      uint16_t m_first_pull_timeout_ms;
      uint16_t m_second_pull_timeout_ms;
};

#include "Three_Shot_Safety_Mode.i"

#endif /* THREE_SHOT_SAFETY_MODE_H_ */