#ifndef USART_CONST_H
#define USART_CONST_H

#define BAUD_RATE 9600
#define F_CPU 16000000UL
#define BAUD_PRESCALE (F_CPU / 16 / BAUD_RATE - 1)

#endif