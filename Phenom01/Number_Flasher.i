/*
 * Number_Flasher.cpp
 *
 * Created: 7/7/2013 7:43:53 AM
 *  Author: Chris
 */ 


#define NF_LIT_DURATION_MS  400
#define NF_DARK_DURATION_MS 400
#define NF_PREAMBLE_COLOR Light_State::orange

template <const Number_Flasher_Command_Message & number_command_message,
          Number_Flasher_Status_Message & number_status_message,
          Light_Message & light_message>
Number_Flasher<number_command_message, number_status_message, light_message>::Number_Flasher() :
   m_state( idle ),
   m_time_left_in_current_state_ms( 0 ),
   m_count_remaining( 0 ),
   m_count_color( Light_State::off )
{
}

template <const Number_Flasher_Command_Message & number_command_message,
          Number_Flasher_Status_Message & number_status_message,
          Light_Message & light_message>
void Number_Flasher<number_command_message, number_status_message, light_message>::periodic_update_1_ms()
{
   if( number_command_message.transitioned == true )
   {
      m_state = preamble_dark_1;
      m_time_left_in_current_state_ms = NF_DARK_DURATION_MS;
      m_count_remaining = number_command_message.number;
      m_count_color = number_command_message.color;
   }

   switch( m_state )
   {
      case idle:
      {
         break;
      }

      case preamble_dark_1:
      {
         light_message.light_state = Light_State::off;

         if( m_time_left_in_current_state_ms == 0 )
         {
            m_state = preamble_lit;
            m_time_left_in_current_state_ms = NF_LIT_DURATION_MS;
         }

         break;
      }

      case preamble_lit:
      {
         light_message.light_state = NF_PREAMBLE_COLOR;

         if( m_time_left_in_current_state_ms == 0 )
         {
            m_state = preamble_dark_2;
            m_time_left_in_current_state_ms = NF_DARK_DURATION_MS;
         }

         break;
      }

      case preamble_dark_2:
      {
         light_message.light_state = Light_State::off;

         if( m_time_left_in_current_state_ms == 0 )
         {
            if( m_count_remaining != 0 )
            {
               m_state = count_lit;
               m_time_left_in_current_state_ms = NF_LIT_DURATION_MS;
            }
            else
            {
               m_state = idle;
            }
         }

         break;
      }

      case count_lit:
      {
         light_message.light_state = m_count_color;

         if( m_time_left_in_current_state_ms == 0 )
         {
            m_state = count_dark;
            m_time_left_in_current_state_ms = NF_DARK_DURATION_MS;
         }

         break;
      }

      case count_dark:
      {
         light_message.light_state = Light_State::off;

         if( m_time_left_in_current_state_ms == 0 )
         {
            m_count_remaining--;

            if( m_count_remaining != 0 )
            {
               m_state = count_lit;
               m_time_left_in_current_state_ms = NF_LIT_DURATION_MS;
            }
            else
            {
               m_state = idle;
            }            
         }
         break;
      }

      default:
      {
         m_state = idle;
         break;
      }
   }

   if( m_time_left_in_current_state_ms != 0 )
   {
      m_time_left_in_current_state_ms--;
   }

   number_status_message.idle = (m_state == idle);
}