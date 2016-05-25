/*
 * GccApplication1.c
 *
 * Created: 2016/5/23 13:17:59
 * Author : ljq51
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.h"
#include "ILib/io.h"

int main(void)
{
	USART_Init();
	KeyButtonInit();
    /* Replace with your application code */
	iprintf("hello%d",10);
    while (1) 
    {
    }
}

ISR(INT1_vect)
{
	cli();
	for (int i = 0; i <= 0xFF; i++)
	{
		USART_Transmit(i);
	}
	sei();
}
void KeyButtonInit() {
	MCUCR |= (0 << ISC10) | (1 << ISC11);
	GICR |= (1 << INT1);
	sei();
}
