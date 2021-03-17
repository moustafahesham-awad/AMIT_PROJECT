/*
 * GccApplication1.c
 *
 * Created: 3/14/2021 10:26:00 PM
 * Author : LENOVO
 */ 
#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "spi_slave.h"
ISR(SPI_STC_vect)
{
	
	char data =SPDR;
	if (data=='a')
	{
		PORTC|=(1<<0);
		PORTC&=~(1<<1);
		PORTC&=~(1<<2);
		
	}
	else if (data=='b')
	{
		PORTC&=~(1<<0);
		PORTC|=(1<<1);
		PORTC&=~(1<<2);
	}
	else if (data=='c')
	{
		PORTC&=~(1<<0);
		PORTC&=~(1<<1);
		PORTC|=(1<<2);
	}

}


int main(void)
{
	DDRC|=(1<<0)|(1<<1)|(1<<2);
	initial_spi(4,slave,1);
	recive();
	
	
    sei();// gloable interrupt
    while (1) 
    {
    }
}

