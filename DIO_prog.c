#include "BIT_Math.h"
#include "DIO_int.h"
#include "DIO_priv.h"

void DIO_voidSetPinDir(u8 DIO_u8Port, u8 DIO_u8Pin, u8 DIO_u8Dir)
{
	switch(DIO_u8Port)
	{
		case DIO_DDRB:
			if( (DIO_u8Dir) && (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) )
			{
				SET_BIT(DDRB,DIO_u8Pin);
			}
			else if( (!DIO_u8Dir) && (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) )
			{
				CLEAR_BIT(DDRB,DIO_u8Pin);
			}
			break;
		case DIO_DDRC:
			if( (DIO_u8Dir) && (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) )
			{
				SET_BIT(DDRC,DIO_u8Pin);
			}
			else if( (!DIO_u8Dir) && (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) )
			{
				CLEAR_BIT(DDRC,DIO_u8Pin);
			}
			break;
		case DIO_DDRD:
			if( (DIO_u8Dir) && (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) )
			{
				SET_BIT(DDRD,DIO_u8Pin);
			}
			else if( (!DIO_u8Dir) && (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) )
			{
				CLEAR_BIT(DDRD,DIO_u8Pin);
			}
			break;
		default: break;
	}
}

void DIO_voidSetPortDir(u8 DIO_u8Port, u8 DIO_u8Dir)
{
	if( (DIO_u8Dir == DIO_LOW) || (DIO_u8Dir == DIO_HIGH) )
	{
		for(int i=0;i<8;i++)
		{
			DIO_voidSetPinDir(DIO_u8Port,i,DIO_u8Dir);
		}
	}
}

void DIO_voidSetPinVal(u8 DIO_u8Port, u8 DIO_u8Pin, u8 DIO_u8Val)
{
	if( (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) && (DIO_u8Val) )
	{
		switch(DIO_u8Port)
		{
			case DIO_PORTB:
				SET_BIT(PORTB,DIO_u8Pin);
				break;
			case DIO_PORTC:
				SET_BIT(PORTC,DIO_u8Pin);
				break;
			case DIO_PORTD:
				SET_BIT(PORTD,DIO_u8Pin);
				break;
			default: break;
		}
	}
	else if( (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) && (!DIO_u8Val) )
	{
		switch(DIO_u8Port)
		{
			case DIO_PORTB:
			CLEAR_BIT(PORTB,DIO_u8Pin);
			break;
			case DIO_PORTC:
			CLEAR_BIT(PORTC,DIO_u8Pin);
			break;
			case DIO_PORTD:
			CLEAR_BIT(PORTD,DIO_u8Pin);
			break;
			default: break;
		}
	}
}

void DIO_voidSetPortVal(u8 DIO_u8Port,u8 DIO_u8Val)
{
	switch(DIO_u8Port)
	{
		case 1: PORTB = DIO_u8Val;
			break;
		case 2: PORTC = DIO_u8Val;
			break;
		case 3: PORTD = DIO_u8Val;
			break;
	}
}

u8 DIO_u8GetPinVal(u8 DIO_u8Port, u8 DIO_u8Pin)
{
	if( (DIO_u8Pin >= PORT_START) && (DIO_u8Pin <= PORT_END) )
	{
		switch(DIO_u8Port)
		{
			case DIO_PINB:
				return GET_BIT(PINB,DIO_u8Pin);
				break;
			case DIO_PINC:
				return GET_BIT(PINC,DIO_u8Pin);
				break;
			case DIO_PIND:
				return GET_BIT(PIND,DIO_u8Pin);
				break;
			default: return -1;
				break;
		}
	}
	return -1;
}

u8 DIO_u8GetPortVal(u8 DIO_u8Port)
{
	switch(DIO_u8Port)
	{
		case DIO_PINB: return PINB;
			break;
		case DIO_PINC: return PINC;
			break;
		case DIO_PIND: return PIND;
			break;
		default: return -1;
			break;
	}
}