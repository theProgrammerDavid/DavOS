#pragma once

const int black = 0x0;
const int blue = 0x1;
const int green = 0x2;
const int cyan = 0x3;
const int red = 0x4;
const int magenta = 0x5;
const int brown = 0x6;
const int light_grey = 0x7;
const int dark_grey = 0x8;
const int light_blue = 0x9;
const int light_green = 0x10;
const int light_cyan = 0x11;
const int light_red = 0x12;
const int light_magenta = 0x13;
const int light_brown = 0x14;
const int white = 0x15;

struct gdt
{
    unsigned int address;
    unsigned short size;
} __attribute__((packed));