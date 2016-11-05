#include "headers/vga.h"

void info(const char* message) {
    print("\n");
    print("[ ");
    vga_set_color(vga_make_color(VGA_GREEN, VGA_BLACK));
    print("INFO");
    vga_set_color(vga_make_color(VGA_WHITE, VGA_BLACK));
    print(" ] ");
    print(message);
}

void warning(const char* message) {
    print("\n");
    print("[ ");
    vga_set_color(vga_make_color(VGA_GREEN, VGA_BLACK));
    print("WARNING");
    vga_set_color(vga_make_color(VGA_WHITE, VGA_BLACK));
    print(" ] ");
    print(message);
}

void error(const char* message) {
    print("\n");
    print("[ ");
    vga_set_color(vga_make_color(VGA_GREEN, VGA_BLACK));
    print("ERROR");
    vga_set_color(vga_make_color(VGA_WHITE, VGA_BLACK));
    print(" ] ");
    print(message);
}

void halt(const char* message) {
    print("\n");
    print("[ ");
    vga_set_color(vga_make_color(VGA_GREEN, VGA_BLACK));
    print("HALT");
    vga_set_color(vga_make_color(VGA_WHITE, VGA_BLACK));
    print(" ] ");
    print(message);
}
