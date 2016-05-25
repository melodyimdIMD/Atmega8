/*
 * uart.c
 *
 * Created: 2016/5/23 13:18:35
 *  Author: ljq51
 */ 

#include <avr/io.h>

#define FOSC 11059200// Clock Speed
#define BAUD 115200
#define MYUBRR FOSC/16/BAUD-1
/*********************************************************
 *                                                       *
 *                                                       *
 *********************************************************/
void USART_Init() {
  unsigned int ubrr = MYUBRR;
  /* Set baud rate */
  UBRRH = (unsigned char)(ubrr >> 8);
  UBRRL = (unsigned char)ubrr;
  /* Enable receiver and transmitter */
  UCSRB = (1 << RXEN) | (1 << TXEN);
  /* Set frame format: 8data, 2stop bit */
  UCSRC = (1 << URSEL) | (1 << USBS) | (3 << UCSZ0);
}
/*********************************************************
 *                                                       *
 *                                                       *
 *********************************************************/
void USART_Transmit(unsigned char data) {
  /* Wait for empty transmit buffer */
  while (!(UCSRA & (1 << UDRE)))
    ;
  /* Put data into buffer, sends the data */
  UDR = data;
}