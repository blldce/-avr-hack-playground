#![feature(no_core, lang_items)]
#![no_std]
#![no_core]
#![no_main]

#[lang = "sized"]
pub trait Sized {}

#[lang = "copy"]
pub trait Copy {}

#[lang = "eh_personality"]
#[no_mangle]
pub fn rust_eh_personality() {}

#[lang = "panic_info"]
pub struct PanicInfo(i32);

#[lang = "panic_impl"]
#[no_mangle]
pub  fn rust_begin_panic(_a: &PanicInfo) -> ! {
    loop {}
}

#[lang = "panic"]
pub  fn panicc() -> ! {
    loop {}
}


#[lang = "panic_location"]
pub struct PanicLocation(i32);




#[lang = "add"]
pub trait CustomAddTrait<T = Self> {
    type Output;

    #[must_use]
    fn add(self, rhs: T) -> Self::Output;
}

impl Copy for i32 {}

impl CustomAddTrait for i32 {
    type Output = i32;

    fn add(self, other: Self) -> Self::Output {
        self + other
    }
}


impl Copy for i128 {}

impl CustomAddTrait for i128 {
    type Output = i128;

    fn add(self, other: Self) -> Self::Output {
        self + other
    }
}




#[no_mangle]
pub extern "C" fn my_start() -> ! {
  
    let a1: i128 = 3;
    let a2: i128 = 4;

    let sum: i128 = a1 + a2;

    unsafe
    {
        let addr:*mut i128 = (0x06ff) as *mut i128;  // SRAM 0x100 - 0x8fc
        *addr = sum;
    }

    
    let a1: i32 = 2;
    let a2: i32 = 2;

    let sum: i32 = a1 + a2;

    unsafe
    {
        let addr:*mut i32 = (0x07ff) as *mut i32;  // SRAM 0x100 - 0x8fc
        *addr = sum;
    }


    loop {}
}


