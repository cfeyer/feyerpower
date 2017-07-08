/*
 * User_Configuration.h
 *
 * Created: 6/21/2013 6:46:54 PM
 *  Author: Chris
 */ 


#include <stdint.h>
#include "Firing_Modes_Enum.h"
#include "Enhanced_Firing_Mode_Guard_Policy_Enum.h"


#ifndef USER_CONFIGURATION_H_
#define USER_CONFIGURATION_H_

#include <stdint.h>

#define PARAM_FIRING_MODE     0
#define PARAM_DWELL_TIME      1
#define PARAM_DEBOUNCE_TIME   2
#define PARAM_FULL_AUTO_BPS   3
#define PARAM_ENHANCED_POLICY 4

#define PARAM_COUNT           5

class User_Configuration
{
   public:

      User_Configuration();

      void load();
      void store() const;

      uint8_t get_parameter_count() const;
      uint8_t get_parameter_value( uint8_t parameter_number ) const;
      void set_parameter_value( uint8_t parameter_number, uint8_t value );
      uint8_t get_parameter_minimum( uint8_t parameter_number ) const;
      uint8_t get_parameter_maximum( uint8_t parameter_number ) const;

   private:

      uint8_t m_values[PARAM_COUNT];
      uint8_t m_mins[PARAM_COUNT];
      uint8_t m_maxes[PARAM_COUNT];
};


#endif /* USER_CONFIGURATION_H_ */