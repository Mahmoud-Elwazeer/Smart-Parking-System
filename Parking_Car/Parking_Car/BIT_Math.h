/*
 * BIT_Math.h
 *
 * Created: 10/12/2022 11:24:54 PM
 *  Author: Elwazeer
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg , bit)           reg |= (1<<bit)
#define CLEAR_BIT(reg , bit)         reg &= ~(1<<bit)
#define TOGGLE_BIT(reg , bit)        reg ^= (1<<bit)
#define GET_BIT(reg, bit)            ((reg>>bit) & 0x01)



#endif /* BIT_MATH_H_ */