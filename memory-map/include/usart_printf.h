#ifndef USART_PRINTF_H
#define USART_PRINTF_H
#include <stdio.h>

/*
In gcc-avr ABI;
All address pointers occurs for SRAM.
0x0 means 0x1000
0x3ff means 0x13ff
0x1f0 means 0x101f0
..
No direct memory access to :
GPIO registers
I/O registers
Extended I/O registers
Flash/Program memory
EEPROM memory
*/
#define SRAM_END 0xffff // 0x8ff0
#define SRAM_BEGIN 0x1000

#define FLASH_END 0x3fff
#define FLASH_BEGIN 0x0

#define EEPROM_END 0x3ff
#define EEPROM_BEGIN 0x0

/*
 * Load Program Memory.
 * The Program memory is organized in
 * 16-bit words while the Z-pointer is a byte address.
 * This instruction can address the first 64KB of Program memory.
 */
#define __load_program_memory__(addr)         \
    (__extension__({                          \
        uint16_t __addr16 = (uint16_t)(addr); \
        uint8_t __result;                     \
        __asm__ __volatile__(                 \
            "lpm %0, Z"                       \
            "\n\t"                            \
            : "=r"(__result)                  \
            : "z"(__addr16));                 \
        __result;                             \
    }))

extern void usart_initialize(void);
extern void usart_send_byte(char byte, FILE *stream);
extern char usart_get_byte(FILE *stream);

FILE uart_output = FDEV_SETUP_STREAM(usart_send_byte, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, usart_get_byte, _FDEV_SETUP_READ);

#endif // USART_PRINTF_H