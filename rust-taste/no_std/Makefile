path:= ./target/my-custom-avr-target/debug/no_std.elf

build:
	cargo +nightly-2021-01-07 rustc -Z build-std=core --target my-custom-avr-target.json
	avr-objdump -D $(path) > dissasm.txt
	avr-objdump -s $(path) > source.txt

nocrt:
	cargo +nightly-2021-01-07 rustc -Z build-std=core --target my-custom-avr-target-no-crt.json
	avr-objdump -D $(path) > dissasm-no-crt.txt
	avr-objdump -s $(path) > source-no-crt.txt

clean:
	cargo clean
	rm dissasm.txt source.txt dissasm-no-crt.txt source-no-crt.txt memory-map.map