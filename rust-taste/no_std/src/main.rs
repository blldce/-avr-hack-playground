
#![no_std]
#![no_main]

use core::panic::PanicInfo;

#[no_mangle]
pub fn main() -> () {

    unsafe
    {
        let addr:*mut i32 = (0x1000) as *mut i32; 
        *addr= 31;
    }

}

#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}

