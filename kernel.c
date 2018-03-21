#include "io.h"

#define FB_GREEN 2
#define FB_DARK_GREY 8

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/** strlen
 * Calculates the lenght of a given string
 *
 * @param str  The string
 * return      The lenght of given string
 */
unsigned int strlen(const char* str)
{
    unsigned int len = 0;
    while (str[len]) {
        len++;
    }
    return len;
}

/** fb_write_cell:
 * Writes a character with the given foreground and background to position i
 * in the framebuffer.
 *
 * @param i  The location in the framebuffer
 * @param c  The character
 * @param fg The foreground color
 * @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    char *fb = (char *) 0x000B8000;
    fb[i * 2] = c;
    fb[i * 2 + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
}

/** fb_clear
 * Clears the frame buffer
 *
 */
void fb_clear()
{
    for (int i = 0; i < 80 * 20; i++) {
        fb_write_cell(i, 0,  FB_GREEN, FB_DARK_GREY);
    }
}

/** fb_move_cursor:
 *  Moves the cursor of the framebuffer to the given position
 *
 *  @param pos The new position of the cursor
 */
void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

void fb_write(const char* data)
{
    unsigned int len = strlen(data);
    for (unsigned int i = 0; i < len; i++) {
        fb_write_cell(i, data[i], FB_GREEN, FB_DARK_GREY);
    }
   fb_move_cursor(len);
}

int kernel_main() {
    fb_clear();

    char message[] = "Wellcome to uberOS!";
    fb_write(message);
    return 0;
}
