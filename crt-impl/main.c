

/*
Register    Description
DDRx        Used to set the respective PORT as output/input
PORTx       Used to write the data to the Port pins
PINx        Used to Read the data from the port pins
*/

/*
Pin not hold data if DDR pin is not selected even PORT pin selected.
Note : Actually pin will have data with very low voltage level.
*/

// avr/sfr_defs.h

#include "io.h"
#include "delay.h"

// void init_stack(void);
// void copy_data(void);

void memset(int *, int, int);
int main(void);
void exit(void);

char CONST_CHAR_ARR[254] =
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
     10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
     20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
     30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
     40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
     50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
     60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
     70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
     80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
     90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
     100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
     110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
     120, 121, 122, 123, 124, 125, 126, 127, 128, 129,
     130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
     140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
     150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
     160, 161, 162, 163, 164, 165, 166, 167, 168, 169,
     170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
     180, 181, 182, 183, 184, 185, 186, 187, 188, 189,
     190, 191, 192, 193, 194, 195, 196, 197, 198, 199,
     200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
     210, 211, 212, 213, 214, 215, 216, 217, 218, 219,
     220, 221, 222, 223, 224, 225, 226, 227, 228, 229,
     230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
     240, 241, 242, 243, 244, 245, 246, 247, 248, 249,
     250, 251, 252, 253};

const char CONST_CHAR_MULTI_ARR[11][10] =
    {
        {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09},
        {0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13},
        {0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D},
        {0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27},
        {0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31},
        {0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B},
        {0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45},
        {0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F},
        {0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59},
        {0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63},
        {0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D}};

int main(void)
{

     int *addr1 = (int *)CONST_CHAR_MULTI_ARR;
     int *addr2 = (int *)CONST_CHAR_ARR;
/*
    for (int i = 0; i <= 254; i++)
    {
        __io_D_output__(CONST_CHAR_ARR[i]);
        for (int i = 0; i < 255; i++)
        {
            for (int i = 0; i < 255; i++)
            {
            }
        }
    }
    */
    return 0;
}

void exit()
{
    while (1)
    {
    }
}

void memset(int *ptr, int value, int size)
{
    int i = 0;
    for (; i <= size; ++i)
    {
        *ptr = value;
        ++ptr;
    }
}
