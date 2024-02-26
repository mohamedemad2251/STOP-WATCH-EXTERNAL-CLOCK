#ifndef TIMER_INT_H_

#define TIMER_INT_H_
#include "STD_types.h"

void TIMER_voidInit();
void TIMER_voidDelayBySec(u32 TIMER_u32Sec);
void TIMER_voidSetOCR0A(u8 TIMER_u8Val);

#endif