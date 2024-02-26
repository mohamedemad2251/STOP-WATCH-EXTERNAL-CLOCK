#include "KEYPAD_int.h"
#include "DIO_int.h"
#include "KEYPAD_config.h"

void KEYPAD_voidInit()
{
	DIO_voidSetPinDir(KEYPAD_PORT_ROW,KEYPAD_Row_0,DIO_OUTPUT);
	DIO_voidSetPinDir(KEYPAD_PORT_ROW,KEYPAD_Row_1,DIO_OUTPUT);
	DIO_voidSetPinDir(KEYPAD_PORT_ROW,KEYPAD_Row_2,DIO_OUTPUT);
	DIO_voidSetPinDir(KEYPAD_PORT_ROW,KEYPAD_Row_3,DIO_OUTPUT);
	DIO_voidSetPinDir(KEYPAD_PORT_COLUMN,KEYPAD_Column_0,DIO_INPUT);
	DIO_voidSetPinDir(KEYPAD_PORT_COLUMN,KEYPAD_Column_1,DIO_INPUT);
	DIO_voidSetPinDir(KEYPAD_PORT_COLUMN,KEYPAD_Column_2,DIO_INPUT);
	DIO_voidSetPinDir(KEYPAD_PORT_COLUMN,KEYPAD_Column_3,DIO_INPUT);
	DIO_voidSetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_0,DIO_HIGH);
	DIO_voidSetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_1,DIO_HIGH);
	DIO_voidSetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_2,DIO_HIGH);
	DIO_voidSetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_3,DIO_HIGH);
}

u8 KEYPAD_u8GetButton()
{
	static u8 debounce_column_0 = 0;
	static u8 debounce_flag_0 = 0;
	static u8 debounce_column_1 = 0;
	static u8 debounce_flag_1 = 0;
	static u8 debounce_column_2 = 0;
	static u8 debounce_flag_2 = 0;
	static u8 debounce_column_3 = 0;
	static u8 debounce_flag_3 = 0;
	for(int i=0;i<4;i++)
	{
		switch(i)
		{
			case 0: 
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_0,DIO_LOW);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_1,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_2,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_3,DIO_HIGH);
				if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_0))
				{
					debounce_column_0++;
					debounce_column_1 = 0;
					debounce_column_2 = 0;
					debounce_column_3 = 0;
					debounce_flag_1 = 0;
					debounce_flag_2 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_0 == 4 && !debounce_flag_0)
					{
						debounce_flag_0 = 1;
						return '7';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_1))
				{
					debounce_column_1++;
					debounce_column_0 = 0;
					debounce_column_2 = 0;
					debounce_column_3 = 0;
					debounce_flag_0 = 0;
					debounce_flag_2 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_1 == 4 && !debounce_flag_1)
					{
						debounce_flag_1 = 1;
						return '8';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_2))
				{
					debounce_column_2++;
					debounce_column_1 = 0;
					debounce_column_0 = 0;
					debounce_column_3 = 0;
					debounce_flag_0 = 0;
					debounce_flag_1 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_2 == 4 && !debounce_flag_2)
					{
						debounce_flag_2 = 1;
						return '9';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_3))
				{
					debounce_column_3++;
					debounce_column_1 = 0;
					debounce_column_2 = 0;
					debounce_column_0 = 0;
					debounce_flag_0 = 0;
					debounce_flag_1 = 0;
					debounce_flag_2 = 0;
					if(debounce_column_3 == 4 && !debounce_flag_3)
					{
						debounce_flag_3 = 1;
						return '/';
					}
					else
					{
						return '\0';
					}
				}
				break;
			case 1:
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_0,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_1,DIO_LOW);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_2,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_3,DIO_HIGH);
				if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_0))
				{
					debounce_column_0++;
					debounce_column_1 = 0;
					debounce_column_2 = 0;
					debounce_column_3 = 0;
					debounce_flag_1 = 0;
					debounce_flag_2 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_0 == 4 && !debounce_flag_0)
					{
						debounce_flag_0 = 1;
						return '4';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_1))
				{
					debounce_column_1++;
					debounce_column_0 = 0;
					debounce_column_2 = 0;
					debounce_column_3 = 0;
					debounce_flag_0 = 0;
					debounce_flag_2 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_1 == 4 && !debounce_flag_1)
					{
						debounce_flag_1 = 1;
						return '5';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_2))
				{
					debounce_column_2++;
					debounce_column_1 = 0;
					debounce_column_0 = 0;
					debounce_column_3 = 0;
					debounce_flag_0 = 0;
					debounce_flag_1 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_2 == 4 && !debounce_flag_2)
					{
						debounce_flag_2 = 1;
						return '6';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_3))
				{
					debounce_column_3++;
					debounce_column_1 = 0;
					debounce_column_2 = 0;
					debounce_column_0 = 0;
					debounce_flag_0 = 0;
					debounce_flag_1 = 0;
					debounce_flag_2 = 0;
					if(debounce_column_3 == 4 && !debounce_flag_3)
					{
						debounce_flag_3 = 1;
						return 'x';
					}
					else
					{
						return '\0';
					}
				}
				break;
			case 2:
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_0,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_1,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_2,DIO_LOW);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_3,DIO_HIGH);
				if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_0))
				{
					debounce_column_0++;
					debounce_column_1 = 0;
					debounce_column_2 = 0;
					debounce_column_3 = 0;
					debounce_flag_1 = 0;
					debounce_flag_2 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_0 == 4 && !debounce_flag_0)
					{
						debounce_flag_0 = 1;
						return '1';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_1))
				{
					debounce_column_1++;
					debounce_column_0 = 0;
					debounce_column_2 = 0;
					debounce_column_3 = 0;
					debounce_flag_0 = 0;
					debounce_flag_2 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_1 == 4 && !debounce_flag_1)
					{
						debounce_flag_1 = 1;
						return '2';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_2))
				{
					debounce_column_2++;
					debounce_column_1 = 0;
					debounce_column_0 = 0;
					debounce_column_3 = 0;
					debounce_flag_0 = 0;
					debounce_flag_1 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_2 == 4 && !debounce_flag_2)
					{
						debounce_flag_2 = 1;
						return '3';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_3))
				{
					debounce_column_3++;
					debounce_column_1 = 0;
					debounce_column_2 = 0;
					debounce_column_0 = 0;
					debounce_flag_0 = 0;
					debounce_flag_1 = 0;
					debounce_flag_2 = 0;
					if(debounce_column_3 == 4 && !debounce_flag_3)
					{
						debounce_flag_3 = 1;
						return '-';
					}
					else
					{
						return '\0';
					}
				}
				break;
			case 3:
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_0,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_1,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_2,DIO_HIGH);
				DIO_voidSetPinVal(KEYPAD_PORT_ROW,KEYPAD_Row_3,DIO_LOW);
				if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_0))
				{
					debounce_column_0++;
					debounce_column_1 = 0;
					debounce_column_2 = 0;
					debounce_column_3 = 0;
					debounce_flag_1 = 0;
					debounce_flag_2 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_0 == 4 && !debounce_flag_0)
					{
						debounce_flag_0 = 1;
						return 'c';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_1))
				{
					debounce_column_1++;
					debounce_column_0 = 0;
					debounce_column_2 = 0;
					debounce_column_3 = 0;
					debounce_flag_0 = 0;
					debounce_flag_2 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_1 == 4 && !debounce_flag_1)
					{
						debounce_flag_1 = 1;
						return '0';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_2))
				{
					debounce_column_2++;
					debounce_column_1 = 0;
					debounce_column_0 = 0;
					debounce_column_3 = 0;
					debounce_flag_0 = 0;
					debounce_flag_1 = 0;
					debounce_flag_3 = 0;
					if(debounce_column_2 == 4 && !debounce_flag_2)
					{
						debounce_flag_2 = 1;
						return '=';
					}
					else
					{
						return '\0';
					}
				}
				else if(!DIO_u8GetPinVal(KEYPAD_PORT_COLUMN,KEYPAD_Column_3))
				{
					debounce_column_3++;
					debounce_column_1 = 0;
					debounce_column_2 = 0;
					debounce_column_0 = 0;
					debounce_flag_0 = 0;
					debounce_flag_1 = 0;
					debounce_flag_2 = 0;
					if(debounce_column_3 == 4 && !debounce_flag_3)
					{
						debounce_flag_3 = 1;
						return '+';
					}
					else
					{
						return '\0';
					}
				}
				break;
		}
	}
	debounce_flag_0 = 0;
	debounce_flag_1 = 0;
	debounce_flag_2 = 0;
	debounce_flag_3 = 0;
	return '\0';
}
