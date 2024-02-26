#ifndef BIT_MATH_H_

#define BIT_MATH_H_

#define GET_BIT(var,bit) (var>>bit)&0b00000001
#define SET_BIT(var,bit) var=(var)|(1<<bit)
#define CLEAR_BIT(var,bit) var=(var)&(~(1<<bit))

#endif