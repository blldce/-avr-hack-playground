#ifndef IO_H
#define IO_H 1

#define DDRD  = 0x0a  // set D register enable bits 
#define PORTD = 0x0b  // set D register output bits
#define PIND  = 0x09  // set D register input bits

#define DDRC  = 0x07  // set C register enable bits 
#define PORTC = 0x08  // set C register output bits
#define PINC  = 0x06  // set C register input bits

#define DDRB  = 0x04  // set B register enable bits
#define PORTB = 0x05  // set B register output bits
#define PINB  = 0x03  // set B register input bits

#define __io_B_output__(value) \
    (__extension__({           \
        __asm__ __volatile__(  \
            "out 0x04, %0\n\t" \
            "out 0x05, %0\n\t" \
            :                  \
            : "r"(value));     \
    }))

#define __io_C_output__(value) \
    (__extension__({           \
        __asm__ __volatile__(  \
            "out 0x07, %0\n\t" \
            "out 0x08, %0\n\t" \
            :                  \
            : "r"(value));     \
    }))

    #define __io_D_output__(value) \
    (__extension__({           \
        __asm__ __volatile__(  \
            "out 0x0a, %0\n\t" \
            "out 0x0b, %0\n\t" \
            :                  \
            : "r"(value));     \
    }))

#endif