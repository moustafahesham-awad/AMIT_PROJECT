/*
 * spi.c
 *
 * Created: 3/14/2021 8:23:54 PM
 * Author : LENOVO
 */ 
#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "spi.h"
#include "UART.h"
ISR(USART_RXC_vect)
{
	char data = UDR;
	if (data == 'a')
	{ 
		PORTC|=(1<<0);
		PORTC&=~((1<<1)|(1<<2));
		_delay_ms(10);
		transmiter('a');
		_delay_ms(50);
		
	}
	else if (data=='b')
	{
		PORTC|=(1<<1);
		PORTC&=~((1<<0)|(1<<2));
		_delay_ms(10);
		transmiter('b');
		_delay_ms(50);
	}
	else if (data=='c')
	{
		PORTC|=(1<<2);
		PORTC&=~((1<<0)|(1<<1));
		_delay_ms(10);
		transmiter('c');
		_delay_ms(50); 
	}
}


int main(void)
{
	initial_spi(3,1);
	initial_receiver (9600);
	DDRA&=~((1<<7)|(1<<6)|(1<<5));
	DDRC|=(1<<0)|(1<<1)|(1<<2);
  
  sei();
    while (1) 
    {
		if (PINA&(1<<7))
		{
			_delay_ms(10);
			transmiter('a');
			_delay_ms(50);
		}
		else if (PINA&(1<<6))
		{
			_delay_ms(10);
			transmiter('b');
			_delay_ms(50);
		}
		else if (PINA&(1<<5))
		{
			_delay_ms(10);
			transmiter('c');
			_delay_ms(50);
		}
	
		
   }
}

