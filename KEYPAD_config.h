#ifndef KEYPAD_CONFIG_H_

#define KEYPAD_CONFIG_H_
#include "DIO_priv.h"

//OPTIONS : 
//			DIO_PORTB
//			DIO_PORTC
//			DIO_PORTD
#define KEYPAD_PORT_ROW DIO_PORTD
#define KEYPAD_PORT_COLUMN DIO_PORTC

//OPTIONS CONFIGURE THE PIN NUMBERS YOU CONNECTED THE KEYPAD ON HERE
#define KEYPAD_Row_0 0
#define KEYPAD_Row_1 1
#define KEYPAD_Row_2 2
#define KEYPAD_Row_3 3
#define KEYPAD_Column_0 0
#define KEYPAD_Column_1 1
#define KEYPAD_Column_2 2
#define KEYPAD_Column_3 3

#endif