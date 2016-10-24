#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif

#include <stddef.h>
#include <stdint.h>
#include "headers/vga.h"

void main() {
    vga_init(VGA_LIGHT_GREEN, VGA_BLACK);
    print("Welcome to MarathonOS");
}