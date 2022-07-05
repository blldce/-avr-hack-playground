#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "include/usart_printf.h"
#include "include/gcc_avr_symbols.h"
#include <avr/eeprom.h>

static void avr_gcc_default_symbols();
static void init_uart();
static void write_sram();
static void dump_sram();
static void dump_flash();
static void dump_eeprom();
static void write_eeprom(uint8_t *, uint8_t);

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    printf("\nI am called first");
}

void calledLast()
{
    printf("\nI am called last");
}

int main(void)
{
    init_uart();
}

static void dump_flash()
{
    uint8_t *addr = (uint8_t *)(FLASH_BEGIN);

    printf("***************** BEGIN FLASH *****************\n");
    for (;;)
    {
        printf("Flash Addr: %p - val: %x \n", addr, __load_program_memory__(*((uint8_t *)addr)));
        if (++addr == ((void *)(FLASH_END)))
        {
            printf("FLASH END Addr: %p - val: %x \n", addr, __load_program_memory__(*((uint8_t *)addr)));
            break;
        }
        _delay_ms(300);
    }
    printf("***************** END FLASH *****************\n");
}

static void dump_sram()
{
    void *addr = (void *)(SRAM_BEGIN);
    printf("***************** BEGIN *****************\n");
    for (;;)
    {
        printf("SRAM Addr: %p - val: %x \n", addr, *((uint8_t *)addr));

        if (addr == ((void *)(SRAM_END)))
        {
            printf("END  Addr: %p - val: %x \n", addr, *((uint8_t *)addr));
            break;
        }

        addr += 1;
        _delay_ms(200);
    }
    printf("***************** END *****************\n");
}

static void write_sram()
{
    void *addr = (void *)(0x1200);
    //  printf("***************** BEGIN WRITING SRAM *****************\n");
    for (;;)
    {
        // Stores one byte indirect from a register to data space(SRAM).
        *((uint8_t *)addr) = 0x6;
        if (++addr == (void *)(SRAM_END))
        {
            break;
        }
        // printf("Writing SRAM Addr: %p - value: %x \n", addr, *((uint8_t *)addr));
        // _delay_ms(300);
    }
    // printf("***************** END WRITING SRAM *****************\n");
}

static void dump_eeprom()
{
    void *addr = (void *)(EEPROM_BEGIN);
    uint8_t epprom_data;
    printf("***************** BEGIN READING EEPROM *****************\n");
    for (;;)
    {
        epprom_data = eeprom_read_byte(((uint8_t *)addr));
        printf("EEPROM Addr: %p - value: %x \n", addr, epprom_data);
        if (++addr == (void *)(EEPROM_END))
        {
            break;
        }
        _delay_ms(400);
    }
    printf("***************** END OF READING EEPROM *****************\n");
}

static void write_eeprom(uint8_t *__p, uint8_t __value)
{
    eeprom_write_byte(__p, __value);
    printf("***************** END OF WRITING EEPROM *****************\n");
}

static void init_uart()
{
    usart_initialize();
    stdout = &uart_output;
}

static void avr_gcc_default_symbols()
{

    printf("_etext       : %p  \n", _etext);
    printf("__bss_end    : %p  \n", __bss_end);
    printf("__bss_start  : %p  \n", __bss_start);
    printf("__eeprom_end : %p  \n", __eeprom_end);
    printf("__init       : %p  \n", __init);
    printf("__stack      : %p  \n", __stack);
    printf("_edata       : %p  \n", _edata);
    printf("__data_start : %p  \n", __data_start);
    printf("__SP_H__     : %p  \n", __SP_H__);
    printf("__SP_L__     : %p  \n", __SP_L__);

    printf("__heap_end     : %p  \n", __heap_end);
    printf("__data_load_start     : %p  \n", __data_load_start);
}