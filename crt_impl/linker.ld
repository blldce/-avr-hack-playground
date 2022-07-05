

__TEXT_REGION_LENGTH__   =    DEFINED(__TEXT_REGION_LENGTH__) ? __TEXT_REGION_LENGTH__ : 32K;
__DATA_REGION_LENGTH__   =    DEFINED(__DATA_REGION_LENGTH__) ? __DATA_REGION_LENGTH__ : 0xFFFF;
__EEPROM_REGION_LENGTH__ =    DEFINED(__EEPROM_REGION_LENGTH__) ? __EEPROM_REGION_LENGTH__ : 64K;
__STACK_LENGTH__           =  DEFINED(__STACK_LENGTH__) ? __STACK_LENGTH__ : 4K;
/* The starting point of stack, at bottom of the SRAM*/
 _stack_top = ORIGIN(DATA_IN_FLASH) + LENGTH(DATA_IN_FLASH) - 1; 

__data_load_start = LOADADDR (.data); 
__data_load_end = (__data_load_start + SIZEOF (.data)); 

MEMORY
{
  CODE_IN_FLASH  (rwx)  : ORIGIN = 0x0000000000000000, LENGTH =   0x0000000000020000
  DATA_IN_FLASH  (rw!x) : ORIGIN = 0x0000000000800000, LENGTH =   0x000000000000ffa0
  EEPROM         (rw!x) : ORIGIN = 0x0000000000810000, LENGTH =   0x0000000000010000
}


ENTRY(__start)


SECTIONS
{


  .text : 
    {
      *(.init)  
       _s_text = .;  
       *(.text*)
       _e_text = .;
       _s_rodata = .;
      *(.rodata*)
      _e_rodata = .;
    } > CODE_IN_FLASH


    .data : 
    {
        _s_data = .;
       /* __data_load_start = .; */
        *(.data*)
         _e_data = .;
         /* __data_load_end = .; */
    } > CODE_IN_FLASH 



/* bss must be set to all zero's */
  .bss : 
    {
        _s_bss = .;
        *(.bss*)
        _e_bss = .;
        _s_heap = .;
    } > DATA_IN_FLASH



}


