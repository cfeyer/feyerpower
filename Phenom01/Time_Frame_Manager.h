/*
 * Time_Frame_Manager.h
 *
 * Created: 7/6/2013 5:31:37 PM
 *  Author: Chris
 */ 


#ifndef TIME_FRAME_MANAGER_H_
#define TIME_FRAME_MANAGER_H_


class Time_Frame_Manager
{
   public:

      static void enable_frame_generation();

      static void wait_for_top_of_frame();

   private:

      Time_Frame_Manager(); // Disallow
};


#endif /* TIME_FRAME_MANAGER_H_ */