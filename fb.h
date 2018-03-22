#define FB_GREEN 2
#define FB_DARK_GREY 8

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/** fb_write_cell:
 * Writes a character with the given foreground and background to position i
 * in the framebuffer.
 *
 * @param i  The location in the framebuffer
 * @param c  The character
 * @param fg The foreground color
 * @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
/** fb_clear
 * Clears the frame buffer
 *
 */
void fb_clear();

/** fb_move_cursor:
 *  Moves the cursor of the framebuffer to the given position
 *
 *  @param pos The new position of the cursor
 */
void fb_move_cursor(unsigned short pos);

void fb_write(const char* data);
