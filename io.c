#include "io.h"

#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15

char *fb = (char *)0x000B8000;

void serial_configure_line(unsigned short com)
{
    /**
 * Bit:     | 7 | 6 | 5 4 3 | 2 | 1 0 |
 * Content: | d | b | parity| s | dl  |
 * Value :  | 0 | 0 | 0 0 0 | 0 | 1 1 |
 */
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}


void serial_configure_baud_rate(unsigned short com, unsigned short divisor)
{
    outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

void fb_move_cursor(unsigned short pos)
{

    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}

int sum_of_three(int arg1, int arg2, int arg3)
{
    return arg1 + arg2 + arg3;
}

void write(char s[], unsigned int n)
{
    fb_move_cursor(0x0050);
    unsigned int i = 0;
    for (i = 0; i < n; i++)
    {
        fb_write_cell(i * 2, s[i], FB_GREEN, FB_DARK_GREY);
        fb_move_cursor(i);
        //fb += 0x15;
    }
}

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}
