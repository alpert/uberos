#include "fb.h"
#include "gdt.h"

int kernel_main() {
    init_gdt();
    fb_clear();

    char message[] = "Wellcome to uberOS!\nThis is the first version!\n\nLOL";
    fb_write(message);
    return 0;
}
