#include "io.h"

struct example
{
    unsigned char config;
    unsigned short address;
    unsigned char index;
} __attribute__((packed));

void kmain()
{
    // fb_write_cell(0, 'A', FB_GREEN, FB_DARK_GREY);
    // fb_write_cell(2, 'B', FB_GREEN, FB_DARK_GREY);
    // fb_write_cell(4, 'C', FB_GREEN, FB_DARK_GREY);
    // fb_write_cell(6, '\n', FB_GREEN, FB_DARK_GREY);
    clear_fb();
    char s[] = "Hello";
    write(s, sizeof(s));
}
