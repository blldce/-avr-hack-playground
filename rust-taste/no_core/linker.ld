MEMORY
{
FLASH (rxai!w) : ORIGIN = 0x80000000, LENGTH = 256K
INTRAM (wxa!ri) : ORIGIN = 0x00000004, LENGTH = 0x0000FFFC
USERPAGE : ORIGIN = 0x80800000, LENGTH = 0x00000200
}


ENTRY(my_start)


SECTIONS
{
. = 0x80000000;
.text : { *(.text) }
. = 0x00000000;
.data : { *(.data) }
.rodata : { *(.rodata) }
.bss : { *(.bss) }
}