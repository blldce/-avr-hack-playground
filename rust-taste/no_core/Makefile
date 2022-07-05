compiler :=rustc 
linker :=avr-ld
target :=my-custom-avr-target.json 
link-args :=-C link-arg=-nostdlib -C link-arg=-nostartfiles -C link-arg=-ffreestanding -C panic=abort -C link-arg=-mno-red-zone 
obj-copy :=avr-objcopy
target-avr := atmega328p
path := /dev/ttyUSB0
hex := main.hex

build:
	$(compiler) +nightly $(link-args) *.rs --emit=obj --target $(target) 
	$(linker) -Map memory-map.map -n --gc-sections -T linker.ld -o main.elf *.o
	$(obj-copy) -j .text -j .data -O ihex main.elf $(hex)
	avr-objdump -D main.elf > dissasm.txt
	avr-objdump -s main.elf > source.txt
	mv *.o *.elf *.hex ./out

clean:
	rm -rf dissasm.txt memory-map.map source.txt ./out/*.o ./out/*.elf ./out/*.hex


burn:
	avrdude -p $(target-avr) -c arduino -P $(path) -U flash:w:./out/$(hex)
	
	
