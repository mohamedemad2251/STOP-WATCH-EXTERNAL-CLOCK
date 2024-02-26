#define STOPWATCH_START 4	//To avoid magical numbers, this definition holds the starting cursor point on the LCD
#define STOPWATCH_END 11	//This definition holds the ending cursor point on the LCD

#ifndef F_CPU                                       // Crystal Frequency
#define F_CPU 8000000UL // 8 MHz clock speed		// Crystal Frequency
#endif
#include "TIMER_int.h"                              // Libraries
#include <stdlib.h>
#include "DIO_int.h"
#include "KEYPAD_int.h"
#include "ALCD.H"
//int8_t sec ;

enum MODE	//Enum, for readability
{
	SEC,
	MIN,
	HR
};

char buffer[10];	//Shows string on LCD
u8 character;		//Stores KEYPAD button clicks
u8 sec = 0;			//Numerical value of seconds entered by user
u8 sec_array[2] = {0,0};	//Holds tenth and units of seconds
u8 min = 0;			//Numerical value of mins entered by user
u8 min_array[2] = {0,0};	//Holds tenth and units of mins
u8 hour = 0;		//Numerical value of hours entered by user
u8 hour_array[2] = {0,0};	//Holds tenth and units of hours
u8 stopwatch_cursor = STOPWATCH_END - 1;	//Start with the tenth of the seconds
u8 skip_count = 0;	//Used to circulate between seconds, mins and hours. Due to the existence of ":"
u8 enable = SEC;	//Used to circulate between seconds, mins and hours. To assign the entered number to variables.
u8 locked = 0;		//Locks the program, can only be cleared by holding "c"
u8 resetted = 0;	//Boolean to see if the program was resetted or not

void STOPWATCH_reset();	//A function that resets the stopwatch

int main()
{
	DIO_voidSetPinDir(DIO_DDRD,5,DIO_OUTPUT);
	DIO_voidSetPinVal(DIO_PORTD,5,DIO_LOW);
	TIMER_voidInit();	
	KEYPAD_voidInit();
	lcd_init(16);
	lcd_gotoxy(4,0);
	lcd_puts("00:00:00");
	lcd_gotoxy(0,1);
	while (1)
	{
		resetted = 0;
		character = KEYPAD_u8GetButton();
		if(character != '\0' && character != '/' && character != 'x' && character != '-' && character != '+' && character != '=' && character != 'c')
		{
			lcd_gotoxy(stopwatch_cursor,0);
			if(!locked)
			{
				if( ( character == '6' || character == '7' || character == '8' || character == '9' ) && ( skip_count == 0 ) )
				{
					//DO NOTHING
				}
				else
				{
					lcd_putchar(character);
					switch(enable)
					{
						case SEC:
						if(skip_count == 0)
						{
							buffer[0] = character;
							sec_array[1] = atoi(buffer);
						}
						else if(skip_count == 1)
						{
							buffer[0] = character;
							sec_array[0] = atoi(buffer);
						}
						break;
						case MIN:
						if(skip_count == 0)
						{
							buffer[0] = character;
							min_array[1] = atoi(buffer);
						}
						else if(skip_count == 1)
						{
							buffer[0] = character;
							min_array[0] = atoi(buffer);
						}
						break;
						case HR:
						if(skip_count == 0)
						{
							buffer[0] = character;
							hour_array[1] = atoi(buffer);
						}
						else if(skip_count == 1)
						{
							buffer[0] = character;
							hour_array[0] = atoi(buffer);
						}
						break;
					}
				}
				
			}
			if(skip_count == 1)
			{
				if(enable != HR)
				{
					stopwatch_cursor -= 4;
					enable++;
					skip_count = 0;
				}
				else
				{
					locked = 1;
				}
				
			}
			else
			{
				if( ( character == '6' || character == '7' || character == '8' || character == '9' ) && ( skip_count == 0 ) )
				{
					
				}
				else
				{
					stopwatch_cursor++;
					skip_count++;
				}
			}
		}
		if(character != '\0' && character == '=')
		{
			resetted = 0;
			sec = (sec_array[1] * 10) + (sec_array[0]);
			min = (min_array[1] * 10) + (min_array[0]);
			hour = (hour_array[1] * 10) + (hour_array[0]);
			for(int k=hour; k>-1;k--)
			{
				if(k >= 10)
				{
					stopwatch_cursor = STOPWATCH_START;
				}
				else
				{
					stopwatch_cursor = STOPWATCH_START;
					lcd_gotoxy(stopwatch_cursor,0);
					lcd_putchar('0');
					stopwatch_cursor = STOPWATCH_START + 1;
				}
				lcd_gotoxy(stopwatch_cursor,0);
				itoa(k, buffer,10);
				lcd_puts(buffer);
				
				for(int j=min; j>-1;j--)
				{
					if(j >= 10)
					{
						stopwatch_cursor = STOPWATCH_END - 4;
					}
					else
					{
						stopwatch_cursor = STOPWATCH_END - 4;
						lcd_gotoxy(stopwatch_cursor,0);
						lcd_putchar('0');
						stopwatch_cursor = STOPWATCH_END - 3;
					}
					lcd_gotoxy(stopwatch_cursor,0);
					itoa(j, buffer,10);
					lcd_puts(buffer);
					
					for(int i=sec;i>-1;i--)
					{
						if(!resetted)
						{
							character = KEYPAD_u8GetButton();
							if(character != '\0' && character == 'c')
							{
								STOPWATCH_reset();
								resetted = 1;
							}
							if(i >= 10)
							{
								stopwatch_cursor = STOPWATCH_END - 1;
							}
							else
							{
								stopwatch_cursor = STOPWATCH_END-1;
								lcd_gotoxy(stopwatch_cursor,0);
								lcd_putchar('0');
								stopwatch_cursor = STOPWATCH_END;
							}
							lcd_gotoxy(stopwatch_cursor,0);
							itoa(i, buffer,10);
							lcd_puts(buffer);
							TIMER_voidDelayBySec(1);
							character = KEYPAD_u8GetButton();
							if(character != '\0' && character == 'c')
							{
								STOPWATCH_reset();
								resetted = 1;
							}
						}
					}
					sec = 59;
				}
				min = 59;
			}
			locked = 1;
			while(locked && !resetted)
			{
				lcd_clear();
				lcd_gotoxy(4,0);
				character = KEYPAD_u8GetButton();
				if(character == 'c')
				{
					locked = 0;
				}
				lcd_puts("00:00:00");
				DIO_voidSetPinVal(DIO_PORTD,5,DIO_HIGH);
			}
			STOPWATCH_reset();		
		}
		if(character != '\0' && character == 'c')
		{
			STOPWATCH_reset();
			resetted = 1;
		}
	}
}

void STOPWATCH_reset()
{
	buffer [0] = 0;
	buffer [1] = 0;
	locked = 0;
	resetted = 1;
	lcd_clear();
	lcd_gotoxy(4,0);
	lcd_puts("00:00:00");
	stopwatch_cursor = STOPWATCH_END - 1;
	sec = 0;
	sec_array[0] = 0;
	sec_array[1] = 0;
	min = 0;
	min_array[0] = 0;
	min_array[1] = 0;
	hour = 0;
	hour_array[0] = 0;
	hour_array[1] = 0;
	skip_count = 0;
	enable = SEC;
	DIO_voidSetPinVal(DIO_PORTD,5,DIO_LOW);
}