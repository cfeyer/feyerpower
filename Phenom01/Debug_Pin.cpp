/*
 * Debug_Pin.cpp
 *
 * Created: 7/3/2013 10:40:27 PM
 *  Author: Chris
 */ 

#include "Debug_Pin.h"

#include <avr/io.h>
#include "Bit_Ops.h"

void Debug_Pin::init()
{
   SET_BIT( DDRA, DDA3 );
   CLEAR_BIT( PORTA, PORTA3 );
}

void Debug_Pin::set()
{
   SET_BIT( PORTA, PORTA3 );
}

void Debug_Pin::clear()
{
   CLEAR_BIT( PORTA, PORTA3 );
}