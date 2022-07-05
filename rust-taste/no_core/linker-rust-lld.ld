
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