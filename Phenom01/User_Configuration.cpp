/*
 * User_Configuration.cpp
 *
 * Created: 6/21/2013 6:47:16 PM
 *  Author: Chris
 */ 

#include "User_Configuration.h"
#include <avr/eeprom.h>

#define CONFIG_ADDR_IN_EEPROM 0


User_Configuration::User_Configuration()
{
   m_values[PARAM_FIRING_MODE] = 1;
   m_values[PARAM_DWELL_TIME] = 8;
   m_values[PARAM_DEBOUNCE_TIME] = 52;
   m_values[PARAM_FULL_AUTO_BPS] = 13;
   m_values[PARAM_ENHANCED_POLICY] = 0;

   m_mins[PARAM_FIRING_MODE] = 0;
   m_mins[PARAM_DWELL_TIME] = 2;
   m_mins[PARAM_DEBOUNCE_TIME] = 25;
   m_mins[PARAM_FULL_AUTO_BPS] = 8;
   m_mins[PARAM_ENHANCED_POLICY] = 0;

   m_maxes[PARAM_FIRING_MODE] = 4;
   m_maxes[PARAM_DWELL_TIME] = 20;
   m_maxes[PARAM_DEBOUNCE_TIME] = 65;
   m_maxes[PARAM_FULL_AUTO_BPS] = 15;
   m_maxes[PARAM_ENHANCED_POLICY] = 1;
}


void User_Configuration::load()
{
   eeprom_read_block( &m_values,
                      CONFIG_ADDR_IN_EEPROM,
                      sizeof(m_values) );

   bool all_within_range = true;

   for( int i = 0; i < PARAM_COUNT; i++ )
   {
      bool within_range = (m_mins[i] <= m_values[i]) &&
                          (m_values[i] <= m_maxes[i]);

      if( within_range == false )
      {
         all_within_range = false;
      }
   }

   if( all_within_range == false )
   {
      *this = User_Configuration();
   }
}


void User_Configuration::store() const
{
   eeprom_write_block( &m_values,
                       CONFIG_ADDR_IN_EEPROM,
                       sizeof(m_values) );
}


uint8_t User_Configuration::get_parameter_count() const
{
   return PARAM_COUNT;
}


uint8_t User_Configuration::get_parameter_value( uint8_t parameter_number ) const
{
   return m_values[parameter_number];
}


void User_Configuration::set_parameter_value( uint8_t parameter_number, uint8_t value )
{
   m_values[parameter_number] = value;
}


uint8_t User_Configuration::get_parameter_minimum( uint8_t parameter_number ) const
{
   return m_mins[parameter_number];
}


uint8_t User_Configuration::get_parameter_maximum( uint8_t parameter_number ) const
{
   return m_maxes[parameter_number];
}

