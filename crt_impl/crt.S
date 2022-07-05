
.section .init,"ax",@progbits
.global __start
__start:

; init stack
eor	r1, r1 ; clear r1
out	0x3f, r1 ; set 0x3f into r1
ldi	r28, 0xFF ; load r28 with 0xFF
ldi	r29, 0x08 ; load r29 with 0x08
out	0x3e, r29	
out	0x3d, r28	
rjmp __do_copy_data
rjmp __do_clear_bss
jmp main



.global __do_copy_data
__do_copy_data:
	ldi	r17, hi8(_e_data) ; load r17 with _e_data high byte 

	; X register set for SRAM : r27:r26
	ldi	r26, lo8(_s_data) ; load r26 with _s_data low byte 
	ldi	r27, hi8(_s_data) ; load r27 with _s_data high byte 

	; Z register set for FLASH : r31:r30
	ldi	r30, lo8(__data_load_start) ; load r30 with __data_load_start low byte 
	ldi	r31, hi8(__data_load_start) ; load r31 with __data_load_start high byte 
    
	rjmp	.L__do_copy_data_start

.L__do_copy_data_loop:
	lpm	r0, Z+ ; load program memory(FLASH) from r0 and into r0 then increase Z register
	st	X+, r0 ; store r0 value into SRAM location which is pointed by X register then increase X register
	
.L__do_copy_data_start:
	cpi	r26, lo8(_e_data) ; compare r26 with _e_data low bytes 
	cpc	r27, r17 ; compare r27 with r17 high bytes
	brne	.L__do_copy_data_loop
	rjmp	main
  	jmp	exit
	


.global __do_clear_bss
__do_clear_bss :
	ldi	r18, hi8(_e_bss) 

	; X register set for SRAM : r27:r26
	ldi	r26, lo8(_s_bss)
	ldi	r27, hi8(_s_bss)
	rjmp	.Ldo_clear_bss_start
.Ldo_clear_bss_loop:
	st	X+, r1
.Ldo_clear_bss_start:
	cpi	r26, lo8(_e_bss)
	cpc	r27, r18
	brne	.Ldo_clear_bss_loop

