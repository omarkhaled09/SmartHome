/*
* UART.c
*
* Created: 2/13/2021 9:11:14 PM
*  Author: karim
*/


#include "UART.h"
#include "LED.h"

void UART_Init(void)
{
	/*Baud rate value variable*/
	Uint16t UBRR_Val = 0;
	/*Enable Transmitter and Receiver bits*/
	UCSRB = (1 << RXEN) | (1 << TXEN);
	/*Full configuration for UART*/
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	/*Baud Rate Calculations*/
	UBRR_Val = (((FRQ) / (16UL * BAUDRATE)) - 1);//00000000 11110101 00111001
	UBRRL = UBRR_Val;//00111001
	UBRRH = UBRR_Val >> 8;//11110101
}
void UART_Transmit(Uint8t data)
{
	UDR = data;
	while (GET_BIT(UCSRA, TXC) != 1);
}
Uint8t UART_Receive(void)
{
	
	while (GET_BIT(UCSRA, RXC) != 1);
	return UDR;
}

UART_Status UART_RECEIVE(Uint8t* data)
{
	while (GET_BIT(UCSRA, RXC) != 1);
	*data = UDR;
	return UART_OK;
}
