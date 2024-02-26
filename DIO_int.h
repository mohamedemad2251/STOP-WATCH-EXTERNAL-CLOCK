#ifndef DIO_INT_H_
#define DIO_INT_H_
#include "STD_types.h"
#include "DIO_priv.h"

void DIO_voidSetPinDir(u8 DIO_u8Port, u8 DIO_u8Pin, u8 DIO_u8Dir);
void DIO_voidSetPortDir(u8 DIO_u8Port, u8 DIO_u8Dir);

void DIO_voidSetPinVal(u8 DIO_u8Port, u8 DIO_u8Pin, u8 DIO_u8Val);
void DIO_voidSetPortVal(u8 DIO_u8Port,u8 Dio_u8Val);

u8 DIO_u8GetPinVal(u8 DIO_u8Port, u8 DIO_u8Pin);
u8 DIO_u8GetPortVal(u8 DIO_u8Port);

#endif
