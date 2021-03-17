/*
 * spi_slave.h
 *
 * Created: 3/14/2021 10:26:51 PM
 *  Author: LENOVO
 */ 


#ifndef SPI_SLAVE_H_
#define SPI_SLAVE_H_
// Oscillator Frequency
#define frq_4 1
#define frq_16 2
#define frq_64 3
#define frq_128 4
#define frq_2 5
#define frq_8 6
#define frq_32 7
//MASTER OR SALVE
#define master 1
#define slave 0
// DATA ORDER
#define MSB_FIRST 1
#define LSB_FIRST 2
void Oscillator_Frequency(char frq);
void master_or_slave(char mode);
void data_order(char send);
void transmiter(char data);
void recive(void);
void initial_spi(char frq,char mode,char send);




#endif /* SPI_SLAVE_H_ */