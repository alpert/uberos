#include "io.h"
#include "fb.h"
#include "uberlib.h"
#include "ubertype.h"

/* Global variable to track cursor location */
unsigned short CURSOR_X = 0;
unsigned short CURSOR_Y = 0;

/* framebuffer address */
char *fb = (char *) 0x000B8000;

void fb_write_cell(char c, u8int fg, u8int bg)
{
	if (c == '\n') {
        /* Go to the next line if encounter a new line char */
        CURSOR_X = 0;
        CURSOR_Y++;
        return;
    }

    // write the character
    int pos = CURSOR_Y * SCREEN_W + CURSOR_X;
    fb[pos * 2 ] = c;
    fb[pos * 2 + 1] = ((bg & 0x0F) << 4) | (fg & 0x0F);
    CURSOR_X++;

    // move to new line if X exceeds line width
    if (CURSOR_X >= SCREEN_W) {
        CURSOR_X = 0;
        CURSOR_Y++;
    }
    
    // scroll if necessary
    fb_scroll();
    // move cursor
    pos = CURSOR_Y * SCREEN_W + CURSOR_X;
    fb_move_cursor(pos);
}

void fb_clear()
{
    u16int blank = 0 | (((FB_BLACK & 0x0F) << 4) | (FB_BLACK & 0x0F)) << 8;
    for (int i = 0; i < SCREEN_W * SCREEN_H; i++) {
        fb[i] = blank;
    }
    
    CURSOR_X = 0;
    CURSOR_Y = 0;
    fb_move_cursor(0);
}

void fb_move_cursor(unsigned short pos)
{
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

void fb_scroll()
{
    // Row 25 is the end, this means we need to scroll up
    if (CURSOR_Y >= 25) {
        // Move the current text chunk that makes up the screen
        // back in the buffer by a line
        for (int i = 0; i < SCREEN_W * SCREEN_H; i++) {
           fb[i] = fb[i + 80];
       }

       // The last line should now be blank. Do this by writing
       // 80 spaces to it.
       u16int blank = 0 | (((FB_BLACK & 0x0F) << 4) | (FB_BLACK & 0x0F)) << 8;
       for (int i = SCREEN_W * SCREEN_H; i < (SCREEN_H + 1) * SCREEN_W ; i++) {
            fb[i] = blank;
       }
       // The cursor should now be on the last line.
       CURSOR_Y = 24;
   }
}

void fb_write(const char* data)
{
    unsigned int len = strlen(data);
    for (unsigned int i = 0; i < len; i++) {
        fb_write_cell(data[i], FB_GREEN, FB_DARK_GREY);
    }
}
