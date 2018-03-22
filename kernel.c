#include "fb.h"

int kernel_main() {
    fb_clear();

    char message[] = "Wellcome to uberOS!\nThis is the first version!\n\nLOL";
    fb_write(message);
    return 0;
}
