compiler :=avr-gcc
flags := -nodevicelib -ffreestanding -nostdlib -nostartfiles -Waddr-space-convert -Wall -W -Wstrict-prototypes -g -O0 -mint8 -mrelax
linker :=avr-ld
obj-copy :=avr-objcopy
target := atmega328p
serial-port := /dev/ttyUSB0
hex-out := main.hex

build:
	$(compiler) -mmcu=$(target) $(flags) -c *.c *.S  
	$(linker) -Map mmap.map -n --gc-sections -T linker.ld -o main.elf *.o
	$(obj-copy) -j .text -j .data -O ihex main.elf $(hex-out)
	avr-objdump -D -j .text -j .data main.elf > dissasm.txt
	mv *.o *.elf *.hex ./out

clean:
	rm -rf *.o *.map *.txt ./out/*.o ./out/*.elf ./out/*.hex
	
burn:
	avrdude -p $(target) -c arduino -P $(serial-port) -U flash:w:./out/$(hex-out)
