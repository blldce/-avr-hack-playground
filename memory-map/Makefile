compiler :=avr-gcc
obj-copy :=avr-objcopy
target := atmega328p
path := /dev/ttyUSB0
hex := main.hex

build:
	$(compiler) -g -Os -mmcu=$(target) -c *.c 
	$(compiler) -g -mmcu=$(target) -Wl,-Map,mmap.map -o main.elf *.o
	$(obj-copy) -j .text -j .data -O ihex main.elf $(hex)
	avr-objdump -d -j .text -j .data main.elf > dissasm.txt
	mv *.o *.elf *.hex ./out

burn:
	avrdude -p $(target) -c arduino -P $(path) -U flash:w:./out/$(hex)

	

clean:
	rm -rf dissasm.txt *.map *.o *.hex *.elf ./out/*.o ./out/*.elf ./out/*.hex
	
