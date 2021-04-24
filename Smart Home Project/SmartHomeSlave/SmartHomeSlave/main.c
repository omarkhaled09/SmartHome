/*
 * SmartHomeSlave.c
 *
 * Created: 4/21/2021 8:57:57 PM
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

	LED0_Initialize();
	LED1_Initialize();
	LED2_Initialize();
	LCD_Init();
	SPI_Init();
	Uint8t Datarecieve =0;
	LCD_Write_Number(Datarecieve);
	while (1)
	{
		Datarecieve=SPI_Receive();
		if (Datarecieve=='a')
		{	
			LED0_ON();
		}
		else if (Datarecieve=='b')
		{
			LED0_OFF();
		}
		else if (Datarecieve=='c')
		{
			LED1_ON();
		}
		else if (Datarecieve=='d')
		{
			LED1_OFF();
		}
		else if (Datarecieve=='e')
		{
			LED2_ON();
		}
		else if (Datarecieve=='f')
		{
			LED2_OFF();
		}
		LCD_Clear();
		LCD_Write_Number(Datarecieve);
		
	}
}

