#include "TIMER_int.h"
#include "TIMER_priv.h"
#include "BIT_Math.h"
#include "DIO_int.h"

void TIMER_voidInit()
{
	DIO_voidSetPinDir(DIO_PORTD,4,DIO_INPUT);	//Make T0 as Input.
	SET_BIT(TCCR0A,WGM01);						//CTC
	SET_BIT(TCCR0B,CS02);						// Rising Edge
	SET_BIT(TCCR0B,CS01);
	SET_BIT(TCCR0B,CS00);
	SET_BIT(TIMSK0,OCIE0A);
}

void TIMER_voidDelayBySec(u32 TIMER_u32Sec)
{
	for (u32 j=0 ; j<TIMER_u32Sec ; j++)
	{
		for (u8 i=0 ; i<=1 ; i++)
		{
			SET_BIT(TCCR0A,WGM01);
			SET_BIT(TCCR0B,CS02);
			SET_BIT(TCCR0B,CS01);
			SET_BIT(TCCR0B,CS00);
			SET_BIT(TIMSK0,OCIE0A);
			OCR0A = (0x30);
			while(!GET_BIT(TIFR0,OCF0A));
			SET_BIT(TIFR0,OCF0A);
		}
	}
}
