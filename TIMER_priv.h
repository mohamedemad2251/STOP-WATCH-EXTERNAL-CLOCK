#ifndef TIMER_PRIV_H_

#define TIMER_PRIV_H_

#define TCCR0A	*((volatile u8*)0x44)
#define WGM00	0
#define WGM01	1
#define COM0B0	4
#define COM0B1	5
#define COM0A0	6
#define COM0A1	7

#define TCNT0	*((volatile u8*)0x46)
#define OCR0A	*((volatile u8*)0x47)

#define TIFR0	*((volatile u8*)0x35)
#define TOV0 0
#define OCF0A 1
#define OCF0B 2

#define TCCR0B	*((volatile u8*)0x45)
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM02	3
#define FOC0B	6
#define FOC0A	7

#define TIMSK0	*((volatile u8*)0x6E)
#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2

#endif