#ifndef DIO_PRIV_H_

#define DDRB    *((volatile u8*)0x24)
#define DDRC    *((volatile u8*)0x27)
#define DDRD    *((volatile u8*)0x2A)

#define PORTB   *((volatile u8*)0x25)
#define PORTC   *((volatile u8*)0x28)
#define PORTD   *((volatile u8*)0x2B)

#define PINB    *((volatile u8*)0x23)
#define PINC    *((volatile u8*)0x26)
#define PIND    *((volatile u8*)0x29)

#define DIO_DDRB 1
#define DIO_DDRC 2
#define DIO_DDRD 3

#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PINB 1
#define DIO_PINC 2
#define DIO_PIND 3

#define DIO_LOW 0
#define DIO_HIGH 1

#define PORT_START 0
#define PORT_END 7

#define DIO_INPUT 0
#define DIO_OUTPUT 1

#endif