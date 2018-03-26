#ifndef INCLUDE_FB_H
#define INCLUDE_FB_H

#include "uint.h"

/* The color codes */
#define FB_BLACK         0
#define FB_BLUE          1
#define FB_GREEN         2
#define FB_CYAN          3
#define FB_RED           4
#define FB_MAGENTA       5
#define FB_BROWN         6
#define FB_LIGHT_GREY    7
#define FB_DARK_GREY     8
#define FB_LIGHT_BLUE    9
#define FB_LIGHT_GREEN   10
#define FB_LIGHT_CYAN    11
#define FB_LIGHT_RED     12
#define FB_LIGHT_MAGENTA 13
#define FB_LIGHT_BROWN   14
#define FB_WHITE         15

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/* The screen width and height */
#define SCREEN_W 80
#define SCREEN_H 25

/* Write a character to framebuffer */
void fb_write_cell(char c, uint8_t fg, uint8_t bg);

/* Clear the frame buffer */
void fb_clear();

/*  Moves the cursor of the framebuffer to the given position */
void fb_move_cursor(uint16_t pos);

/* Scrolls screen upwards one line */
void fb_scroll(void);

/*  Writed given string to the framebuffer scrolling */
void fb_write(const char *data);

#endif  /* INCLUDE_FB_H */
