/*
 * spi.h
 *
 * Created: 3/14/2021 8:25:01 PM
 *  Author: LENOVO
 */ 


#ifndef SPI_H_
#define SPI_H_
// Oscillator Frequency
#define frq_4 0
#define frq_16 1
#define frq_64 2
#define frq_128 3
#define frq_2 4
#define frq_8 5
#define frq_32 6
//MASTER OR SALVE
#define master 1
#define slave 2
// DATA ORDER
#define MSB_FIRST 1
#define LSB_FIRST 2
void SCK_Frequency(char CLOCK);;
void master_or_slave(char mode);
void data_order(char send);
void transmiter(unsigned char data);
void recive(void);
void initial_spi(char frq,char send);






#endif /* SPI_H_ */