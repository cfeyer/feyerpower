/*
 * Lights.cpp
 *
 * Created: 6/21/2013 6:44:44 PM
 *  Author: Chris
 */ 

#include "Phenom_IO.h"
#include "Bit_Ops.h"

#define LIGHTS_RED_ON()      SET_BIT( MARKER_RED_LED_PORT_REG,   MARKER_RED_LED_PORT_BIT )
#define LIGHTS_RED_OFF()   CLEAR_BIT( MARKER_RED_LED_PORT_REG,   MARKER_RED_LED_PORT_BIT )
#define LIGHTS_GREEN_ON()    SET_BIT( MARKER_GREEN_LED_PORT_REG, MARKER_GREEN_LED_PORT_BIT )
#define LIGHTS_GREEN_OFF() CLEAR_BIT( MARKER_GREEN_LED_PORT_REG, MARKER_GREEN_LED_PORT_BIT )

template <const Light_Message & light_message>
Lights<light_message>::Lights() :
   m_next_orange_state( orange_green_1 )
{
   // Configure LED pins as outputs
   SET_BIT( MARKER_RED_LED_DD_REG, MARKER_RED_LED_DD_BIT );
   SET_BIT( MARKER_GREEN_LED_DD_REG, MARKER_GREEN_LED_DD_BIT );

   LIGHTS_RED_OFF();
   LIGHTS_GREEN_OFF();
}


template <const Light_Message & light_message>
void Lights<light_message>::periodic_update_1_ms()
{
   switch( light_message.light_state )
   {
      case Light_State::off:
      {
         LIGHTS_RED_OFF();
         LIGHTS_GREEN_OFF();
         break;
      }

      case Light_State::green:
      {
         LIGHTS_RED_OFF();
         LIGHTS_GREEN_ON();
         break;
      }

      case Light_State::red:
      {
         LIGHTS_RED_ON();
         LIGHTS_GREEN_OFF();
         break;
      }

      case Light_State::green_red:
      {
         LIGHTS_RED_ON();
         LIGHTS_GREEN_ON();
         break;
      }

      case Light_State::orange:
      {
         switch( m_next_orange_state )
         {
            case orange_green_1:
            {
               LIGHTS_RED_OFF();
               LIGHTS_GREEN_ON();
               m_next_orange_state = orange_green_2;
               break;
            }

            case orange_green_2:
            {
               LIGHTS_RED_OFF();
               LIGHTS_GREEN_ON();
               m_next_orange_state = orange_red_1;
               break;
            }

            case orange_red_1:
            {
               LIGHTS_RED_ON();
               LIGHTS_GREEN_OFF();
               m_next_orange_state = orange_green_1;
               break;
            }

            default:
            {
               // do nothing
               break;
            }
         }
      }

      default:
      {
         // do nothing
         break;
      }
   }

}