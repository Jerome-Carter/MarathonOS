#ifndef VGA_H
#define VGA_H

#include <stddef.h>
#include <stdint.h>
#include "port.h"

#define CURSOR_CMD_PORT 0x3D4
#define CURSOR_DATA_PORT 0x3D5
#define CURSOR_HIGH 0x0F
#define CURSOR_LOW 0x0E

uint8_t cursor_row;
uint8_t cursor_column;
size_t vga_row;
size_t vga_column;
uint8_t vga_color;
uint16_t* vga_address;

enum vga_color {
    VGA_BLACK = 0,
    VGA_BLUE = 1,
    VGA_GREEN = 2,
    VGA_CYAN = 3,
    VGA_RED = 4,
    VGA_MAGENTA = 5,
    VGA_BROWN = 6,
    VGA_LIGHT_GREY = 7,
    VGA_DARK_GREY = 8,
    VGA_LIGHT_BLUE = 9,
    VGA_LIGHT_GREEN = 10,
    VGA_LIGHT_CYAN = 11,
    VGA_LIGHT_RED = 12,
    VGA_LIGHT_MAGENTA = 13,
    VGA_LIGHT_BROWN = 14,
    VGA_WHITE = 15,
};

uint8_t vga_make_color(enum vga_color foreground, enum vga_color background);
uint16_t vga_make_char(unsigned char character, uint8_t color);

void vga_set_cursor(size_t row, size_t column);
void vga_set_color(uint8_t color);

void vga_init(enum vga_color foreground, enum vga_color background);

void vga_clear_line(size_t from, size_t to);
void vga_clear();
void vga_scroll(uint16_t lines);
void vga_scroll_down();
void vga_newline();

void vga_put_index(char c, uint8_t color, size_t row, size_t column);
void vga_put_char(char c);
void print(const char* data);

#endif
