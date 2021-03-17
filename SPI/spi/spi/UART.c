/*
 * UART.c
 *
 * Created: 3/15/2021 11:22:19 AM
 *  Author: LENOVO
 */ 
#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "UART.h"
void Baud_Rate(unsigned char buad)
{
	int X =(F_CPU/(16.0/buad))-1;
	UBRRL=(char) X;
	UBRRH=(X>>8);
	
	
}
void UART_transmiter(unsigned char data)
{
	
	while(!(UCSRA&(1<<UDRE)));
	UDR=data;
	
	
}
void initial_TRANSMIT (unsigned char buad)
{
	// enable transmiter
	UCSRB|=(1<<TXEN);
	//BUAD RATE
	Baud_Rate( buad);
	

	
	
}
void initial_receiver (unsigned char buad)
{
	// enable receiver
	UCSRB|=(1<<RXEN);
	//BUAD RATE
	Baud_Rate( buad);
	// enable receiver interrupt 
	UCSRB|=(1<<RXCIE);
	
	
}

