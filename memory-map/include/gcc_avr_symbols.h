#ifndef GCC_AVR_SYMBOLS_H
#define GCC_AVR_SYMBOLS_H

#include <stdint.h>



extern uint8_t *_end;
extern uint8_t *__eeprom_end;
extern uint8_t *__trampolines_start;
extern uint8_t *__ctors_end;
extern uint8_t *__trampolines_end;
extern uint8_t *__dtors_start;
extern uint8_t *__trampolines_start;
extern uint8_t *__ctors_start;
extern uint8_t *__dtors_end;
extern uint8_t *__init;
extern uint8_t *__do_copy_data;
extern uint8_t *__do_clear_bss;
extern uint8_t *do_clear_bss_loop;
extern uint8_t *do_clear_bss_start;
extern uint8_t *__vector_17;
extern uint8_t *__vector_1;
extern uint8_t *__vector_8;
extern uint8_t * __vector_20;
extern uint8_t *__vector_14;
extern uint8_t *__vector_16;
extern uint8_t *__vector_21;
extern uint8_t *__vector_4;
extern uint8_t *__vector_19;
extern uint8_t *__vector_9;
extern uint8_t *__vector_3;
extern uint8_t *__vector_18;
extern uint8_t *__vector_12;
extern uint8_t *__vector_10;
extern uint8_t *__bad_interrupt;
extern uint8_t *__vector_6;
extern uint8_t *__vector_13;
extern uint8_t *__vector_15;
extern uint8_t *__vector_24;
extern uint8_t *__vector_5;
extern uint8_t *__vector_7;
extern uint8_t *__vector_22;
extern uint8_t *__vector_25;
extern uint8_t *__vector_2;
extern uint8_t *__vector_23;
extern uint8_t *__vector_11;
extern uint8_t *__ultoa_invert;
extern uint8_t *__stop_program;
extern uint8_t *_etext;
extern uint8_t *__vectors;
extern uint8_t *__vector_default;
extern uint8_t *__EEPROM_REGION_LENGTH__;
extern uint8_t *__TEXT_REGION_LENGTH__;
extern uint8_t *__TEXT_REGION_ORIGIN__;
extern uint8_t *__heap_end;
extern uint8_t *__zero_reg__;
extern uint8_t *__SP_L__;
extern uint8_t *__SP_H__;
extern uint8_t *__SREG__;
extern uint8_t *__DATA_REGION_ORIGIN__;
extern uint8_t *__data_start;
extern uint8_t *__bss_start;
extern uint8_t *_edata;
extern uint8_t *__data_end;
extern uint8_t *__bss_end;
extern uint8_t *__LOCK_REGION_LENGTH__;
extern uint8_t *__data_load_start;
extern uint8_t *__stack;
extern uint8_t *__data_load_end;

#endif // GCC_AVR_SYMBOLS_H


