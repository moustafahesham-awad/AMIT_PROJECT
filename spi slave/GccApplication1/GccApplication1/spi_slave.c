/*
 * spi_slave.c
 *
 * Created: 3/14/2021 10:27:26 PM
 *  Author: LENOVO
 */ 
#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "spi_slave.h"
void Oscillator_Frequency(char frq )
{
	if (frq==1)
	{
		SPCR&=~((1<<SPR0)|(1<<SPR1));
		SPSR&=~(1<<SPI2X);
	}
	else if (frq==2)
	{
		SPCR|=(1<<SPR0);
		SPCR&=~(1<<SPR1);
		SPSR&=~(1<<SPI2X);
	}
	else if (frq==3)
	{
		SPCR|=(1<<SPR1);
		SPCR&=~(1<<SPR0);
		SPSR&=~(1<<SPI2X);
	}
	else if (frq==4)
	{
		SPCR|=((1<<SPR0)|(1<<SPR1));
		SPSR&=~(1<<SPI2X);
		
	}
	else if(frq==5)
	{
		SPCR&=~((1<<SPR0)|(1<<SPR1));
		SPSR|=(1<<SPI2X);
		
	}
	else if (frq==6)
	{
		SPCR|=(1<<SPR0);
		SPCR&=~(1<<SPR1);
		SPSR|=(1<<SPI2X);
	}
	else if(frq==7)
	{
		SPCR&=~(1<<SPR0);
		SPCR|=(1<<SPR1);
		SPSR|=(1<<SPI2X);
	}
}
void master_or_slave(char mode)
{
	switch(mode)
	{
		case master:
		SPCR|=(1<<MSTR);
		break;
		case slave:
		SPCR&=~(1<<MSTR);
		break;
	}
}
void data_order(char send)
{
	
	if (send==1)
	{
		SPCR&=~(1<<DORD);
	}
	
	else if (send==2)
	{
		SPCR|=(1<<DORD);
	}
}
void transmiter(char data)
{
	
	SPDR=data;
	while(!(SPSR&(1<<SPIF)));
}
void recive(void)
{
	
	SPCR|=(1<<SPIE); // ENABLE INTERRUPT
}
void initial_spi(char frq,char mode,char send)
{
	DDRB|=(1<<6);
	SPCR|=(1<<SPE);
	master_or_slave(mode);
	data_order(send);
}