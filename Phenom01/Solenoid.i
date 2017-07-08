/*
 * Solenoid.cpp
 *
 * Created: 6/21/2013 6:30:10 PM
 *  Author: Chris
 */ 

#include "Phenom_IO.h"
#include "Bit_Ops.h"

template <const Solenoid_Message & solenoid_message_in,
          Light_Message & light_message>
Solenoid<solenoid_message_in, light_message>::Solenoid() :
   m_dwell_remaining_ms( 0 ),
   m_dwell_interval_ms( 8 )
{
   // Configure the solenoid pin as an output
   CLEAR_BIT( PHENOM_SOLENOID_PORT, PHENOM_SOLENOID_BIT );
   SET_BIT( PHENOM_SOLENOID_DDR, PHENOM_SOLENOID_BIT );

//   // Configure the solenoid arm pin as an output
//   CLEAR_BIT( PHENOM_SOLENOID_ARM_PORT_REG, PHENOM_SOLENOID_ARM_BIT );
//   SET_BIT( PHENOM_SOLENOID_ARM_DDR_REG,  PHENOM_SOLENOID_ARM_BIT );
}


template <const Solenoid_Message & solenoid_message_in,
          Light_Message & light_message>
void Solenoid<solenoid_message_in, light_message>::periodic_update_1_ms()
{
   // Arm the solenoid once we begin cycling the solenoid logic
   //SET_BIT( PHENOM_SOLENOID_ARM_PORT_REG, PHENOM_SOLENOID_ARM_BIT );

   if( m_dwell_remaining_ms != 0 )
   {
      m_dwell_remaining_ms--;
   }

   if( m_dwell_remaining_ms == 0 )
   {
      if( solenoid_message_in.command == Solenoid_Command::initiate_firing )
      {
         SET_BIT( PHENOM_SOLENOID_PORT, PHENOM_SOLENOID_BIT );
         m_dwell_remaining_ms = m_dwell_interval_ms;
      }
      else
      {
         CLEAR_BIT( PHENOM_SOLENOID_PORT, PHENOM_SOLENOID_BIT );
      }  
   }

   if( m_dwell_remaining_ms != 0 )
   {
      light_message.light_state = Light_State::orange;
   }
}


template <const Solenoid_Message & solenoid_message_in,
          Light_Message & light_message>
void Solenoid<solenoid_message_in, light_message>::set_dwell_time_ms( uint8_t dwell_time_ms )
{
   if( (2 <= dwell_time_ms) && (dwell_time_ms <= 20) )
   {
      m_dwell_interval_ms = dwell_time_ms;
   }
}
