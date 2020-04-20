#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

// const int black         = 0x0;
// const int blue          = 0x1;
// const int green         = 0x2;
// const int cyan          = 0x3;
// const int red           = 0x4;
// const int magenta       = 0x5;
// const int brown         = 0x6;
// const int light_grey    = 0x7;
// const int dark_grey     = 0x8;
// const int light_blue    = 0x9;
// const int light_green   = 0x10;
// const int light_cyan    = 0x11;
// const int light_red     = 0x12;
// const int light_magenta = 0x13;
// const int light_brown   = 0x14;
// const int white         = 0x15;

/**
 * All the IO ports are calculated relative to the data port. This is
 * because all serial ports (COM1, COM2, COM3, COM4) have their ports
 * in the same order, but they start at different values
 */

#define SERIAL_COM1_BASE 0x3F8

#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base) (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base) (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base) (base + 5)

/* SERIAL_LINE_ENABLE_DLAB:
    Tells the serial port to expect first the highest 8 bits on the
    data port, then the lowest 8 bits next
*/
#define SERIAL_LINE_ENABLE_DLAB 0x80

/** serial_configure_baud_rate:
 *  Sets the speed of data being sent. The default speed of a serial
 *  port is 11520 bits/s. The argument is a divisor of that number and
 *  the resulting speed will be (11520 / divisor) bits/s
 * 
 *  @param COM PORT to configure
 *  @param the divisor
 */
void serial_configure_baud_rate(unsigned short com, unsigned short divisor);

/** serial_configure_law:
 * Conigures the line of the given serial port. The port is set to have
 * data length of 8 bits, no parity bits, one stop bit and break control
 * disabled
 * 
 * @param com The serial port to configure
 */

void serial_configure_line(unsigned short com);

/**
 * int sum_of_three: int,int,int
 * input: 3 ints
 * output: sum of the three
 */
int sum_of_three(int, int, int);

/**
 * fb_write_cell:
 * writes a character to position i of the frame-buffer
 * with the specified foreground and background
 * 
 * @param i The location in the Frame Buffer
 * @param c The character to write
 * @param fg Foreground Color
 * @param bg Background Color
 */
void fb_write_cell(unsigned int, char, unsigned char, unsigned char);

/**
 * write_string
 * writes the string to the current line of the frame-buffer
 * 
 * @param s String to write
 * @param n Length of the string that is passed
 */
void write(char s[], unsigned int n);

/**
 * outb: 
 * Sends the given data to the given I/O port
 * 
 * @param port Port to send the I/O data through
 * @param data Data to send through the I/O port
 */
void outb(unsigned short port, unsigned char data);

#define FB_GREEN 2
#define FB_DARK_GREY 8

#endif
