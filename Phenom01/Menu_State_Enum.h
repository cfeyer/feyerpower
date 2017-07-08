/*
 * Menu_State_Enum.h
 *
 * Created: 7/4/2013 3:56:33 PM
 *  Author: Chris
 */ 


#ifndef MENU_STATE_ENUM_H_
#define MENU_STATE_ENUM_H_


namespace Menu_State
{

enum Enum
{
   disabled,
   highlight_dwell_time,
   configure_dwell_time,
   highlight_debounce_time,
   configure_debounce_time,
   highlight_full_auto_rate,
   configure_full_auto_rate,
   highlight_firing_mode,
   configure_firing_mode,
   highlight_three_shot_safety,
   configure_three_shot_safety
};

} // namespace Menu_State


#endif /* MENU_STATE_ENUM_H_ */