/*
 * SmartHomeMaster.c
 *
 * Created: 4/21/2021 8:44:01 PM
 * Author : Dell
 */ 

#include <avr/io.h>
#include "UART.h"
#include "LED.h"
#include "LCD.h"
#include "SPI.h"
int main(void)
{
	/* Replace with your application code */
	UART_Init();
	LED0_Initialize();
	LCD_Init();
	SPI_Init();
	SPI_SlaveSelect(0);
	uint8_t DataSent =0;
	LCD_Write_Number(DataSent);
	while (1)
	{
		DataSent = UART_Receive();
		SPI_Transmit(DataSent);
		if (DataSent=='a')
		{
			LED0_ON();
		}
		else if (DataSent=='b')
		{	
			LED0_OFF();
		}
		
		LCD_Clear();
		LCD_Write_Number(DataSent);
		//SPI_Transmit(DataSent);
	}
}

