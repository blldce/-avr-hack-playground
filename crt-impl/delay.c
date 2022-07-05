#include "cpu.h"

void _delay_loop_2(int __count)
{
    __asm__ volatile(
        "1: sbiw %0,1"
        "\n\t"
        "brne 1b"
        : "=w"(__count)
        : "0"(__count));
}

void _delay_ms(int __ms)
{
    int __tmp;
    int __ticks;
    __tmp = ((F_CPU) / 255) * __ms;
    if (__tmp < 1)
        __ticks = 1;
    else if (__tmp > 255)
    {
        __ticks = (int)(__ms * 50);
        while (__ticks)
        {
            _delay_loop_2(((F_CPU) / 255) / 10);
            __ticks--;
        }
        return;
    }
    else
        __ticks = (int)__tmp;
    _delay_loop_2(__ticks);
}
