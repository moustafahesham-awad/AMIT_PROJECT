/*
 * spi.c
 *
 * Created: 3/14/2021 8:24:33 PM
 *  Author: LENOVO
 */ 
#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "spi.h"
void SCK_Frequency(char CLOCK)
{
	if (CLOCK==0)
	{
		SPCR&=~((1<<SPI2X)|(1<<SPR1)|(1<<SPR0));
	}
	else if (CLOCK==1)
	{
		SPCR&=~((1<<SPI2X)|(1<<SPR1));
		SPCR|=(1<<SPR0);
	}
	else if (CLOCK==2)
	{
		SPCR&=~((1<<SPI2X)|(1<<SPR0));
		SPCR|=(1<<SPR1);
	}
	else if (CLOCK==3)
	{
		SPCR&=~(1<<SPI2X);
		SPCR|=((1<<SPR1)|(1<<SPR0));
	}
	else if (CLOCK==4)
	{
		SPCR|=(1<<SPI2X);
		SPCR&=~((1<<SPR1)|(1<<SPR0));
	}
	else if (CLOCK==5)
	{
		SPCR|=(1<<SPI2X)|(1<<SPR0);
		SPCR&=~(1<<SPR1);
	}
	else if (CLOCK==6)
	{
		SPCR|=(1<<SPI2X)|(1<<SPR1);
		SPCR&=~(1<<SPR0);
	}
	else if (CLOCK==7)
	{
		SPCR|=((1<<SPI2X)|(1<<SPR1)|(1<<SPR0));
	}
}
void master_or_slave(char mode)
{
	if (mode==master)
	{
		SPCR|=(1<<MSTR);
	}
	else if (mode==slave)
	{
		SPCR&=(1<<MSTR);
	}
}
void data_order(char send)
{
	if (send==1)
	{
		
		SPCR&=~(1<<DORD);
	}
	
	else 
	{
		
		SPCR|=(1<<DORD);
	}
}
void transmiter(unsigned char data)
{	
	SPDR=data;
	while(!(SPSR&(1<<SPIF)));
}
void recive(void)
{
	DDRB|=(1<<6);
	SPCR|=(1<<SPIE); // ENABLE INTERRUPT
}
void initial_spi(char CLOCK,char send)
{
	DDRB|=(1<<4)|(1<<5)|(1<<7);
	SCK_Frequency(CLOCK);
	SPCR|=(1<<MSTR);//MASTER
	SPCR|=(1<<SPE);
	
	
	
}



