/*
 * Bit_Ops.h
 *
 * Created: 6/22/2013 10:48:10 AM
 *  Author: Chris
 */ 


#ifndef BIT_OPS_H_
#define BIT_OPS_H_


#define SET_BIT( reg, bit_pos ) \
   (reg) |= (1 << (bit_pos))

#define CLEAR_BIT( reg, bit_pos ) \
   (reg) &= ~(1 << (bit_pos))

#define GET_BIT( reg, bit_pos ) \
   ( ((reg) & (1 << (bit_pos))) >> bit_pos )

#define TOGGLE_BIT( reg, bit_pos ) \
   (reg) ^= (1 << (bit_pos))

#endif /* BIT_OPS_H_ */